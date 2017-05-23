/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#include "xc.h"

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
#include "sleep.h"
#include "can.h"
#include "sd.h"
#include "slave.h"
#include "lem.h"

/******************************************************************************/
/* Global Variables                                                           */
/******************************************************************************/

//BMS bms_status;
enum SystemStatus status;
BMS BMS_SYSTEM;
                
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void InitApp(void)
{
    InitSleepModule();
    InitCan();
    BMS_SYSTEM = InitSlave(BMS_SYSTEM);
    BMS_SYSTEM = InitLem(BMS_SYSTEM);
    InitMicroSDCad();
    BMS_SYSTEM = ReadSDConfiguration(BMS_SYSTEM);
    
    SLEEP_LED_TRIS = 0;
    ERROR_LED_TRIS = 0;
    BUZZER_LED_TRIS = 0;
        
    status = WORKING; /* Initializing system in WORKING status */
}

void CheckIgnition(void){
    if (IGNITION == OFF && status == WORKING) GoToSleep();
    if (IGNITION == ON && status == SLEEPING) WakeUp();
}

void TurnOnRelay(void){
    RELAY = ON;
}

void TurnOffRelay(void){
    RELAY = OFF;
}

void TurnOnErrorLed(){
    ERROR_LED = ON;
}

void TurnOffErrorLed(){
    ERROR_LED = OFF;
}

void TurnOnBuzzer(){
    BUZZER = ON;
}

void TurnOffBuzzer(){
    BUZZER = OFF;
}

void GetMeasurements(void){
    BMS_SYSTEM = ReadSlaves(BMS_SYSTEM);
    BMS_SYSTEM = ReadLems(BMS_SYSTEM);
}    

void Evaluate(void){
    //calculate soc, soh etc
}

void DoActions(void){
    //open or close relays
}  
