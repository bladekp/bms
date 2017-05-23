/*
 * File:   lem.c
 * Author: bladekp
 *
 * Created on 7 lutego 2017, 21:35
 */

#include "xc.h"
#include "mcc_generated_files/i2c1.h"
#include "user.h"

BMS AddressLems(BMS bms_system){
    //TODO: addressing
    
    uint8_t i;
    for(i = 0; i<LEM_COUNT; i++){
        bms_system.lems[i].address = i;
    }
    
    return bms_system;
}

BMS InitLem(BMS bms_system){
    bms_system = AddressLems(bms_system);
    return bms_system;
}

BMS ReadLems(BMS bms_system){
    return bms_system;
}

void ReadCurrents(void){
    
}