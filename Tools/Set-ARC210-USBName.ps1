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

$backupPaths = @($path)
if ($Undo) {
    $instanceId = $devices[0].InstanceId
    $hardware = $instanceId.Substring(0, $instanceId.LastIndexOf('\'))
    $container = (Get-PnpDeviceProperty -InstanceId $instanceId -KeyName DEVPKEY_Device_ContainerId -ErrorAction SilentlyContinue).Data
    if ($container -and $container -ne [guid]::Empty -and $container -ne [guid]'00000000-0000-0000-ffff-ffffffffffff') {
        $oldPaths = @(Get-PnpDevice -Class Ports | Where-Object {
            $_.Present -eq $false -and $_.InstanceId.StartsWith($hardware + '\', [StringComparison]::OrdinalIgnoreCase)
        } | ForEach-Object {
            $oldPath = 'HKLM:\SYSTEM\CurrentControlSet\Enum\' + $_.InstanceId
            $oldKey = Get-Item -LiteralPath $oldPath -ErrorAction SilentlyContinue
            if ($oldKey -and $oldKey.GetValueNames() -contains $backupName) {
                $oldContainer = (Get-PnpDeviceProperty -InstanceId $_.InstanceId -KeyName DEVPKEY_Device_ContainerId -ErrorAction SilentlyContinue).Data
                if ($oldContainer -eq $container) { $oldPath }
            }
        })
        if ($oldPaths.Count -gt 1) {
            throw 'More than one old device record has a matching backup. No changes were made.'
        }
        if ($oldPaths.Count -eq 1) {
            $backupPaths = @($path, $oldPaths[0])
        }
    }
}

if ($hasBackup) {
    $backup = $key.GetValue($backupName) | ConvertFrom-Json
    $savedLabel = $backup.AppliedName -creplace ' \(COM[1-9][0-9]*\)$', " ($Port)"
    $originalLabel = "$defaultName ($Port)"
    if ($backup.HadName) {
        $originalLabel = $backup.OriginalName -creplace ' \(COM[1-9][0-9]*\)$', " ($Port)"
    }
}

if ($Undo -and $backupPaths.Count -eq 2) {
    $oldBackup = (Get-Item -LiteralPath $backupPaths[1]).GetValue($backupName) | ConvertFrom-Json
    $originalLabel = "$defaultName ($Port)"
    if ($oldBackup.HadName) {
        $originalLabel = $oldBackup.OriginalName -creplace ' \(COM[1-9][0-9]*\)$', " ($Port)"
    }
    if (!$hasBackup) {
        $backup = $oldBackup
        $savedLabel = $backup.AppliedName -creplace ' \(COM[1-9][0-9]*\)$', " ($Port)"
    }
}

if ($Undo) {
    if (!$hasBackup -and $backupPaths.Count -eq 1) { Write-Output 'There is no saved rename for this device.'; return }
    if ($hasName -and $current -cne $backup.AppliedName -and $current -cne $savedLabel -and $current -cne $originalLabel) {
        throw 'The display name changed since the utility ran. The saved backup was kept.'
    }
    if ($PSCmdlet.ShouldProcess($target, 'Restore the saved Windows display name')) {
        New-ItemProperty -LiteralPath $path -Name FriendlyName -PropertyType String -Value $originalLabel -Force | Out-Null
        foreach ($backupPath in $backupPaths) {
            if ((Get-Item -LiteralPath $backupPath).GetValueNames() -contains $backupName) {
                Remove-ItemProperty -LiteralPath $backupPath -Name $backupName
            }
        }
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
