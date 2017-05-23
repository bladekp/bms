/*
 * File:   slave.c
 * Author: bladekp
 *
 * Created on 7 lutego 2017, 21:35
 */
#include <stdint.h> 
#include "xc.h"
#include "mcc_generated_files/uart2.h"
#include "slave.h"
#include "user.h"
#include "crc.h"

void sendFrame(uint8_t * buffer){
    UART2_TRANSFER_STATUS status;
    uint8_t numbytes = 2;
    // Pre-initialize myBuffer with MY_BUFFER_SIZE bytes of valid data.
    int i = 0;
    while( i < numbytes)
    {
        status = UART2_TransferStatusGet ( ) ;
        if (status & UART2_TRANSFER_STATUS_TX_EMPTY)
        {
            i += UART2_WriteBuffer ( buffer + i, numbytes - i )  ;
            if(i < numbytes)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            continue;
        }
    }
    free(buffer);
}

uint16_t readFrame(uint8_t slave_address){
    uint8_t buffer_size = 3;
    uint8_t myBuffer[buffer_size];
    unsigned int numBytes;
    UART2_TRANSFER_STATUS status ;

    // Pre-initialize myBuffer with MY_BUFFER_SIZE bytes of valid data.
    numBytes = 0;
    while( numBytes < buffer_size)
    {
        status = UART2_TransferStatusGet ( ) ;
        if (status & UART2_TRANSFER_STATUS_RX_FULL)
        {
            numBytes += UART2_ReadBuffer( myBuffer + numBytes, buffer_size - numBytes )  ;
            if(numBytes < buffer_size)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            continue;
        }
    }
    
    uint16_t data = (myBuffer[1] << 4) + ((myBuffer[0] & 0xF0) >> 4);
    uint32_t frame = (myBuffer[0] << 12) + data;
    uint8_t crcMine = calculateCRC(frame, 20);
    uint8_t crcTheirs = (myBuffer[2] & 0x0F);
    
    if (myBuffer[0] != slave_address){
        //addresses not equals
    }
    if (crcMine != crcTheirs){
        //crcs not equals
    }
    
    return data;
}

/*
 * @param address - 8bit device address 0x00=broadcast 
 * @param command - 4bit (minor) command
 */
uint8_t* prepareFrame(uint8_t address, uint8_t command){
    uint16_t frame = (address * 16) + command;
    uint8_t crc = calculateCRC(frame, 12);
    uint8_t *buffer = malloc(2);
    buffer[0] = address;
    buffer[1] = (command * 16) + crc;
    return buffer;
}

BMS AddressSlaves(BMS bms_system){
    //TODO: addressing
    //sendFrame(prepareFrame(BROADCAST_ADDRESS, ADDRESS_COMMAND));
    
    uint8_t i;
    for(i = 0; i<SLAVE_COUNT; i++){
        bms_system.slaves[i].address = i;
    }
    
    return bms_system;
}

BMS InitSlave(BMS bms_system){
    bms_system = AddressSlaves(bms_system);
    return bms_system;
}

BMS ReadSlaves(BMS bms_system){
    
    uint8_t i;
    for(i = 0; i<SLAVE_COUNT; i++){
        sendFrame(prepareFrame( i, READ_VOLTAGE_COMMAND));
        uint16_t voltage = readFrame(bms_system.slaves[i].address);
        bms_system.slaves[i].voltage = voltage;
        
        sendFrame(prepareFrame( i, READ_VOLTAGE_COMMAND));
        uint16_t temperature = readFrame(bms_system.slaves[i].address);
        bms_system.slaves[i].temperature = temperature;
    }
    
    return bms_system;
}

void ReadVoltages(void){
    
}

void ReadTemperatures(void){
    
}
