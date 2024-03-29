//=====[Libraries]=============================================================
#include "arm_book_lib.h"
#include "brake_light.h"
#include "led_driver.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

DigitalIn leftBrakeButton(PC_8);
DigitalIn rightBrakeButton(PC_9);

//=====[Declaration and initialization of public global objects]===============


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void brakeLightInit() { 
    leftBrakeButton.mode(PullDown);
    rightBrakeButton.mode(PullDown);
}

//This function turns the brake leds on or off depending on the state of the brake buttons
bool brakeLightUpdate() { 
    bool brakeLightStatus = leftBrakeButton || rightBrakeButton;
    if (brakeLightStatus) {
        brakeLightOn();
    } else {
        brakeLightOff();
    }
    return brakeLightStatus;
}
//=====[Implementations of private functions]==================================
