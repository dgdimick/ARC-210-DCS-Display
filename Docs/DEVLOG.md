# ARC-210 Development Log

## 2026-09-17

### Teensy 4.1 TFT and DCS-BIOS Milestone

Successfully got the ARC-210 TFT display working with the Teensy 4.1.

Confirmed working display:
- 3.5-inch 480x320 SPI TFT
- ILI9488 controller
- Teensyduino-supplied `ILI9488_t3` library

Confirmed working TFT pinout:
- CS -> GPIO 10
- DC / RS -> GPIO 9
- RESET -> GPIO 8
- MOSI / SDI -> GPIO 11
- SCK -> GPIO 13
- MISO / SDO -> GPIO 12
- BLK / Backlight -> GPIO 6

Also confirmed the Teensy 4.1 is communicating with DCS through DCS-BIOS using:

```cpp
#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"
```

The ARC-210 frequency was successfully received from DCS-BIOS and displayed on the TFT.

Tested live frequency received from DCS:
- 133.000 MHz

Working ARC-210 frequency buffer:

```cpp
void onArc210FrequencyChange(char* newValue) {
    // Update TFT with the new ARC-210 frequency
}

DcsBios::StringBuffer<7> arc210FrequencyBuffer(
    0x1382,
    onArc210FrequencyChange
);
```

### Status

At this point, the following has been verified:
- Teensy 4.1 is working
- TFT display is working
- TFT pinout is confirmed
- USB serial connection is working
- DCS-BIOS connection is working
- Live ARC-210 frequency data is being displayed on the TFT

### Next Steps

- Add previous frequency display
- Add preset/channel display
- Add modulation display
- Add RT number
- Add COMSEC fields
- Update only changed regions of the TFT instead of redrawing the entire screen
