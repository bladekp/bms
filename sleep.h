/* 
 * File: sleep.h  
 * Author: bladekp
 */

#ifndef _SLEEP_H_
#define	_SLEEP_H_

#include <xc.h> 

void InitSleepModule(void);   /* Sleeping initialization */
void GoToSleep(void);   /* Going to sleep mode */
void WakeUp(void);      /* Waking up from sleep mode */

#endif	/* _SLEEP_H_ */

