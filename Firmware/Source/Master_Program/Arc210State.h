#ifndef ARC210_STATE_H
#define ARC210_STATE_H

extern const unsigned long INITIALIZING_TIME;
extern const unsigned long INIT_START_DELAY;
extern const unsigned long POWER_ON_DELAY;
extern const unsigned long BOOT_SCREEN_TIME;

extern unsigned int frequencyMode;
extern unsigned int masterSwitch;
extern unsigned int previousMasterSwitch;
extern unsigned int currentEncryptionNumber;

extern bool dcsConnected;
extern bool radioOn;
extern bool radioDisplayPowered;
extern bool waitingToBoot;
extern bool powerUpActive;

extern unsigned long powerUpStartTime;

extern char currentFrequency[8];
extern char previousFrequency[8];
extern char currentModulation[3];
extern char currentComsecSubmode[6];
extern char currentActiveChannel[3];
extern char currentXmitRecv[5];

#endif
