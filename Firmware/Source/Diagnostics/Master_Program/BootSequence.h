#ifndef BOOT_SEQUENCE_H
#define BOOT_SEQUENCE_H

enum BootStage
{
    BOOT_IDLE,
    BOOT_WAITING,
    BOOT_MESSAGE,
    BOOT_INITIALIZING
};

extern BootStage bootStage;

void startBootSequence(bool aircraftPowerRestored = false);
void cancelBootSequence();
void updateBootSequence();
void syncAircraftBootInitializing();
void finishAircraftBoot();
bool isRadioSwitchBootActive();

#endif
