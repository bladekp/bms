/*
 * File:   sleep.c
 * Author: bladekp
 *
 * Created on 7 lutego 2017, 21:37
 */

#include "xc.h"
#include "user.h"

void TurnOnSleepingLed(){
    SLEEP_LED = ON;
}

void TurnOffSleepingLed(){
    SLEEP_LED = OFF;
}

void InitSleepModule(void){
    TurnOffSleepingLed();
}

void GoToSleep(void){
    TurnOnSleepingLed();
}

void WakeUp(void){
    TurnOffSleepingLed();
}

