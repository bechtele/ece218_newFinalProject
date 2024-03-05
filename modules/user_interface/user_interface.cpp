//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "display.h"
#include "brake_light.h"

#include "user_interface.h"
#include "turn_signal.h"

//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================


//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================
static void displaySystemInit();
static void LCDUpdate();
static void LCDInit();

//=====[Implementations of public functions]===================================

void userInterfaceInit() {
    LCDInit();
}

void userInterfaceUpdate() {
    LCDUpdate();
    turnSignalUpdate();
}


//=====[Implementations of private functions]==================================

static void LCDInit(){
    //Position of SPEED: 
    displayCharPositionWrite(0,0);
    displayStringWrite("SPEED:   MPH");

    //TURN SIGNAL
    displayCharPositionWrite(0,1);
    displayStringWrite("TS:");

    //BRAKE
    displayCharPositionWrite(9,1);
    displayStringWrite("BRK:");
}

static void LCDUpdate(){
    //Update Speed
    displayCharPositionWrite(7,0);
    displayStringWrite("99");

    //Update Turn Signal
    displayCharPositionWrite(3,1);
    if(readLeftTurnSignal()){
        displayStringWrite("LEFT ");
    }
    else if(readRightTurnSignal()){
        displayStringWrite("RIGHT");
    } else {
        displayStringWrite("OFF  ");
    }
    //displayStringWrite()

    //Update Brake
    displayCharPositionWrite(13,1);
    if(brakeLightUpdate()){
        displayStringWrite("ON ");
    }
    else{
        displayStringWrite("OFF");
    }

}
