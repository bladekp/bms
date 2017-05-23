/******************************************************************************/
/* Reading                                                                    */
/******************************************************************************/

/* Getting started with MPLAB X: http://ww1.microchip.com/downloads/en/DeviceDoc/70151a.pdf         */
/* dsPIC33EPXXXGP50X datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/70000657H.pdf       */
/* Device configuration: http://ww1.microchip.com/downloads/en/DeviceDoc/70000618d.pdf              */
/* Oscillator module: http://ww1.microchip.com/downloads/en/DeviceDoc/70005131a.pdf                 */
/* Watchdog and power saving: http://ww1.microchip.com/downloads/en/DeviceDoc/S9.pdf                */
/* PICkit datasheet: https://www.sparkfun.com/datasheets/Programmers/PICkit_3_User_Guide_51795A.pdf */
/* XC16 User Guide: http://ww1.microchip.com/downloads/en/DeviceDoc/50002071F.pdf                   */
/* ANSI C 89/90 specification: http://www.open-std.org/JTC1/sc22/wg14/www/docs/n1256.pdf            */
/* PPS settings: http://ww1.microchip.com/downloads/en/DeviceDoc/39711b.pdf                         */

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "user.h"
#include "slave.h"


void userDelay(){
    uint8_t i;
    for(i = 0; i<=255; i++) {
        uint8_t j;
        for(j = 0; j<=255; j++){};
    }
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    // initialize application
    //InitApp();
    
    uint8_t *buffer = malloc(1);
    buffer[0] = 65;
    
    while (1)
    {
        sendFrame(buffer);
        
        userDelay(); 
        // check ignition, go to sleep or wake up
        //CheckIgnition();
        
        //GetMeasurements();
        
        //Evaluate();
       
        //DoActions();
    }
    return 0;
}