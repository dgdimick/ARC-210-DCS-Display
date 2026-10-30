[Back to the main project README](../README.md)

# My SIMPIT and test computer

**This page describes my own development and flight-simulation setup. It is not a list of minimum requirements for the ARC-210, ARC-164, or ARC-186 panels.** Builders do not need a comparable gaming PC, these monitors, or these particular USB hubs to build the radio hardware. DCS system requirements depend on the simulator, aircraft, mission, and display configuration.

The equipment below provides context for development and testing. Listing it here does not mean every planned panel or the completed cockpit has already been tested.

## Computer configuration

| Component | My configuration |
| --- | --- |
| Computer | Empowered PC |
| CPU | AMD Ryzen 7 9800X3D |
| Motherboard | ASUS ROG STRIX X870E-E GAMING WIFI |
| GPU | NVIDIA GeForce RTX 5060 Ti, 16 GB |
| Current installed RAM | **Kingston FURY Beast RGB 64 GB (2 × 32 GB) DDR5-6000 CL36**, model KF560C36BWEAK2-64 |
| Storage | Samsung 990 PRO 4 TB NVMe SSD with heatsink |
| Power supply | 750 W, 80 PLUS Gold |
| CPU cooling | Liquid cooling |

**The Kingston FURY 64 GB kit listed above is currently installed.**

## Monitors and DCS display layout

| Display | Resolution | Listed refresh rate | Use |
| --- | --- | --- | --- |
| Samsung Odyssey G9 G95C, 49-inch | 5120 × 1440 | 240 Hz | Primary DCS display |
| LG 32GS60QC-B, 32-inch | 2560 × 1440 | 180 Hz | Other applications |
| Left MFCD display | 800 × 600 | Not recorded | DCS instrument export |
| Right MFCD display | 800 × 600 | Not recorded | DCS instrument export |

My normal DCS configuration uses the **Samsung 49-inch monitor and both MFCD exports**. The LG 32-inch monitor is for other applications. Listed monitor refresh rates are not measured DCS frame rates.

I also own a **Meta Quest 3, 512 GB, with a Quest Link cable**, but I am not currently using VR for DCS. VR performance and settings are considered separately from the normal monitor configuration.

## Existing USB setup and expansion

**I currently run all 12 USB devices through a single powered USB hub without any issues, after rewiring my SIMPIT when I started the ARC-210 project.** My existing USB equipment includes MFCD controls, button boxes, a keyboard, HOTAS, and a flight stick. The radio panels will join that USB setup.

I have purchased these hubs for the radio panels and future cockpit panels:

- [RSHTECH RSH-ST10C-6 powered 10-port USB hub](https://www.amazon.com/dp/B0DX6KR79L) — six USB-C and four USB-A ports, with a listed 60 W power adapter.
- [ACASIS powered 16-port USB hub](https://www.amazon.com/dp/B07G8S324L) — with a listed 96 W power adapter.

Only one hub is currently in use; the other is available for expansion. Which of the two is currently connected has not been recorded here.

The ARC-210, ARC-164, and ARC-186 are each planned to use a dedicated Teensy 4.1 and their own USB connection. A Teensy may also operate several smaller panels where the pin count, processing needs, power budget, and wiring allow. Where practical, expanded hubs will connect directly to the PC with short hub chains.

See [USB connections and powered hubs](USB-Connections-and-Powered-Hubs.md) for the USB-versus-RS-485 decision, GPIO use, bandwidth, power, electrical noise, and optional ferrite chokes.

## Other cockpit equipment and software

My saved setup also lists:

- WinWing HOTAS, rudder pedals, and control panels.
- Thrustmaster Cougar MFD controls.
- TrackIR 5 and Stream Deck.
- DCS-BIOS, Tacview, and OpenKneeboard.

My primary DCS aircraft is the **A-10C II Thunderbolt II**. The radio projects are being developed for this cockpit; compatibility with additional aircraft requires the appropriate mappings and testing.
