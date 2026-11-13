# ARC-210 Windows USB display name utility

**Last updated: November 13, 2026 at 1:48 AM MST (America/Denver)**

These optional scripts change the label shown for your Teensy serial port in Windows Device Manager to **ARC-210 (COMx)**. The label is local to this Windows device instance. The utility leaves the COM number, Teensy firmware, and USB product name as they are. It works with a connected Teensy serial device even if its firmware uses the default USB product name.

1. Download [Set-ARC210-USBName.ps1](Set-ARC210-USBName.ps1) and [Restore-ARC210-USBName.ps1](Restore-ARC210-USBName.ps1) into the same folder.
2. Plug in your ARC-210 and find its port under **Device Manager → Ports (COM & LPT)**. The utility checks for a Teensy USB vendor ID. If you have more than one Teensy, confirm which port belongs to your ARC-210.
3. Open **Windows PowerShell** using **Run as administrator** and go to the folder where you saved the scripts. Substitute your port for COM5.

```powershell
.\Set-ARC210-USBName.ps1 -Port COM5
```

To undo the rename, run this from the same elevated PowerShell window with the Teensy connected.

```powershell
.\Restore-ARC210-USBName.ps1 -Port COM5
```

The set script saves the original registry value on the selected device instance. The restore script uses that backup to put the old label back, or sets the label to **USB Serial Device (COMx)** if there was no original label. A label already set manually before using the utility has no backup from this utility. Both scripts accept `-WhatIf` to preview the operation. Reopen Device Manager to refresh the displayed name.
