/* 
 * File: microSDcard.h  
 * Author: bladekp
 */

#ifndef _MICROSDCARD_H_
#define	_MICROSDCARD_H_

#include <xc.h> 
#include "user.h"

BMS ReadSDConfiguration(BMS bms_system);

void InitMicroSDCad(void);

uint8_t ReadBMSConfiguration();

#endif	/* _MICROSDCARD_H_ */

