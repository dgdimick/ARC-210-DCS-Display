# ARC-210 Documentation

## Why I used a Teensy

[Why I used a Teensy.png](Why%20I%20used%20a%20Teensy.png) is a screenshot of the Teensy 4.1 symbol and its connections in the ARC-210 panel's KiCad schematic. The green lines are electrical connections to the rest of the circuit. It shows how many connections are needed to bring the display, controls, and lighting together on one controller.

![Teensy 4.1 connections in the ARC-210 schematic](Why%20I%20used%20a%20Teensy.png)

### Why the GPIO count matters

GPIO means general-purpose input/output. These are the pins the controller uses to read controls and send signals to other hardware. This panel needs pins for several jobs:

- Rotary encoders each use two input signals to detect movement and direction.
- The 16 buttons use a 4 × 4 matrix, requiring eight pins for the rows and columns instead of a separate pin for every button.
- The SPI TFT needs clock and data signals, plus chip-select, data/command, and reset connections.
- The display backlight and panel lighting have separate control signals.
- Other switches need inputs, and the current pin layout reserves two pins for I²C.

Even with a button matrix, the connections add up quickly. The Teensy 4.1 provides enough pins for this design without adding GPIO expanders or a second controller. That keeps the wiring and firmware easier to manage.

### Could I have used several Arduinos?

Yes. I could have split the buttons and switches onto one Arduino, the rotary encoders onto another, and the TFT onto a controller with enough processing speed and memory for the display. Depending on the DCS-BIOS connection setup, the boards could use separate USB connections or communicate through a main controller.

That would provide more GPIO, but it would also mean more wiring, connections, and separate firmware to maintain. Splitting the controls across boards would not increase the memory or processing speed of the board driving the TFT. An Uno or Mega would still have its own display limitations.

I chose the Teensy 4.1 because it combines the GPIO, processing speed, and memory needed for this design on one board. Several Arduinos were an option; one Teensy keeps this build simpler.

### Reading the diagram

The red numbers beside the symbol are KiCad pad numbers, **not necessarily the Teensy GPIO numbers used in the code**. The signal names identify the corresponding functions. Power and ground connections are also shown; they are not extra GPIO pins.

This image is a schematic excerpt, not a complete wiring guide. Use the [ARC-210 Teensy 4.1 pin layout](ARC-210%20Teensy%204.1%20Pin%20layout.txt) for the documented actual GPIO assignments, and check them against the firmware and PCB revision you are building.
