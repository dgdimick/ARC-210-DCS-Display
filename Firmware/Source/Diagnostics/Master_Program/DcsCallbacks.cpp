#include <Arduino.h>
#include <string.h>

#include "DcsCallbacks.h"
#include "Arc210State.h"
#include "BootSequence.h"
#include "MenuNavigation.h"
#include "MenuState.h"

#include <Display.h>


// ==================================================
// LOCAL STATE
// ==================================================

// Used so connecting the Teensy to DCS does not
// automatically run the startup sequence if the
// radio is already powered.
bool masterStateInitialized = false;


// ==================================================
// HELPER
//
// Returns TRUE when the Master Switch position
// requires the UNAVAILABLE screen.
//
// 3 = ADF
// 5 = TEST
// 6 = ZERO
// ==================================================
bool isUnavailableMasterMode()
{
    return (
        masterSwitch == 3 ||
        masterSwitch == 5 ||
        masterSwitch == 6
    );
}


// ==================================================
// HELPER
//
// Determines whether the ARC-210 should currently
// display UNAVAILABLE.
//
// MAR on the secondary selector overrides all
// powered Master Switch positions.
// ==================================================
bool shouldShowUnavailable()
{
    // Secondary selector:
    // 4 = MAR
    if (frequencyMode == 4)
    {
        return true;
    }

    // Master Switch:
    // ADF / TEST / ZERO
    if (isUnavailableMasterMode())
    {
        return true;
    }

    return false;
}


// ==================================================
// DISPLAY CURRENT RADIO STATE
// ==================================================
void updateRadioDisplay()
{
    // Master OFF always wins
    if (!radioOn)
    {
        blankScreen();
        return;
    }

    // Do not overwrite startup screens
    if (bootStage != BOOT_IDLE)
    {
        return;
    }

    if (!radioDisplayPowered)
    {
        blankScreen();
        return;
    }

    // Keep live DCS-BIOS updates from overwriting an active menu.
    if (isArc210MenuActive())
    {
        return;
    }

    // MAR / ADF / TEST / ZERO
    if (shouldShowUnavailable())
    {
        showUnavailableScreen();
        return;
    }

    if (!dcsConnected)
    {
        blankScreen();
        return;
    }

    // ==================================================
    // STATIC GUARD MODES
    //
    // Secondary selector:
    // 5 = 243.000 MHz GUARD
    // 6 = 121.500 MHz GUARD
    //
    // Only the selector position is needed from
    // DCS-BIOS. The page contents are fixed.
    // ==================================================
    if (frequencyMode == 5)
    {
        showGuard243Screen(currentModulation);
        return;
    }

    if (frequencyMode == 6)
    {
        showGuard121Screen(currentModulation);
        return;
    }

    // ==================================================
    // PRESET MODE
    //
    // Secondary selector:
    // 2 = PRST
    // ==================================================
    if (frequencyMode == 2)
    {
        showPresetScreen(
            currentActiveChannel,
            currentFrequency,
            currentModulation,
            currentComsecSubmode,
            currentEncryptionNumber
        );

        // MASTER = 4 (CHG PRST):
        // Show LOAD in the normal PREV top-left location.
		if (masterSwitch == 4 && frequencyMode == 2)        {
            drawLoad();
        }

     // ==================================================
// XMIT / RECV
//
// Only display on:
// Master Switch = 4  (CHG PRST)
// Secondary     = 2  (PRST)
// Channels      = 26 through 30
// ==================================================

int channelNumber = atoi(currentActiveChannel);

if (
    masterSwitch == 4 &&
    frequencyMode == 2 &&
    channelNumber >= 26 &&
    channelNumber <= 30
   )
{
    // If DCS-BIOS has not supplied the status yet,
    // default to XMIT.
    if (currentXmitRecv[0] == '\0')
    {
        drawXmitRecv("XMIT");
    }
    else
    {
        drawXmitRecv(currentXmitRecv);
    }
}
else
{
    drawXmitRecv("");
}

        return;
    }

    // ==================================================
    // NORMAL / MAN FREQUENCY DISPLAY
    // ==================================================
    showFrequencyScreen(
        currentFrequency,
        currentModulation,
        previousFrequency,
        currentComsecSubmode
    );

    drawXmitRecv(currentXmitRecv);
}


// ==================================================
// ARC-210 FREQUENCY CALLBACK
// ==================================================
void onArc210PreviousFrequencyChange(char* newValue)
{
    // Keep the value when absent on menus, but accept DCS's dashed PREV value.
    bool hasFrequencyOrDashes = false;
    for (unsigned int i = 0; i < 7 && newValue[i] != '\0'; ++i)
        if ((newValue[i] >= '0' && newValue[i] <= '9') || newValue[i] == '-')
            hasFrequencyOrDashes = true;
    if (!hasFrequencyOrDashes) return;

    strncpy(previousFrequency, newValue, 7);
    previousFrequency[7] = '\0';
    updateRadioDisplay();
}

void onArc210OperDateChange(char* newValue)
{
    setOperDateValue(newValue);
}

// Observe actual knob movement, not changes in the shared export word.
// Seed the initial sample without exiting a menu on connection.
static void onHQKnobChange(unsigned int index, unsigned int value)
{
    static bool initialized[6] = {};
    static unsigned int previous[6] = {};
    const bool changed = initialized[index] && previous[index] != value;
    initialized[index] = true;
    previous[index] = value;
    if (!changed || !menuActive || !radioOn || !radioDisplayPowered || bootStage != BOOT_IDLE) return;
    const bool formatPage = currentMenuPage == ARC210_MENU_HQ_FMT_LOAD;
    const bool frequencyExit = index != 0 &&
        (currentMenuPage == ARC210_MENU_HQ_WOD_LOAD ||
         currentMenuPage == ARC210_MENU_HQ_MORE_3 ||
         currentMenuPage == ARC210_MENU_HQ_OPER_DATE_6B);
    if (formatPage || frequencyExit)
    {
        resetArc210Menu();
        updateRadioDisplay();
    }
}

void onHQChannelKnobChange(unsigned int v) { onHQKnobChange(0, v); }
void onHQFreq100MChange(unsigned int v) { onHQKnobChange(1, v); }
void onHQFreq10MChange(unsigned int v) { onHQKnobChange(2, v); }
void onHQFreq1MChange(unsigned int v) { onHQKnobChange(3, v); }
void onHQFreq100KChange(unsigned int v) { onHQKnobChange(4, v); }
void onHQFreq25KChange(unsigned int v) { onHQKnobChange(5, v); }

void onArc210SelectedRtChange(char* newValue)
{
    const bool wasPowered = radioDisplayPowered;
    radioDisplayPowered = false;
    for (unsigned int i = 0; i < 3 && newValue[i] != '\0'; ++i)
        if (newValue[i] != ' ') radioDisplayPowered = true;
    if (!radioDisplayPowered)
    {
        // A switch-started sequence includes an initial blank game indication.
        // Keep its timed splash/loader/initializing stages running.
        if (radioOn && isRadioSwitchBootActive()) return;
        resetArc210Menu();
        if (wasPowered) cancelBootSequence();
        blankScreen();
        return;
    }
    if (!wasPowered && radioOn && bootStage == BOOT_IDLE)
    {
        startBootSequence(true);
    }
    if (strncmp(newValue, "RT", 2) == 0) syncAircraftBootInitializing();
    updateRadioDisplay();
}

void onArc210FrequencyChange(char* newValue)
{
    char newFrequency[8];

    strncpy(
        newFrequency,
        newValue,
        7
    );

    newFrequency[7] = '\0';
    setHQFrequencyValue(newFrequency);

    // PREV is supplied independently by ARC210_PREV_MANUAL_FREQ.
    if (strcmp(newFrequency, currentFrequency) != 0)
    {
        strncpy(
            currentFrequency,
            newFrequency,
            7
        );

        currentFrequency[7] = '\0';
    }

    // We have received DCS-BIOS data
    dcsConnected = true;
    bool hasFrequencyDigit = false;
    for (unsigned int i = 0; i < 7 && newFrequency[i] != '\0'; ++i)
        if (newFrequency[i] >= '0' && newFrequency[i] <= '9') hasFrequencyDigit = true;
    if (hasFrequencyDigit) finishAircraftBoot();

    if (!radioOn)
    {
        return;
    }

    if (bootStage != BOOT_IDLE)
    {
        return;
    }

    updateRadioDisplay();
}


// ==================================================
// ARC-210 ACTIVE PRESET CHANNEL CALLBACK
//
// Expected examples:
// 01
// 02
// 15
// ==================================================
void onArc210ActiveChannelChange(char* newValue)
{
    strncpy(
        currentActiveChannel,
        newValue,
        2
    );

    currentActiveChannel[2] = '\0';

    dcsConnected = true;

    updateRadioDisplay();
}


// ==================================================
// ARC-210 MODULATION DISPLAY CALLBACK
//
// Expected values:
// AM
// FM
// ==================================================
void onArc210ModulationTextChange(char* newValue)
{
    strncpy(
        currentModulation,
        newValue,
        2
    );

    currentModulation[2] = '\0';

    updateRadioDisplay();
}


// ==================================================
// KY-58 ENCRYPTION NUMBER CALLBACK
// ==================================================
void onKy58EncryptionChange(unsigned int newValue)
{
    currentEncryptionNumber = newValue;

    updateRadioDisplay();
}

void onArc210KyLabelChange(char* newValue)
{
    setRadioKyLabel(newValue);
    updateRadioDisplay();
}


// ==================================================
// ARC-210 COMSEC SUBMODE CALLBACK
//
// Expected values:
// PT
// CT
// CT-TD
// ==================================================
void onArc210ComsecSubmodeChange(char* newValue)
{
    // DCS indication text can pad short modes such as CT with spaces.
    while (*newValue == ' ' || *newValue == '\t') ++newValue;
    strncpy(
        currentComsecSubmode,
        newValue,
        5
    );

    currentComsecSubmode[5] = '\0';

    size_t length = strlen(currentComsecSubmode);
    while (length > 0 &&
        (currentComsecSubmode[length - 1] == ' ' ||
         currentComsecSubmode[length - 1] == '\t' ||
         currentComsecSubmode[length - 1] == '\r' ||
         currentComsecSubmode[length - 1] == '\n'))
        currentComsecSubmode[--length] = '\0';

    // Operational pages, including SATCOM, carry PT/CT even without a frequency.
    if (length > 0) finishAircraftBoot();

    updateRadioDisplay();
}


// ==================================================
// ARC-210 XMIT / RECV CALLBACK
//
// Expected values:
// XMIT
// RECV
// ==================================================
void onArc210XmitRecvChange(char* newValue)
{
    strncpy(
        currentXmitRecv,
        newValue,
        4
    );

    currentXmitRecv[4] = '\0';

    updateRadioDisplay();
}


// ==================================================
// ARC-210 MENU / FSK BUTTON CALLBACKS
//
// DCS-BIOS exports these momentary buttons as 0/1.
// Only react to the pressed state (1), so release does
// not execute the menu action a second time.
// ==================================================
void onArc210MenuButtonChange(unsigned int newValue)
{
    static bool wasPressed = false;
    const bool pressed = (newValue == 1);
    const bool risingEdge = pressed && !wasPressed;
    wasPressed = pressed;
    if (risingEdge && radioOn && radioDisplayPowered && bootStage == BOOT_IDLE)
    {
        onArc210MenuPress();
    }
}

void onArc210XmtRcvButtonChange(unsigned int newValue)
{
    static bool wasPressed = false;
    const bool pressed = (newValue == 1);
    const bool risingEdge = pressed && !wasPressed;
    wasPressed = pressed;
    if (risingEdge && radioOn && radioDisplayPowered && bootStage == BOOT_IDLE)
    {
        onArc210XmtRcvPress();
    }
}

void onArc210UpperLskChange(unsigned int newValue)
{
    static bool wasPressed = false;
    const bool pressed = (newValue == 1);
    const bool risingEdge = pressed && !wasPressed;
    wasPressed = pressed;
    if (risingEdge && radioOn && radioDisplayPowered && bootStage == BOOT_IDLE)
    {
        onArc210UpperLskPress();
    }
}

void onArc210MiddleLskChange(unsigned int newValue)
{
    static bool wasPressed = false;
    const bool pressed = (newValue == 1);
    const bool risingEdge = pressed && !wasPressed;
    wasPressed = pressed;
    if (risingEdge && radioOn && radioDisplayPowered && bootStage == BOOT_IDLE)
    {
        onArc210MiddleLskPress();
    }
}

void onArc210LowerLskChange(unsigned int newValue)
{
    static bool wasPressed = false;
    const bool pressed = (newValue == 1);
    const bool risingEdge = pressed && !wasPressed;
    wasPressed = pressed;
    if (risingEdge && radioOn && radioDisplayPowered && bootStage == BOOT_IDLE)
    {
        onArc210LowerLskPress();
    }
}


// ==================================================
// ARC-210 SECONDARY / FREQUENCY MODE CALLBACK
//
// 0 = ECCM MASTER
// 1 = ECCM
// 2 = PRST
// 3 = MAN
// 4 = MAR
// 5 = 243 GUARD
// 6 = 121.500 GUARD
// ==================================================
void onArc210SecSwChange(unsigned int newValue)
{
    frequencyMode = newValue;

    if (!radioOn)
    {
        blankScreen();
        return;
    }

    if (bootStage != BOOT_IDLE)
    {
        return;
    }

    // All radio rendering goes through the menu-aware update path.
    // drawPREV("") draws PREV and dashes; it is not a clearing operation.
    updateRadioDisplay();

}


// ==================================================
// ARC-210 MASTER SWITCH CALLBACK
//
// 0 = OFF
// 1 = TR-G
// 2 = TR
// 3 = ADF
// 4 = CHG PRST
// 5 = TEST
// 6 = ZERO
// ==================================================
void onArc210MasterChange(unsigned int newValue)
{
    previousMasterSwitch = masterSwitch;
    masterSwitch = newValue;

    // ==================================================
    // FIRST MASTER STATE RECEIVED FROM DCS-BIOS
    // ==================================================
    if (!masterStateInitialized)
    {
        masterStateInitialized = true;

        if (masterSwitch == 0)
        {
            radioOn = false;
            blankScreen();
            return;
        }

        radioOn = true;

        updateRadioDisplay();

        return;
    }

    // ==================================================
    // MASTER SWITCH OFF
    // ==================================================
    if (masterSwitch == 0)
    {
        radioOn = false;
        resetArc210Menu();

        cancelBootSequence();
        blankScreen();

        return;
    }

    // ==================================================
    // RADIO IS POWERED
    // ==================================================
    radioOn = true;

    // ==================================================
    // REAL OFF -> ON TRANSITION
    // ==================================================
    if (
        previousMasterSwitch == 0 &&
        masterSwitch != 0
       )
    {
        resetArc210Menu();
        startBootSequence();
        return;
    }

    // ==================================================
    // DON'T INTERRUPT STARTUP
    // ==================================================
    if (bootStage != BOOT_IDLE)
    {
        return;
    }

    updateRadioDisplay();
}
