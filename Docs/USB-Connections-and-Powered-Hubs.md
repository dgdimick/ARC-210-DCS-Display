[Back to the main project README](../README.md)

# USB connections and powered hubs

I also own three other SIMPIT panels that use USB.

I’ll use a **dedicated Teensy 4.1 and USB connection to DCS-BIOS for each radio: the ARC-210, ARC-164, and ARC-186**. Three USB connections are manageable, and each radio can be built, tested, updated, and troubleshot independently.

RS-485 can reduce USB ports and COM-port connections when many cockpit panels share a communication bus, but it adds transceiver hardware, bus wiring, termination, addressing, and a master interface. For these three radios, separate USB connections keep assembly and setup simpler. **I plan to keep USB for each radio.**

**I’m using powered USB hubs to expand my cockpit.** I already use USB for my MFCDs, button boxes, keyboard, HOTAS, and flight stick, so the radio panels will use the same USB setup. **I currently run all 12 USB devices through a single USB hub without any issues, after rewiring my SIMPIT when I started the ARC-210 project.** That experience supports my plan to keep using USB and add the radio controllers one at a time. I’ll check power requirements and test the setup as I connect new panels. RS-485 would consolidate the panel-controller connections, but those existing devices would still need USB. Building on the powered-hub setup already in use keeps the radios consistent with the rest of my cockpit. Powered hubs allow multiple Teensy controllers to share the PC's USB connections, preserve header GPIO pins, and work with the planned USB DCS-BIOS firmware. Each controller can still be tested, updated, and troubleshot independently, without adding RS-485 transceivers, bus termination, addressing, or a master interface. One Teensy can serve several smaller panels, so the number of cockpit panels or DCS-BIOS categories does not determine the number of USB devices.

Where practical, connect several powered hubs directly to the PC and keep any hub daisy-chaining short. Choose hubs and power supplies with enough capacity for the connected controllers and displays; higher-current lighting and other loads may need separate power.

**RS-485 would normally use three GPIO pins per controller: hardware-serial TX, RX, and a transmit/receive direction-control pin. USB uses no header GPIO pins, leaving those connections available for controls and displays.** On a Teensy 4.1, that means 42 readily accessible I/O pins remain available with USB, compared with 39 after allocating three pins to RS-485, before accounting for the panel's other connections.

**One Teensy can also run multiple smaller panels through a single USB connection**, provided their combined pin count, processing needs, and power requirements fit within the controller's limits. Nearby panels can share a controller when the wiring is practical, so future expansion does not require a separate USB connection for every panel. I’m keeping a dedicated Teensy 4.1 for each of the three radios.

### USB hubs purchased for this cockpit

I have purchased the following powered USB hubs and plan to use them for the **ARC-210, ARC-164, and ARC-186 radio panels, along with future cockpit panels**:

- [RSHTECH RSH-ST10C-6 powered 10-port USB hub](https://www.amazon.com/dp/B0DX6KR79L) — six USB-C ports and four USB-A ports, with a listed 60 W power adapter.
- [ACASIS powered 16-port USB hub](https://www.amazon.com/dp/B07G8S324L) — with a listed 96 W power adapter.

Where practical, I’ll connect each hub directly to my PC. The connected controllers and displays will share each hub's available power; I still need to check the completed panels’ current draw and test them together. These are the hubs I have purchased for my build, rather than required purchases for other builders.

## Electronic noise and a full cockpit

**USB remains a reasonable choice even if I build all of the cockpit controls.** Adding RS-485 solely to prevent possible electrical noise would add hardware and firmware complexity without an established need. I’ll check this choice as I expand the cockpit; I haven’t tested every planned panel together yet.

The number of switches and panels is not the main source of interference. Motors, solenoids, force-feedback equipment, and high-current lighting drivers are more significant potential noise sources. USB already uses differential signaling to help reject interference. RS-485 also uses differential signaling, but an ordinary, non-isolated RS-485 transceiver does not provide electrical isolation or automatically eliminate ground loops. See [Analog Devices' explanation of differential USB communication and ground-loop isolation](https://www.analog.com/en/resources/technical-articles/breaking-ground-loops-with-functional-isolation.html).

For my full cockpit, I plan to:

- Keep controllers close to their panels and keep switch and encoder wiring short.
- Use good USB data cables and keep hub chains short.
- Route signal cables away from motor wiring and high-current power wiring.
- Provide suitable separate power for motors and larger loads instead of drawing it through the Teensy or its USB supply; see [PJRC's servo-power guidance](https://www.pjrc.com/teensy/td_libs_Servo.html).
- Check power budgets and test panels together as the cockpit grows.

RS-485 would change the communication link between controllers; it would not fix noisy switch wiring, unstable display power, or overloaded USB hubs. **I’ll continue with powered USB hubs and revisit the communication system only if testing reveals a persistent problem that appropriate wiring and power distribution do not resolve.**

### Optional clip-on ferrite chokes

If testing reveals high-frequency interference on USB or power cables, **clip-on ferrite chokes (also called ferrite cores or clamp filters) can be added as a troubleshooting measure**. They clamp around the whole cable without cutting it and suppress common-mode noise. Their effectiveness depends on the ferrite material, noise frequency, and placement; locations near the controller, hub, or identified noise source can be evaluated. See [TDK's explanation of snap-on clamp filters](https://www.tdk.com/en/tech-mag/noise/09).

Ferrite chokes will not fix insufficient power, loose connections, mechanical switch bounce, or every grounding problem. **They can be added later if needed; possible noise alone is not a reason to change the USB plan.**

## Motherboard connections and USB speed

My DCS computer uses an **ASUS ROG STRIX X870E-E GAMING WIFI** motherboard. Its rear connections include **ten USB 10 Gbps ports (nine USB-A and one USB-C), one USB 20 Gbps USB-C port, and two USB4 40 Gbps USB-C ports**, providing several options for connecting the powered hubs directly to the PC. See the [ASUS motherboard specifications](https://rog.asus.com/us/motherboards/rog-strix/rog-strix-x870e-e-gaming-wifi/spec/?config=90MB1IB0-MVAAY0).

**USB bandwidth is not expected to be the limiting factor for the cockpit controls and three radio panels.** Switch, encoder, and DCS-BIOS radio data traffic is small compared with storage transfers, cameras, or USB video. The Teensy 4.1 uses a **USB 2.0 high-speed connection at up to 480 Mbps**; connecting it to a USB 3 port does not increase that signaling rate. The 480 Mbps figure is the interface signaling rate, not a measured application transfer rate. See the [PJRC Teensy 4.1 specifications](https://www.pjrc.com/store/teensy41.html).

Devices on a hub share its upstream connection, and separate motherboard sockets may still share internal controller resources. USB 2.0 devices also remain subject to the USB 2.0 side of the hub rather than gaining the full advertised USB 3 bandwidth. Powered hubs add connections and supply power, but do not increase the host controller's device or endpoint capacity.

For this setup, power budgets, controller resource limits, cable reliability, and hub depth are more likely constraints than the radio panels' bandwidth needs. I’ll connect each powered hub directly to the motherboard where practical and add panels incrementally. If used, higher-bandwidth devices such as **Quest Link, USB cameras, and external SSDs** should connect directly to the PC where practical. The existing 12-device setup runs reliably through one hub; I’ll keep testing everything together as I add panels.
