#Requires -RunAsAdministrator
[CmdletBinding(SupportsShouldProcess)]
param(
    [ValidatePattern('^COM[1-9][0-9]*$')]
    [string]$Port,
    [Alias('DisplayName')]
    [ValidateScript({ -not [string]::IsNullOrWhiteSpace($_) -and $_ -notmatch '[\x00-\x1F\x7F]' })]
    [string]$Name = 'ARC-210',
    [switch]$Undo
)

$ErrorActionPreference = 'Stop'
if (!$PSBoundParameters.ContainsKey('Port')) {
    $Port = (Read-Host 'Enter the COM port (for example, COM5)').Trim()
    if ($Port -notmatch '^COM[1-9][0-9]*$') {
        throw 'Enter a COM port such as COM5.'
    }

    if (!$Undo -and !$PSBoundParameters.ContainsKey('Name')) {
        $enteredName = Read-Host 'Enter the display name (press Enter for ARC-210)'
        if ($enteredName -match '[\x00-\x1F\x7F]') {
            throw 'The display name cannot contain control characters.'
        }
        if (![string]::IsNullOrWhiteSpace($enteredName)) {
            $Name = $enteredName.Trim()
        }
    }
}
$Port = $Port.ToUpperInvariant()
$devices = @(Get-PnpDevice -PresentOnly -Class Ports | Where-Object {
    $parameters = 'HKLM:\SYSTEM\CurrentControlSet\Enum\' + $_.InstanceId + '\Device Parameters'
    (Get-ItemProperty -LiteralPath $parameters -Name PortName -ErrorAction SilentlyContinue).PortName -eq $Port
})
if ($devices.Count -ne 1) { throw "Expected one present serial device on $Port. Check Device Manager under Ports (COM & LPT)." }

$target = "$Port ($($devices[0].InstanceId))"
$path = 'HKLM:\SYSTEM\CurrentControlSet\Enum\' + $devices[0].InstanceId
$key = Get-Item -LiteralPath $path
$backupName = 'ARC210_OriginalFriendlyName'
$hasBackup = $key.GetValueNames() -contains $backupName
$hasName = $key.GetValueNames() -contains 'FriendlyName'
$current = $key.GetValue('FriendlyName')
$label = "$($Name.Trim()) ($Port)"

$defaultName = 'Serial Port'
$isTeensy = $devices[0].InstanceId -match '^USB\\VID_16C0&'
if ($isTeensy) {
    $defaultName = 'USB Serial Device'
}

if ($hasBackup) {
    $backup = $key.GetValue($backupName) | ConvertFrom-Json
    $savedLabel = $backup.AppliedName -creplace ' \(COM[1-9][0-9]*\)$', " ($Port)"
    $originalLabel = "$defaultName ($Port)"
    if ($backup.HadName) {
        $originalLabel = $backup.OriginalName -creplace ' \(COM[1-9][0-9]*\)$', " ($Port)"
    }
}

if ($Undo) {
    if (!$hasBackup) { Write-Output 'There is no saved rename for this device.'; return }
    if ($current -cne $backup.AppliedName -and $current -cne $savedLabel) {
        throw 'The display name changed since the utility ran. The saved backup was kept.'
    }
    if ($PSCmdlet.ShouldProcess($target, 'Restore the saved Windows display name')) {
        New-ItemProperty -LiteralPath $path -Name FriendlyName -PropertyType String -Value $originalLabel -Force | Out-Null
        Remove-ItemProperty -LiteralPath $path -Name $backupName
        Write-Output 'Windows display name restored. Reopen Device Manager to refresh the list.'
    }
    return
}

if ($current -ceq $label) { Write-Output "$Port already has that display name."; return }
if ($hasName -and $key.GetValueKind('FriendlyName') -ne 'String') {
    throw 'The current display name uses an unexpected registry type.'
}
if ($PSCmdlet.ShouldProcess($target, "Set the Windows display name to $label")) {
    if ($hasBackup) {
        # A port reassignment can reset FriendlyName while leaving the backup intact.
        $wasReset = !$hasName -or $current -ceq $originalLabel -or
            ($isTeensy -and $current -ceq "$defaultName ($Port)")
        if ($label -cne $savedLabel -or !$wasReset) {
            throw 'This device already has a saved rename. Restore it before applying a new name.'
        }
        New-ItemProperty -LiteralPath $path -Name FriendlyName -PropertyType String -Value $label -Force | Out-Null
        Write-Output "Reapplied the display name $label. Reopen Device Manager to refresh the list."
        return
    }

    $backup = @{ HadName = $hasName; OriginalName = $current; AppliedName = $label } | ConvertTo-Json -Compress
    New-ItemProperty -LiteralPath $path -Name $backupName -PropertyType String -Value $backup | Out-Null
    try {
        New-ItemProperty -LiteralPath $path -Name FriendlyName -PropertyType String -Value $label -Force | Out-Null
    } catch {
        Remove-ItemProperty -LiteralPath $path -Name $backupName
        throw
    }
    Write-Output "Set the display name to $label. Reopen Device Manager to refresh the list."
}
