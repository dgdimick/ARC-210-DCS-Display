[Back to the main project README](../README.md)

# USB connections and powered hubs

The **ARC-210, ARC-164, and ARC-186 will each use a dedicated Teensy 4.1 with its own USB connection to DCS-BIOS**. Three USB connections are manageable, and each radio can be built, tested, updated, and troubleshot independently.

RS-485 can reduce USB ports and COM-port connections when many cockpit panels share a communication bus, but it adds transceiver hardware, bus wiring, termination, addressing, and a master interface. For these three radios, separate USB connections keep assembly and setup simpler. **USB remains the planned connection for each radio.**

**Powered USB hubs are the preferred expansion approach for this cockpit.** I already use USB for my MFCDs, button boxes, keyboard, HOTAS, and flight stick, so the radio panels will use the same USB setup. RS-485 would consolidate the panel-controller connections, but those existing devices would still need USB. Building on the powered-hub setup already in use keeps the radios consistent with the rest of my cockpit. Powered hubs allow multiple Teensy controllers to share the PC's USB connections, preserve header GPIO pins, and work with the planned USB DCS-BIOS firmware. Each controller can still be tested, updated, and troubleshot independently, without adding RS-485 transceivers, bus termination, addressing, or a master interface. One Teensy can serve several smaller panels, so the number of cockpit panels or DCS-BIOS categories does not determine the number of USB devices.

Where practical, connect several powered hubs directly to the PC and keep any hub daisy-chaining short. Choose hubs and power supplies with enough capacity for the connected controllers and displays; higher-current lighting and other loads may need separate power.

**RS-485 would normally use three GPIO pins per controller: hardware-serial TX, RX, and a transmit/receive direction-control pin. USB uses no header GPIO pins, leaving those connections available for controls and displays.** On a Teensy 4.1, that means 42 readily accessible I/O pins remain available with USB, compared with 39 after allocating three pins to RS-485, before accounting for the panel's other connections.

**One Teensy can also run multiple smaller panels through a single USB connection**, provided their combined pin count, processing needs, and power requirements fit within the controller's limits. Nearby panels can share a controller when the wiring is practical, so future expansion does not require a separate USB connection for every panel. The current radio plan remains unchanged: the ARC-210, ARC-164, and ARC-186 will each have their own dedicated Teensy 4.1.

### USB hubs purchased for this cockpit

I have purchased the following powered USB hubs and plan to use them for the **ARC-210, ARC-164, and ARC-186 radio panels, along with future cockpit panels**:

- [RSHTECH RSH-ST10C-6 powered 10-port USB hub](https://www.amazon.com/dp/B0DX6KR79L) — six USB-C ports and four USB-A ports, with a listed 60 W power adapter.
- [ACASIS powered 16-port USB hub](https://www.amazon.com/dp/B07G8S324L) — with a listed 96 W power adapter.

Where practical, each hub will connect directly to the PC. The connected controllers and displays will share each hub's available power; completed-panel current draw and multi-panel operation still need to be tested. These are the hubs I have purchased for my build, rather than required purchases for other builders.
