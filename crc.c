/*
 * File:   crc.c
 * Author: bladekp
 *
 * Created on 27 marca 2017, 20:55
 */


#include "xc.h"
#include <stdint.h> 

uint8_t calculateCRC(uint32_t data, uint8_t data_len){
	uint8_t polynomial = 0xD8;
	uint32_t remainder = data;
	uint8_t bit;
	for (bit = data_len; bit > 0; --bit){
		if (remainder & 0x80){
			remainder ^= polynomial;
		}
		remainder = (remainder <<1);
	}
	return (remainder >> 4);
}