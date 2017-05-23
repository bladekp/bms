/* 
 * File: slave.h   
 * Author: bladekp
 */

#ifndef _SLAVE_H_
#define	_SLAVE_H_

#include <xc.h> 
#include "user.h"

#define BROADCAST_ADDRESS           0x00
#define ADDRESS_COMMAND             0x0F
#define RESET_ADDRESSES_COMMAND     0x0E
#define READ_VOLTAGE_COMMAND        0x00
#define READ_TEMPERATURE_COMMAND    0x01
#define ENABLE_BALLANCER_COMMAND    0x02
#define DISABLE_BALLANCER_COMMAND   0x03

BMS InitSlave(BMS bms_system);

BMS ReadSlaves(BMS bms_system);

void ReadVoltages(void);

void ReadTemperatures(void);

//temp
void sendFrame(uint8_t * buffer);
uint16_t readFrame(uint8_t slave_address);

#endif	/* _SLAVE_H_ */

