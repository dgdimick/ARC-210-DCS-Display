# ARC-210 Teensy Firmware and Boot Loader Files

This directory contains the precompiled Teensy 4.1 firmware files for the ARC-210 DCS Display project. These files can be installed without compiling the Arduino source code.

The firmware files use the `.hex` extension.

## TyTools

You can find the complete TyTools instructions on the [official TyTools website](https://koromix.dev/tytools).

TyTools is a collection of independent programs for uploading firmware to, monitoring, and managing Teensy boards. Only one executable is needed for the function you want to use.

| Tool | Type | Description |
| --- | --- | --- |
| **TyCommander** | Qt graphical application | Upload, monitor, and communicate with multiple Teensy boards |
| **TyUploader** | Qt graphical application | Simple firmware and sketch uploader |
| **tycmd** | Command line | Command-line tool for managing Teensy boards |

Download the [latest TyTools release from GitHub](https://github.com/Koromix/tytools/releases). Development builds are available from [koromix.dev](https://koromix.dev/files/tytools/).

## Uploading with TyCommander or TyUploader

1. Download and install TyTools.
2. Connect the Teensy 4.1 to the computer with a USB cable.
3. Open **TyCommander** or **TyUploader**.
4. Select the Teensy 4.1.
5. Select the appropriate ARC-210 `.hex` file from this directory.
6. Start the upload.
7. If requested, press the physical programming button on the Teensy.

## Using `tycmd`

### List connected Teensy boards

```text
tycmd list
```

Use `--verbose` for additional device information:

```text
tycmd list --verbose
```

For structured output that can be processed by a script:

```text
tycmd list --output json
```

### Upload firmware

From this directory, upload a HEX file with:

```text
tycmd upload "<firmware-file>.hex"
```

If you run the command from the repository root, use:

```text
tycmd upload "Firmware/Boot Loader/<firmware-file>.hex"
```

Replace `<firmware-file>.hex` with the actual firmware filename.

By default, `tycmd` attempts to reboot the Teensy into its bootloader. Use `--wait` if you want it to wait for the bootloader to appear or for you to press the Teensy's programming button:

```text
tycmd upload --wait "Firmware/Boot Loader/<firmware-file>.hex"
```

## Selecting a Specific Teensy

When multiple Teensy boards are connected, select one with:

```text
tycmd <command> --board "[<serial>][-<family>][@<location>]"
```

The serial number, board family, and USB or operating-system location are optional filters. Run `tycmd list` to see the identifiers available on your computer.

| Board filter | Effect |
| --- | --- |
| `714230` | Select the board with serial number 714230 |
| `-Teensy` | Select a board in the Teensy family |
| `@usb-1-2-2` | Select the board connected at USB location `usb-1-2-2` |
| `@COM1` | Select the board associated with COM1 |
| `714230@usb-1-2-2` | Match both the serial number and USB location |

Examples:

```text
tycmd upload --board "714230" "Firmware/Boot Loader/<firmware-file>.hex"
tycmd upload --board "@COM5" "Firmware/Boot Loader/<firmware-file>.hex"
tycmd upload --board "@usb-1-2-2" "Firmware/Boot Loader/<firmware-file>.hex"
```

Using the USB-location form is useful in a simulator containing several Teensy boards because a device can remain associated with the same physical USB port.

## Serial Monitor

Open a serial connection with:

```text
tycmd monitor
```

Use `--reconnect` to reconnect automatically after a reset or brief USB disconnection:

```text
tycmd monitor --reconnect
```

Use `--raw` to send terminal input immediately without line buffering:

```text
tycmd monitor --raw
```

Teensy is a native USB device, so normal serial baud-rate settings are generally ignored by TyTools.

## Reset and Bootloader Commands

Restart the Teensy:

```text
tycmd reset
```

Start the Teensy bootloader, equivalent to pressing its physical programming button:

```text
tycmd reset -b
```

Display general or command-specific help:

```text
tycmd help
tycmd help upload
tycmd help monitor
```

## Additional Information

TyTools identifies boards by their USB topology, allowing multiple Teensy devices to be managed independently. A board that remains connected to the same USB port can continue to be recognized at the same USB location even when it changes between normal operation and bootloader mode.

TyTools is released into the public domain. Refer to the [TyTools repository](https://github.com/Koromix/tytools) and its license information for details.
