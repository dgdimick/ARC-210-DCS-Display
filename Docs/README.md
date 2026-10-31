# ARC-210 Documentation

**Last updated: October 31, 2026 at 12:20 AM MDT (America/Denver)**

These notes explain the choices behind my ARC-210 build and help you find your way around the wiring and hardware. If something is unclear, feel free to ask in Discussions.

## Build guide

The [step-by-step build guide](Build%20Guide/README.md) covers parts, printing, PCB assembly, wiring, and testing. It marks unfinished steps and manufactured-board validation as **pending**.

## Why I used a Teensy

[Why I used a Teensy.png](Why%20I%20used%20a%20Teensy.png) is a screenshot of the Teensy 4.1 symbol and its connections in the ARC-210 panel's KiCad schematic. The green lines are electrical connections to the rest of the circuit. It shows the display and control connections on one controller. This is a historical schematic image: its panel-lighting and protected-power circuitry are not part of the current build. Use the current Main Board schematic for wiring.

![Teensy 4.1 connections in the ARC-210 schematic](Why%20I%20used%20a%20Teensy.png)

### Why the GPIO count matters

GPIO means general-purpose input/output. These are the pins the controller uses to read controls and send signals to other hardware. This panel needs pins for several jobs:

- Rotary encoders each use two input signals to detect movement and direction.
- The 16 buttons use a 4 × 4 matrix, requiring eight pins for the rows and columns instead of a separate pin for every button.
- The SPI TFT needs clock and data signals, plus chip-select, data/command, and reset connections.
- The display backlight has its own control signal. The older panel-lighting signal shown in the image belongs to a previous design; future button lighting would require a separate power/driver design and redesigned boards.
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

### The same Arduino programming workflow

The Teensy is programmed using the same **Arduino IDE** and **`.ino` sketches** used for Arduino boards. The familiar editor, C++ sketch structure, and `setup()` / `loop()` workflow remain the same, so there is no need to learn a different programming environment for this project.

Install [Teensy board support](https://www.pjrc.com/teensy/td_download.html) and select Teensy 4.1 in the IDE. [Teensy Loader](https://www.pjrc.com/teensy/loader.html) handles uploading the compiled firmware and is integrated with the Arduino upload workflow. To use the precompiled `ARC210_A-10C2_v0.1.1_Preview.hex` supplied here, simply open it in Teensy Loader and program the board; you do not need to compile the sketch yourself.

The programming workflow is familiar, although pin assignments and hardware-specific libraries still need to match the Teensy rather than an Uno or Mega.

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

## Teensy GPIO labels and KiCad pin numbers

**Use the numbers printed on the Teensy (or the matching GPIO labels on your breakout adapter) when following the firmware and wiring instructions.** KiCad uses a separate set of pin/pad numbers for the Teensy symbol and its matching `teensy:Teensy41` footprint. These include power and ground connections, so they are not the same as GPIO numbers.

| Teensy printed label / firmware GPIO | KiCad U1 pin / footprint pad |
| --- | ---: |
| GND (one of several ground connections) | 1 |
| 0 | 2 |
| 4 — TFT backlight | 6 |
| 14 / A0 — rotary-switch input | 36 |
| 15 / A1 — rotary-switch input | 37 |

For example, connect a rotary-switch signal to the Teensy connection marked **14/A0**, which is **KiCad pad 36**—not pad 14. In KiCad, read the symbol’s pin name and net label to identify the signal. Updating the PCB from the schematic with the matching symbol and footprint maps the connections to the correct physical locations. This pad mapping applies to the Teensy library supplied with this project; other libraries may use different numbering.

## Power and future button lighting

The painted buttons supplied with the PC Flights panel used for this build are opaque: light will not pass through them, so LEDs behind them would not illuminate their legends. Future backlighting would also require suitable light-transmitting replacement buttons.

The Teensy is powered by USB, and TFT VCC connects directly to the Teensy's 3.3 V supply. The external protected 5 V input, Main Board JP1 power selector, and C5/C6 TFT supply capacitors have been removed. C1/C2 and R1/R2 remain as rotary-input filters. The TFT backlight uses GPIO 4. Use a USB Micro-B data cable for power, programming, and USB communications.

Future button lighting would require suitable light-transmitting buttons, a separate power and driver design, a revised Main Board, and a new Button LED PCB. I’m leaving this for later and prioritizing the other radio projects. Button-lighting LEDs are not part of the current build or parts estimate.

## Optional SQL On/Off PCB

The SQL On/Off PCB is optional: the panel uses five required PCBs, or six with this optional board. For direct wiring, use TP1 (SQL signal, GPIO 41 / U1 pad 33) and TP2 (GND), both included and routed in the current Main Board v1.1. SQL1 remains an alternative two-pin header. The [shaft spacer v.5](../Supporting%20STL%27s/Shaft_Spacer_v.5.stl) is required in all installations to support the longer SQL On/Off switch shaft, whether or not the optional PCB is fitted. See the [direct-wiring notes](../parts/README.md#six-pcb-layout). I’ve checked the physical fit of Main Board v1.1; I still need to test the assembled board.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.

## Current PCB versions and a friendly starting point

Use Main Board **v1.1**, Button Matrix **v3.2**, Rotary Encoder **v1.4**, and Rotary Switch **v2.0**. The [PCB downloads](../PCBs/README.md#gerber-and-drill-downloads) link to their current manufacturing files. Start with the [build guide](Build%20Guide/README.md), take it one step at a time, and ask in [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) whenever you need a hand. Progress photos and questions are welcome!

## Printed parts

**I have printed the complete 17-part layout at 100% scale, and all parts passed test fitting. I consider the current STL designs final.** The set includes nine knobs, one display bracket, six encoder spacers, and one SQL shaft spacer. **Channel v4.2 and SQL v1.2 are the same outside size, with the same small side hole; only their shaft holes differ.** Channel has the smaller shaft hole. Print one of each at 100%. Use the [master print files and quantities](../Supporting%20STL%27s/README.md#complete-17-part-print-set) and keep checking [Project Updates](Project-Updates.md) for changes.
