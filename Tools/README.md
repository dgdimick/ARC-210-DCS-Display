# ARC-210 Windows USB display name utility

**Last updated: November 13, 2026**

These optional scripts set the display name for a serial device listed under **Ports (COM & LPT)** in Windows Device Manager. The default label is **ARC-210 (COMx)**. Use **-Name** or the interactive prompt to choose your own label for a Teensy, USB-to-serial adapter, or another serial device listed there. Windows keeps the assigned COM number.

## How to rename or restore the port

1. Download [Set-ARC210-USBName.ps1](Set-ARC210-USBName.ps1) and [Restore-ARC210-USBName.ps1](Restore-ARC210-USBName.ps1) into the same folder.
2. Connect the device and find its COM number under **Device Manager → Ports (COM & LPT)**. Confirm the number belongs to the device you want to rename.
3. Open **Windows PowerShell** using **Run as administrator** and go to the folder where you saved the scripts. Substitute your port for COM5. For example, if your Teensy is on COM5, run the command below.

```powershell
.\Set-ARC210-USBName.ps1 -Port COM5
```

To use a different port and label, pass your COM number and put the name in quotes. In this example, Windows shows **Dummy Test (COM3)**.

```powershell
.\Set-ARC210-USBName.ps1 -Port COM3 -Name "Dummy Test"
```

![Windows Device Manager showing Dummy Test (COM3) under Ports (COM & LPT)](Device-Manager-Dummy-Test-COM3.png)

The script adds the COM number for you. If you already used the script to rename this device, restore its original name before applying another label.

To undo the rename, enter the device's current COM number from the same administrator PowerShell window. For the COM3 example, use the command below.

```powershell
.\Restore-ARC210-USBName.ps1 -Port COM3
```

The set script saves the original registry value on the selected device instance. The restore script uses that backup to put the old label back, or uses **Serial Port (COMx)** when there was no original label (**USB Serial Device (COMx)** for a Teensy). A label already set manually before using the utility has no backup from this utility. Both scripts accept `-WhatIf` to preview the operation. Reopen Device Manager to refresh the displayed name.

Run **.\Set-ARC210-USBName.ps1** with no arguments to enter the COM port and display name at the prompts. Press Enter at the name prompt to use **ARC-210**. Run **.\Restore-ARC210-USBName.ps1** with no arguments to enter just the COM port and restore its saved label. If Device Manager shows only **USB Serial Device**, check which port appears in TekConnect or DCSBridge when you plug in the Teensy.

I tested both scripts on COM5. Windows showed **ARC-210 (COM5)** after renaming and **USB Serial Device (COM5)** after restoring. I also tested the custom name on a Bluetooth serial port with the Teensy unplugged. Windows showed **Dummy Test (COM3)** and then restored **Standard Serial over Bluetooth link (COM3)**. I still need to test Teensy Loader and live DCS-BIOS on the flight sim PC.
