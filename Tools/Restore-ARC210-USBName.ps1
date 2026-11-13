#Requires -RunAsAdministrator
[CmdletBinding(SupportsShouldProcess)]
param(
    [Parameter(Mandatory)]
    [ValidatePattern('^COM[1-9][0-9]*$')]
    [string]$Port
)

& (Join-Path $PSScriptRoot 'Set-ARC210-USBName.ps1') -Port $Port -Undo -WhatIf:$WhatIfPreference
