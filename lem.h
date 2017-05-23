/* 
 * File: lem.h 
 * Author: bladekp
 */

#ifndef _LEM_H_
#define	_LEM_H_

#include <xc.h>
#include "user.h"

BMS InitLem(BMS bms_system);

BMS ReadLems(BMS bms_system);

void ReadCurrents(void);

#endif	/* _LEM_H_ */

