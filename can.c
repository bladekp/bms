/*
 * File:   can.c
 * Author: bladekp
 *
 * Created on 7 lutego 2017, 21:34
 */

#include "xc.h"
#include "can.h"

void InitCan(void){
    RPINR26bits.C1RXR = RPI44;  // Connect the C1RX input to RPI44
    RPOR2bits.RP39R = C1TX;     // Assign C1TX To Pin RP39 
}
