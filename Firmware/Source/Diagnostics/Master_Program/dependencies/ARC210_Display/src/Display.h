#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>


// ==================================================
// DISPLAY CONTROL
// ==================================================
void initializeDisplay();
void blankScreen();
void showInfoScreen();
void refreshDisplay();


// ==================================================
// COMPLETE SCREENS
// ==================================================
void showPowerUpScreen();
void showInitializingScreen();
void showUnavailableScreen();
void showMenuScreen();

// HQ menu pages
void showHQMenusScreen();
void showOperDateLoadScreen();
void setOperDateValue(const char* value);
void showVerifyWodMwodScreen();
void showHQWodLoadScreen();
void showHQWodEraseScreen();
void showHQFmtLoadScreen();
void drawHQLoadNumber(const char* value, bool formatPage);
void setHQFrequencyValue(const char* value);
void showHQMore1Screen();
void showHQMore2Screen();
void showHQMore3Screen();
void showHQMore4Screen();
void showHQMore5Screen();
void showHQMore6Screen();
void showHQMore7Screen();
void showHQMore8Screen();
void showHQMore9Screen();
void showHQMore10Screen();
void showHQMore11Screen();
void showHQMore12Screen();
void showHQMore13Screen();
void showHQMore14Screen();
void showHQMore15Screen();
void showHQMore16Screen();
void showHQMore17Screen();
void showHQMore18Screen();

// RADIO SETTINGS menu pages
void showRadioSettingsScreen();
void showRadioMore1Screen();
void showRadioMore2Screen();
void showRadioMore3Screen();
void showRadioMore4Screen();
void showRadioMore5Screen();
void showRadioMore6Screen();

// RADIO SETTINGS submenus
void showRadioIdNumbersScreen();
void showRadioPreset2630Screen(bool halfDuplex);
void showRadioDamaChannelsScreen(bool ch41To50);
void showRadioBeepEnableScreen(bool disabled);
void showRadioUserDataWidebandScreen();
void showRadioUserData188144Screen();
void showRadioUserDataSynchronousScreen();
void showRadioUserDataAsyncScreen();
void showRadioUserDataExternalClockScreen();
void showRadioUserDataInternalClockScreen();
void showRadioSwitchTestScreen();
void showRadioSwitchTestMenuScreen();
void showRadioSwitchTestXmtRcvScreen();
void showRadioEnterKeyScreen(bool disabled);

// COMSEC menu pages
void showComsecMenuScreen(bool damaSatcomSelected);
void showComsecLoadScreen(bool dama = true);
void showComsecLosMore1Screen(const char* dataMode);
void showComsecLosMore2Screen(bool diphase = false);
void showComsecLosMore3Screen(bool cvsd12k = false);
void showComsecLosMore4Screen(bool analogData = false);
void showComsecLosMore5Screen(const char* dataMode);
void showComsecLosMore6Screen(bool diphase = false);
void showComsecLosMore7Screen(bool cvsd12k = false);
void showComsecLosMore8Screen(const char* dataMode);
void showComsecDamaMoreScreen();
void showComsecDamaDataScreen();
void showComsecDamaRate300Screen();
void showComsecKg84RateScreen(const char* rate = "300");

void showGuard243Screen(const char* modulation);
void showGuard121Screen(const char* modulation);

void drawStaticGuardHeader(const char* band);


// ==================================================
// NORMAL / MAN FREQUENCY SCREEN
// ==================================================
void showFrequencyScreen(
    const char* frequency,
    const char* modulation,
    const char* previousFrequency,
    const char* comsecSubmode
);


// ==================================================
// PRESET SCREEN
// ==================================================
void showPresetScreen(
    const char* activeChannel,
    const char* frequency,
    const char* modulation,
    const char* comsecSubmode,
    unsigned int encryptionNumber
);


// ==================================================
// REUSABLE / COMMON DISPLAY ELEMENTS
//
// Implemented in DisplayCommon.cpp
// ==================================================
void drawPREV(const char* previousFrequency);
void drawLoad();

void drawRT1();

void drawKY58();
void drawKY58Status(const char* status);

void drawComsecSubmode(const char* mode);

void drawAMFM(const char* mode);

void drawFrequencyValue(const char* frequency);

void drawBandMode(const char* frequency);

void drawXmitRecv(const char* mode);

void drawGuard(bool enabled);

void drawDAMA();
void drawADF();


// ==================================================
// PRESET-ONLY DISPLAY ELEMENTS
//
// Implemented in Display.cpp
// ==================================================
void drawPresetChannel(const char* channel);
void drawEncryptionNumber(unsigned int encryptionNumber);
void setRadioKyLabel(const char* label);
void flushDisplay();


// ==================================================
// OTHER DISPLAY ELEMENTS
// ==================================================
void drawUnavailableText();


#endif
