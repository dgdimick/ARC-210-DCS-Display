#Requires -RunAsAdministrator
[CmdletBinding(SupportsShouldProcess)]
param(
    [Parameter(Mandatory)]
    [ValidatePattern('^COM[1-9][0-9]*$')]
    [string]$Port,
    [switch]$Undo
)

$ErrorActionPreference = 'Stop'
$Port = $Port.ToUpperInvariant()
$devices = @(Get-PnpDevice -PresentOnly -Class Ports | Where-Object {
    if ($_.InstanceId -notmatch '^USB\\VID_16C0&') { return $false }
    $parameters = 'HKLM:\SYSTEM\CurrentControlSet\Enum\' + $_.InstanceId + '\Device Parameters'
    (Get-ItemProperty -LiteralPath $parameters -Name PortName -ErrorAction SilentlyContinue).PortName -eq $Port
})
if ($devices.Count -ne 1) { throw "Expected one connected Teensy serial device on $Port. Check Device Manager." }

$path = 'HKLM:\SYSTEM\CurrentControlSet\Enum\' + $devices[0].InstanceId
$key = Get-Item -LiteralPath $path
$backupName = 'ARC210_OriginalFriendlyName'
$hasBackup = $key.GetValueNames() -contains $backupName
$hasName = $key.GetValueNames() -contains 'FriendlyName'
$current = $key.GetValue('FriendlyName')
$label = "ARC-210 ($Port)"

if ($Undo) {
    if (!$hasBackup) { Write-Output 'There is no saved rename for this device.'; return }
    $backup = $key.GetValue($backupName) | ConvertFrom-Json
    if ($current -cne $backup.AppliedName) {
        throw 'The display name changed since the utility ran. The saved backup was kept.'
    }
    if ($PSCmdlet.ShouldProcess($Port, 'Restore the saved Windows display name')) {
        if ($backup.HadName) {
            Set-ItemProperty -LiteralPath $path -Name FriendlyName -Value $backup.OriginalName
        } else {
            Remove-ItemProperty -LiteralPath $path -Name FriendlyName
        }
        Remove-ItemProperty -LiteralPath $path -Name $backupName
        Write-Output 'Original display name restored. Reopen Device Manager to refresh the list.'
    }
    return
}

if ($current -ceq $label) { Write-Output "$Port already has that display name."; return }
if ($hasBackup) { throw 'This device already has a saved rename. Restore it before applying a new name.' }
if ($hasName -and $key.GetValueKind('FriendlyName') -ne 'String') {
    throw 'The current display name uses an unexpected registry type.'
}
if ($PSCmdlet.ShouldProcess($Port, "Set the Windows display name to $label")) {
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
