#define DCSBIOS_DEFAULT_SERIAL

#include <DcsBios.h>

#include "Display.h"
#include "BootSequence.h"
#include "DcsCallbacks.h"
#include "Arc210State.h"
#include "MenuNavigation.h"


// ==================================================
// ARC-210 FREQUENCY
//
// Address : 0x1382
// Length  : 7
// ==================================================
DcsBios::StringBuffer<7> arc210FrequencyBuffer(
    0x1382,
    onArc210FrequencyChange
);

// ARC210_PREV_MANUAL_FREQ: actual PREV value from DCS, including startup.
DcsBios::StringBuffer<7> arc210PreviousFrequencyBuffer(
    0x1314,
    onArc210PreviousFrequencyChange
);


// ==================================================
// ARC-210 MODULATION DISPLAY
//
// Address : 0x131E
// Length  : 2
//
// Expected values:
// AM
// FM
// ==================================================
DcsBios::StringBuffer<2> arc210ModulationTextBuffer(
    0x131E,
    onArc210ModulationTextChange
);


// ==================================================
// ARC-210 COMSEC SUBMODE
//
// Address : 0x12BE
// Length  : 5
//
// Expected values:
// PT
// CT
// CT-TD
// ==================================================
DcsBios::StringBuffer<5> arc210ComsecSubmodeBuffer(
    0x12BE,
    onArc210ComsecSubmodeChange
);


// ==================================================
// ARC-210 XMIT / RECV
//
// Address : 0x12BA
// Length  : 4
//
// Expected values:
// XMIT
// RECV
// ==================================================
DcsBios::StringBuffer<4> arc210XmitRecvBuffer(
    0x12BA,
    onArc210XmitRecvChange
);


// ==================================================
// ARC-210 ACTIVE PRESET CHANNEL
//
// Address : 0x1336
// Length  : 2
//
// Expected examples:
// 01
// 02
// 15
// ==================================================
DcsBios::StringBuffer<2> arc210ActiveChannelBuffer(
    0x1336,
    onArc210ActiveChannelChange
);


// ==================================================
// KY-58 ENCRYPTION NUMBER
//
// Selected encryption/key number
//
// Address : 0x11B8
// Mask    : 0x01C0
// Shift   : 6
// Range   : 0-5
// ==================================================
DcsBios::IntegerBuffer ky58EncryptionBuffer(
    0x11B8,
    0x01C0,
    6,
    onKy58EncryptionChange
);

// ARC210_KY_SUBMODE: the actual one-character label displayed by DCS.
DcsBios::StringBuffer<1> arc210KyLabelBuffer(0x1308, onArc210KyLabelChange);

// HQ operating date / WOD channel indication (0-31).
DcsBios::StringBuffer<2> arc210OperDateBuffer(0x1338, onArc210OperDateChange);

// RT indication disappears when the cockpit radio display loses power.
DcsBios::StringBuffer<3> arc210SelectedRtBuffer(0x1320, onArc210SelectedRtChange);


// ==================================================
// ARC-210 MASTER SWITCH
//
// 0 = OFF
// 1 = TR-G
// 2 = TR
// 3 = ADF
// 4 = CHG PRST
// 5 = TEST
// 6 = ZERO
//
// Address : 0x1322
// Mask    : 0x1C00
// Shift   : 10
// ==================================================
DcsBios::IntegerBuffer arc210MasterBuffer(
    0x1322,
    0x1C00,
    10,
    onArc210MasterChange
);


// ==================================================
// ARC-210 SECONDARY / FREQUENCY MODE SWITCH
//
// 0 = ECCM MASTER
// 1 = ECCM
// 2 = PRST
// 3 = MAN
// 4 = MAR
// 5 = 243 GUARD
// 6 = 121.500 GUARD
//
// Address : 0x1322
// Mask    : 0xE000
// Shift   : 13
// ==================================================
DcsBios::IntegerBuffer arc210SecSwBuffer(
    0x1322,
    0xE000,
    13,
    onArc210SecSwChange
);


// ==================================================
// ARC-210 MENU / FSK BUTTONS
//
// DCS-BIOS controls:
//   ARC210_MENU
//   ARC210_TRANS_REC_FUNC
//   ARC210_FSK_UP
//   ARC210_FSK_MID
//   ARC210_FSK_LOW
//
// These are momentary controls. The callbacks react
// only when the exported state is 1 (button pressed).
// ==================================================
DcsBios::IntegerBuffer arc210MenuButtonBuffer(
    0x1334,
    0x1000,
    12,
    onArc210MenuButtonChange
);

DcsBios::IntegerBuffer arc210XmtRcvButtonBuffer(
    0x1334,
    0x0400,
    10,
    onArc210XmtRcvButtonChange
);

DcsBios::IntegerBuffer arc210UpperLskBuffer(
    0x1366,
    0x0400,
    10,
    onArc210UpperLskChange
);

DcsBios::IntegerBuffer arc210MiddleLskBuffer(
    0x1366,
    0x0800,
    11,
    onArc210MiddleLskChange
);

DcsBios::IntegerBuffer arc210LowerLskBuffer(
    0x1366,
    0x1000,
    12,
    onArc210LowerLskChange
);


// ==================================================
// SETUP
// ==================================================
// Read-only knob observations for HQ menu exits.
DcsBios::IntegerBuffer hqChannelKnob(0x137E, 0xFFFF, 0, onHQChannelKnobChange);
DcsBios::IntegerBuffer hqFreq100M(0x1326, 0x0300, 8, onHQFreq100MChange);
DcsBios::IntegerBuffer hqFreq10M(0x1326, 0x3C00, 10, onHQFreq10MChange);
DcsBios::IntegerBuffer hqFreq1M(0x1330, 0x0F00, 8, onHQFreq1MChange);
DcsBios::IntegerBuffer hqFreq100K(0x1330, 0xF000, 12, onHQFreq100KChange);
DcsBios::IntegerBuffer hqFreq25K(0x1326, 0xC000, 14, onHQFreq25KChange);

void setup()
{
    initializeDisplay();

    DcsBios::setup();

    // Stay blank until DCS-BIOS supplies the real radio state.
}


// ==================================================
// LOOP
// ==================================================
void loop()
{
    DcsBios::loop();

    updateBootSequence();
    updateArc210Menu();
    flushDisplay();
}
