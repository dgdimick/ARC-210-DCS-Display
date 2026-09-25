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

The standard processor clock speeds are:

| Board | CPU clock speed |
| --- | ---: |
| [Teensy 4.1](https://www.pjrc.com/store/teensy41.html) | **600 MHz** |
| [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3/) | **16 MHz** |
| [Arduino Mega 2560 Rev3](https://docs.arduino.cc/hardware/mega-2560/) | **16 MHz** |

The Teensy 4.1 has **37.5 times the CPU clock frequency** of these classic Arduino boards. That is a clock-speed comparison, not a measured 37.5-times improvement in screen refresh rate; processor architecture, memory, SPI speed, and the display code also affect the result.

Display response speed was another major factor in my choice. Compared with classic Arduino Uno and Mega boards, the Teensy 4.1 provides much more processing headroom for drawing the TFT while handling radio updates and controls. I would not expect those older boards to deliver the same screen response with this display and firmware. Actual refresh speed also depends on the SPI connection, display library, and drawing code; this comparison is not a claim about every Arduino model.

### Cost: one Teensy versus three Arduinos

For a board-only comparison, these US-dollar prices were checked on September 24, 2026:

| Option | Price per board | Quantity | Total |
| --- | ---: | ---: | ---: |
| [Teensy 4.1 without Ethernet — SparkFun](https://www.sparkfun.com/teensy-4-1-without-ethernet.html) | $29.60 | 1 | **$29.60** |
| [Official Arduino Uno R3 — Arduino US store](https://store-usa.arduino.cc/products/arduino-uno-rev3) | $27.60 | 3 | **$82.80** |

At those listed prices, one Teensy costs **$53.20 less** than three official Uno R3 boards, before tax, shipping, cables, headers, or other accessories. Lower-cost Arduino-compatible boards can change the comparison substantially. This is an illustrative cost comparison, not a claim that three Unos would run the current display firmware or provide equivalent screen performance. Prices may change.

### Reading the diagram

The red numbers beside the symbol are KiCad pad numbers, **not necessarily the Teensy GPIO numbers used in the code**. The signal names identify the corresponding functions. Power and ground connections are also shown; they are not extra GPIO pins.

This image is a schematic excerpt, not a complete wiring guide. Use the [ARC-210 Teensy 4.1 pin layout](ARC-210%20Teensy%204.1%20Pin%20layout.txt) for the documented actual GPIO assignments, and check them against the firmware and PCB revision you are building.
