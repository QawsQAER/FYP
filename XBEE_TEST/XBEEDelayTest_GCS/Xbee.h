#include "main.h"
#ifndef _XBEE_H
#define _XBEE_H

#if _USE_MBED

#include "mbed.h"

#else

#include <stdlib.h>

#endif

//#include "ADDRESS.h"


class Xbee
{
    private:
        Serial *port;
        uint32_t Serial_Num;// the Serial number of current XBEE module;
        uint8_t ID;
    public:
        Xbee(PinName TX, PinName RX, uint32_t Serial_Num = 0x00000000, uint8_t ID = 0);
        ~Xbee();
        void write(char *tran_buff,uint8_t size);
        void read(char * rece_buff,uint8_t size);
        void transmit(uint8_t ID,char * tran_buff, uint8_t size);
        void receive(char * rece_buff,uint8_t size);
        void baud(uint16_t baudrate);
};
#endif
