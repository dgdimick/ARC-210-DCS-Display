# Firmware

This folder contains the firmware used for the ARC-210 controller project.

## Test Code

The `Test Code` folder contains small test programs intended to help builders verify individual parts of their controller during assembly and troubleshooting.

These test programs can be used to check things such as:

- Teensy 4.1 operation
- TFT display operation
- TFT pin assignments
- USB serial communication
- DCS-BIOS communication
- Switches and rotary encoders
- LEDs and backlighting
- Other controller inputs and outputs

The test code is not necessarily the final ARC-210 firmware. It is provided as a troubleshooting and bring-up aid so that each part of the controller can be tested individually before the complete firmware is loaded.

When building the controller, it is recommended to test each major section as it is completed. This can make it much easier to find wiring, pin-assignment, or hardware problems before the entire controller is assembled.
