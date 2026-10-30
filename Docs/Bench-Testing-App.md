[Back to the main project README](../README.md)

# ARC-210 Bench Testing App

I keep the [working ARC-210 version of dcsBiosDebug](https://github.com/dgdimick/dcsBiosDebug/tree/arc210-working) in a separate repository. It provides buttons for menu testing and separate Frequency, Secondary, and Master controls for sending simulated DCS-BIOS data to your Teensy without running DCS.

Download the **arc210-working** branch using **Code → Download ZIP**, extract it, and keep its `icons` folder beside the Python script. With Python 3 and Tkinter installed, open a terminal in that folder and run:

```cmd
python -m pip install numpy pyserial Pillow
python dcsBiosDebug.py
```

Use the Python script, including the `.py` extension; the original bundled executable does not include the ARC-210 controls. Select your Teensy's serial port and click **Connect**. Choose **2 - TR** and click **Set Master** for the normal radio switch position, or **0 - OFF** to test power off.

See the [full testing instructions and compatibility notes](https://github.com/dgdimick/dcsBiosDebug/blob/arc210-working/ARC210_TESTING.md). The shortcuts use fixed A-10C II addresses and send data to the hardware, not commands to DCS. Some firmware states require additional exports through the normal instrument controls.
