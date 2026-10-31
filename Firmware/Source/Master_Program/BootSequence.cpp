#include <Arduino.h>

#include "BootSequence.h"
#include "Arc210State.h"
#include "DcsCallbacks.h"
#include <Display.h>


BootStage bootStage = BOOT_IDLE;
static unsigned long startupPictureDuration = 0;
static bool followAircraftBoot = false;
static bool aircraftInitializingSeen = false;
static bool aircraftReadySeen = false;
static constexpr unsigned long MIN_AIRCRAFT_STAGE_MS = 250;


// ==================================================
// START BOOT SEQUENCE
// ==================================================
void startBootSequence(bool aircraftPowerRestored)
{
    followAircraftBoot = aircraftPowerRestored;
    aircraftInitializingSeen = false;
    aircraftReadySeen = false;
    if (aircraftPowerRestored)
    {
        // DCS is already displaying its loader when this export arrives.
        // Skip only the aircraft-power splash, preserving radio-switch startup.
        bootStage = BOOT_MESSAGE;
        powerUpStartTime = millis();
        showPowerUpScreen();
        return;
    }
    bootStage = BOOT_WAITING;

    startupPictureDuration = POWER_ON_DELAY;

    powerUpStartTime = millis();

    // Show project information during the selected initial delay.
    // The real ARC-210 POWER UP LOADER and INITIALIZING timings
    // remain unchanged.
    showInfoScreen();
}


// ==================================================
// CANCEL BOOT SEQUENCE
// ==================================================
void cancelBootSequence()
{
    followAircraftBoot = false;
    bootStage = BOOT_IDLE;

    blankScreen();
}


// ==================================================
// UPDATE BOOT SEQUENCE
// ==================================================
void syncAircraftBootInitializing()
{
    if (!followAircraftBoot) return;
    aircraftInitializingSeen = true;
}

void finishAircraftBoot()
{
    if (!followAircraftBoot) return;
    aircraftReadySeen = true;
}

bool isRadioSwitchBootActive()
{
    return bootStage != BOOT_IDLE && !followAircraftBoot;
}

void updateBootSequence()
{
    unsigned long now = millis();


    // ==================================================
    // STAGE 1
    // Firmware version and aircraft information screen during the existing
    // initial power-on delay
    // ==================================================
    if (bootStage == BOOT_WAITING)
    {
        if (now - powerUpStartTime >= startupPictureDuration)
        {
            showPowerUpScreen();

            bootStage = BOOT_MESSAGE;

            powerUpStartTime = now;
        }

        return;
    }


    // ==================================================
    // STAGE 2
    // POWER UP LOADER screen
    // ==================================================
    if (bootStage == BOOT_MESSAGE)
    {
        if (followAircraftBoot)
        {
            if ((aircraftInitializingSeen || aircraftReadySeen) &&
                now - powerUpStartTime >= MIN_AIRCRAFT_STAGE_MS)
            {
                showInitializingScreen();
                bootStage = BOOT_INITIALIZING;
                powerUpStartTime = now;
            }
            return;
        }
        if (now - powerUpStartTime >= BOOT_SCREEN_TIME)
        {
            // Immediately switch to INITIALIZING
            // No blank pause between screens
            showInitializingScreen();

            bootStage = BOOT_INITIALIZING;

            powerUpStartTime = now;
        }

        return;
    }


    // ==================================================
    // STAGE 3
    // INITIALIZING RT1 screen
    // ==================================================
    if (bootStage == BOOT_INITIALIZING)
    {
        if (followAircraftBoot)
        {
            if (aircraftReadySeen && now - powerUpStartTime >= MIN_AIRCRAFT_STAGE_MS)
            {
                followAircraftBoot = false;
                bootStage = BOOT_IDLE;
                updateRadioDisplay();
            }
            return;
        }
        if (now - powerUpStartTime >= INITIALIZING_TIME)
        {
            bootStage = BOOT_IDLE;


            // Radio may have been switched OFF
            if (!radioOn || !radioDisplayPowered)
            {
                blankScreen();
                return;
            }


            // Move to live ARC-210 display
            if (dcsConnected)
            {
                updateRadioDisplay();
            }
            else
            {
                blankScreen();
            }
        }

        return;
    }
}
