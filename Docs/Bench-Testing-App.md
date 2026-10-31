[Back to the main project README](../README.md)

# ARC-210 Bench Testing App

For installation, Lua file changes, and connecting the panel to DCS with TekConnect, use the [DCS-BIOS setup guide](DCS-BIOS.md). This page covers testing with simulated data.

I use a [modified version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working), based on [tldBear’s original, unmodified app](https://github.com/tldBear/dcsBiosDebug). I modified my version to provide better support for the ARC-210, adding buttons for menu testing and separate Frequency, Secondary, and Master controls. These controls send simulated DCS-BIOS data to the Teensy so I can test the panel without running DCS.

Download the **arc210-working** branch using **Code → Download ZIP**, extract it, and keep its `icons` folder beside the Python script. With Python 3 and Tkinter installed, open a terminal in that folder and run:

```cmd
python -m pip install numpy pyserial Pillow
python dcsBiosDebug.py
```

Use the Python script, including the `.py` extension; the original bundled executable does not include the ARC-210 controls. Select your Teensy's serial port and click **Connect**. Choose **2 - TR** and click **Set Master** for the normal radio switch position, or **0 - OFF** to test power off.

See the [full testing instructions and compatibility notes](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md). The shortcuts use fixed A-10C II addresses and send data to the hardware, not commands to DCS. Some firmware states require additional exports through the normal instrument controls.
