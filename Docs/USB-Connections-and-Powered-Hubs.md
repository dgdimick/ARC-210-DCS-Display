[Back to the main project README](../README.md)

# USB connections and powered hubs

The **ARC-210, ARC-164, and ARC-186 will each use a dedicated Teensy 4.1 with its own USB connection to DCS-BIOS**. Three USB connections are manageable, and each radio can be built, tested, updated, and troubleshot independently.

RS-485 can reduce USB ports and COM-port connections when many cockpit panels share a communication bus, but it adds transceiver hardware, bus wiring, termination, addressing, and a master interface. For these three radios, separate USB connections keep assembly and setup simpler. **USB remains the planned connection for each radio.**

**Powered USB hubs are the preferred expansion approach for this cockpit.** I already use USB for my MFCDs, button boxes, keyboard, HOTAS, and flight stick, so the radio panels will use the same USB setup. **I currently use 12 USB devices without any issues.** That experience supports continuing with USB and adding the radio controllers incrementally, while checking power requirements and testing the expanded setup as new panels are connected. RS-485 would consolidate the panel-controller connections, but those existing devices would still need USB. Building on the powered-hub setup already in use keeps the radios consistent with the rest of my cockpit. Powered hubs allow multiple Teensy controllers to share the PC's USB connections, preserve header GPIO pins, and work with the planned USB DCS-BIOS firmware. Each controller can still be tested, updated, and troubleshot independently, without adding RS-485 transceivers, bus termination, addressing, or a master interface. One Teensy can serve several smaller panels, so the number of cockpit panels or DCS-BIOS categories does not determine the number of USB devices.

Where practical, connect several powered hubs directly to the PC and keep any hub daisy-chaining short. Choose hubs and power supplies with enough capacity for the connected controllers and displays; higher-current lighting and other loads may need separate power.

**RS-485 would normally use three GPIO pins per controller: hardware-serial TX, RX, and a transmit/receive direction-control pin. USB uses no header GPIO pins, leaving those connections available for controls and displays.** On a Teensy 4.1, that means 42 readily accessible I/O pins remain available with USB, compared with 39 after allocating three pins to RS-485, before accounting for the panel's other connections.

**One Teensy can also run multiple smaller panels through a single USB connection**, provided their combined pin count, processing needs, and power requirements fit within the controller's limits. Nearby panels can share a controller when the wiring is practical, so future expansion does not require a separate USB connection for every panel. The current radio plan remains unchanged: the ARC-210, ARC-164, and ARC-186 will each have their own dedicated Teensy 4.1.

### USB hubs purchased for this cockpit

I have purchased the following powered USB hubs and plan to use them for the **ARC-210, ARC-164, and ARC-186 radio panels, along with future cockpit panels**:

- [RSHTECH RSH-ST10C-6 powered 10-port USB hub](https://www.amazon.com/dp/B0DX6KR79L) — six USB-C ports and four USB-A ports, with a listed 60 W power adapter.
- [ACASIS powered 16-port USB hub](https://www.amazon.com/dp/B07G8S324L) — with a listed 96 W power adapter.

Where practical, each hub will connect directly to the PC. The connected controllers and displays will share each hub's available power; completed-panel current draw and multi-panel operation still need to be tested. These are the hubs I have purchased for my build, rather than required purchases for other builders.

## Electronic noise and a full cockpit

**USB remains a reasonable choice even if I build all of the cockpit controls.** Adding RS-485 solely to prevent possible electrical noise would add hardware and firmware complexity without an established need. This is a design choice to verify as the cockpit expands, rather than a claim that every completed panel has already been tested together.

The number of switches and panels is not the main source of interference. Motors, solenoids, force-feedback equipment, and high-current lighting drivers are more significant potential noise sources. USB already uses differential signaling to help reject interference. RS-485 also uses differential signaling, but an ordinary, non-isolated RS-485 transceiver does not provide electrical isolation or automatically eliminate ground loops. See [Analog Devices' explanation of differential USB communication and ground-loop isolation](https://www.analog.com/en/resources/technical-articles/breaking-ground-loops-with-functional-isolation.html).

For the full cockpit, the plan is to:

- Keep controllers close to their panels and keep switch and encoder wiring short.
- Use good USB data cables and keep hub chains short.
- Route signal cables away from motor wiring and high-current power wiring.
- Provide suitable separate power for motors and larger loads instead of drawing it through the Teensy or its USB supply; see [PJRC's servo-power guidance](https://www.pjrc.com/teensy/td_libs_Servo.html).
- Check power budgets and test panels together as the cockpit grows.

RS-485 would change the communication link between controllers; it would not fix noisy switch wiring, unstable display power, or overloaded USB hubs. **The plan is to continue with powered USB hubs and revisit the communication system only if testing reveals a persistent problem that appropriate wiring and power distribution do not resolve.**

### Optional clip-on ferrite chokes

If testing reveals high-frequency interference on USB or power cables, **clip-on ferrite chokes (also called ferrite cores or clamp filters) can be added as a troubleshooting measure**. They clamp around the whole cable without cutting it and suppress common-mode noise. Their effectiveness depends on the ferrite material, noise frequency, and placement; locations near the controller, hub, or identified noise source can be evaluated. See [TDK's explanation of snap-on clamp filters](https://www.tdk.com/en/tech-mag/noise/09).

Ferrite chokes will not fix insufficient power, loose connections, mechanical switch bounce, or every grounding problem. **They can be added later if needed; possible noise alone is not a reason to change the USB plan.**
