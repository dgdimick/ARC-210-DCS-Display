#include <Arduino.h>

#include "Arc210State.h"

// ==================================================
// DCS / RADIO STATUS
// ==================================================
bool dcsConnected = false;
bool radioOn = false;
bool radioDisplayPowered = true; // Refined by the exported RT indication.

// ==================================================
// STARTUP STATUS
// ==================================================
bool waitingToBoot = false;
bool powerUpActive = false;

// ==================================================
// MASTER SWITCH
// ==================================================
unsigned int masterSwitch = 0;
unsigned int previousMasterSwitch = 0;

// ==================================================
// SECONDARY / FREQUENCY MODE SWITCH
// ==================================================
unsigned int frequencyMode = 3;

// ==================================================
// FREQUENCY
// ==================================================
char currentFrequency[8] = "---.---";
char previousFrequency[8] = "---.---";

// ==================================================
// MODULATION
// ==================================================
char currentModulation[3] = "AM";

// ==================================================
// COMSEC SUBMODE
// ==================================================
char currentComsecSubmode[6] = "PT";

// ==================================================
// PRESET CHANNEL
// ==================================================
char currentActiveChannel[3] = "01";

// ==================================================
// KY-58 ENCRYPTION NUMBER
// ==================================================
unsigned int currentEncryptionNumber = 1;

// ==================================================
// XMIT / RECV
//
// Blank until DCS-BIOS sends the actual value.
// ==================================================
char currentXmitRecv[5] = "";

// ==================================================
// BOOT TIMER
// ==================================================
unsigned long powerUpStartTime = 0;

// ==================================================
// BOOT TIMING
// ==================================================
const unsigned long POWER_ON_DELAY = 2750;
const unsigned long BOOT_SCREEN_TIME = 3150;
const unsigned long INIT_START_DELAY = 100;
const unsigned long INITIALIZING_TIME = 3000;
