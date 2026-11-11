[Back to the main project README](../README.md)

# USB connections and powered hubs

**Last updated: November 10, 2026 at 8:30 PM MST (America/Denver)**

I’m keeping **a dedicated Teensy 4.1 and USB connection to DCS-BIOS for each radio: the ARC-210, ARC-164, and ARC-186**. Three connections are manageable, and I can build, test, update, and troubleshoot each radio independently.

USB is already part of my SIMPIT. I use it for my MFCDs, button boxes, keyboard, HOTAS, and flight stick. I also own **three other SIMPIT panels that use USB**, and I have used them for **over 1,000 hours in the past year without any issues**.

When I started the ARC-210 project, I rewired my SIMPIT. **I currently run all 12 USB devices through one hub without any issues.** I’ll build on that setup, adding the radio controllers and future panels one at a time and testing everything together as I go.

## Why I’m staying with USB

See my [DCS-BIOS setup and connection guide](DCS-BIOS.md) for the connection software I use, TekConnect downloads, and radio export requirements.

RS-485 can let several panel controllers share one connection to the PC, reducing USB ports and COM ports. It also adds transceivers, bus wiring, termination, addressing, and a master interface. My existing cockpit devices would still need USB, so I don’t see enough benefit to add that complexity for these radios.

USB also leaves the Teensy’s header GPIO pins available for controls and displays. A typical half-duplex RS-485 connection would use **three pins: TX, RX, and direction control**. For the Teensy 4.1’s 42 readily accessible I/O pins, that leaves **42 with USB versus 39 after allocating three to RS-485**, before connecting the panel hardware.

**One Teensy can run several smaller panels through a single USB connection**, provided their combined pin count, processing needs, and power requirements fit. I may use that approach for nearby panels where the wiring is practical. I’m still keeping a separate Teensy for each radio, so the number of cockpit panels or DCS-BIOS categories does not determine how many USB connections I’ll need.

## USB hubs I’ve purchased

I purchased these powered hubs for the **three radio panels and future cockpit panels**:

- [RSHTECH RSH-ST10C-6 powered 10-port USB hub](https://www.amazon.com/dp/B0DX6KR79L) — six USB-C ports and four USB-A ports, with a listed 60 W power adapter.
- [ACASIS powered 16-port USB hub](https://www.amazon.com/dp/B07G8S324L) — with a listed 96 W power adapter.

These are my choices for this build; other builders don’t need to buy the same hubs. Where practical, I’ll connect each hub directly to the PC and keep any daisy-chaining short. Controllers and displays share the hub’s available power, so I’ll check the completed panels’ current draw and test them together. Lighting and other larger loads may need separate power.

## USB device limits as my cockpit grows

My **12 existing USB devices plus the three planned radio panels would make 15 connected devices**, before counting the hubs and any devices built into them. That is a reasonable expansion target, and I will test the complete setup as I add each radio.

USB 2.0 allows up to **127 addressed devices per bus, including hubs**. Several motherboard sockets may share the same bus or controller. The practical limit can be lower because devices also use controller device slots and endpoints, share bandwidth, and need suitable power. The 127-device figure is a theoretical bus limit rather than a guaranteed capacity for my PC. See the [USB 2.0 overview](https://support.hp.com/hr-en/document/c01208644) and [Microsoft USB controller documentation](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-3-0-driver-stack-architecture).

Powered hubs give me more connections and power, while the attached devices still share the host controller resources. Additional USB controllers can provide more resources. I would need to check how my motherboard routes its ports across controllers to establish its practical capacity. My current 12-device setup has been reliable, and testing all 15 together will confirm how the expanded setup performs.

## Electronic noise and a full cockpit

**I plan to keep USB even if I build all of the cockpit controls.** My current setup has been reliable, and I haven’t found a noise problem that would justify switching to RS-485. I haven’t tested every planned panel together yet, so I’ll keep checking as the cockpit grows.

Motors, solenoids, force-feedback equipment, and high-current lighting drivers are more likely noise sources than the number of switches and panels. USB and RS-485 both use differential signaling to help reject interference. An ordinary, non-isolated RS-485 transceiver does not provide electrical isolation or automatically eliminate ground loops. See [Analog Devices’ explanation of USB signaling and ground-loop isolation](https://www.analog.com/en/resources/technical-articles/breaking-ground-loops-with-functional-isolation.html).

For my cockpit, I’ll:

- Keep controllers near their panels and switch and encoder wiring short.
- Use good USB data cables and keep hub chains short.
- Route signal cables away from motor and high-current power wiring.
- Give motors and larger loads suitable separate power rather than drawing it through the Teensy or USB supply; see [PJRC’s servo-power guidance](https://www.pjrc.com/teensy/td_libs_Servo.html).
- Check power budgets and test the panels together as I add them.

RS-485 would change the link between controllers; it would not fix noisy switch wiring, unstable display power, or overloaded hubs. I’ll revisit the communication system if testing reveals a persistent problem that suitable wiring and power distribution cannot resolve.

### Optional clip-on ferrite chokes

If I encounter high-frequency interference on a USB or power cable, I can try **clip-on ferrite chokes**, also called ferrite cores or clamp filters. They fit around the whole cable without cutting it and suppress common-mode noise. The material, noise frequency, and placement affect how well they work; I can try them near the controller, hub, or identified noise source. See [TDK’s explanation of snap-on clamp filters](https://www.tdk.com/en/tech-mag/noise/09).

Ferrites won’t fix insufficient power, loose connections, switch bounce, or every grounding problem. I can add them later if needed; I don’t need to change the USB plan because of possible noise alone.

## Motherboard connections and USB speed

My DCS computer has an **ASUS ROG STRIX X870E-E GAMING WIFI** motherboard. Its rear connections include **ten USB 10 Gbps ports (nine USB-A and one USB-C), one USB 20 Gbps USB-C port, and two USB4 40 Gbps USB-C ports**. That gives me several places to connect the hubs directly. See the [ASUS motherboard specifications](https://rog.asus.com/us/motherboards/rog-strix/rog-strix-x870e-e-gaming-wifi/spec/?config=90MB1IB0-MVAAY0).

**I don’t expect USB bandwidth to limit the cockpit controls or radio panels.** Switch, encoder, and DCS-BIOS data traffic is small compared with storage transfers, cameras, or USB video. The Teensy 4.1 uses **USB 2.0 high speed at up to 480 Mbps**. A USB 3 port won’t make that connection faster, and 480 Mbps is the signaling rate rather than a measured application transfer rate. See the [PJRC Teensy 4.1 specifications](https://www.pjrc.com/store/teensy41.html).

A hardware listing for this motherboard reports **six USB host controllers**. Three are on the Ryzen CPU, two are on the X870E chipset, and one is on the ASMedia ASM4242, which also exposes a USB4 router. I still need to verify which controllers are active on my DCS computer. [Motherboard hardware listing](https://iommu.info/mainboard/?board_name=ROG+STRIX+X870E-E+GAMING+WIFI&board_vendor=ASUSTeK+COMPUTER+INC.)

With my 10-port and 16-port powered hubs plugged directly into two rear ports, I have **37 sockets available for devices**, with 26 on the hubs and 11 on the rear panel. Another 16-port hub plugged into a third rear port would bring that to **52 sockets**. Simultaneous device capacity depends on the host controllers the hubs use, the devices and endpoints each controller must handle, and the available bandwidth and power.

On my DCS PC, I can open **Device Manager → View → Devices by connection**, expand the USB host controller and root hub branches, and trace each powered hub to its host controller. If the hubs have similar names, I can unplug and reconnect them one at a time to identify each entry. I can try another rear port and check the tree again to spread the hubs across controllers. [Microsoft USBView and Device Manager guidance](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/usbview)

Devices on a hub share its upstream connection. USB 2.0 devices use the hub’s USB 2.0 connection rather than gaining its advertised USB 3 bandwidth, and separate motherboard sockets may still share controller resources. Powered hubs provide connections and power; they don’t increase the host controller’s device or endpoint capacity.

For my setup, I expect **power, controller resources, cable reliability, and hub depth** to matter more than the radios’ bandwidth needs. Where practical, I’ll connect higher-bandwidth devices such as Quest Link, USB cameras, and external SSDs directly to the PC. My current 12-device setup works through one hub, and I’ll keep testing everything together as I expand it.
