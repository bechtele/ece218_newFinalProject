//=====[Libraries]============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "display.h"
#include "brake_light.h"
#include "speed_sensor.h"
#include "string.h"

#include "user_interface.h"
#include "turn_signal.h"

//=====[Declaration of private defines]========================================

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);


//=====[Declaration of private data types]=====================================


//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================
static void displaySystemInit();
static void turnSignalDisplay();
static void speedometerDisplay();
static void brakeDisplay();

//=====[Implementations of public functions]===================================

void userInterfaceInit() {
    //Position of SPEED: 
    displayCharPositionWrite(0,0);
    displayStringWrite("SPEED: 00.0 MPH");

    //TURN SIGNAL
    displayCharPositionWrite(0,1);
    displayStringWrite("TS:");

    //BRAKE
    displayCharPositionWrite(9,1);
    displayStringWrite("BRK:");
}

void userInterfaceUpdate() {
    turnSignalDisplay();
    speedometerDisplay();
    brakeDisplay();
}


//=====[Implementations of private functions]==================================

static void turnSignalDisplay() {
     displayCharPositionWrite(3,1);
    if(readLeftTurnSignal()){
        displayStringWrite("LEFT ");
    }
    else if(readRightTurnSignal()){
        displayStringWrite("RIGHT");
    } else {
        displayStringWrite("OFF  ");
    }
}

static void speedometerDisplay() {
     displayCharPositionWrite(7,0);
    int speed = (int)(readSpeed()*10);
    int rightDecimal = speed%10;
    int leftDecimal = (speed-rightDecimal)/10;
    char buffer[7];
    if (leftDecimal < 10) {
        sprintf(buffer, "0%d.%d", leftDecimal, rightDecimal);
    } else{
        sprintf(buffer, "%d.%d", leftDecimal, rightDecimal);
    }
    displayStringWrite(buffer);
}

static void brakeDisplay() {
    displayCharPositionWrite(13,1);
    if(brakeLightUpdate()){
        displayStringWrite("ON ");
    }
    else{
        displayStringWrite("OFF");
    }
}
