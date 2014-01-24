#include "main.h"
#ifndef _XBEE_H
#define _XBEE_H

#if _USE_MBED

#include "mbed.h"

#else
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Serial.h"

#endif

//#include "ADDRESS.h"


class Xbee
{
    private:
	int fd;// The file descriptor for the port.
        uint32_t Serial_Num_HI;
	uint32_t Serial_Num_LO;// the Serial number of current XBEE module;
        uint8_t ID;
	uint8_t recv_buff[MB];
    public:
        Xbee(int fd,uint32_t Serial_Num_HI = 0x00000000,uint32_t Serial_Num_LO = 0x0000ffff, uint8_t ID = 0);
        ~Xbee();
        void write(char *tran_buff,uint8_t size);
        void read(char * rece_buff,uint8_t size);
        void transmit(uint8_t ID,char * tran_buff, uint8_t size);
        void receive(char * rece_buff,uint8_t size);
        void baud(uint16_t baudrate);
};
#endif
