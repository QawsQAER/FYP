#ifndef _XBEE_H
#define _XBEE_H
#include "mbed.h"

class Xbee
{
    private:
        Serial *port;
        uint32_t Serial_Num;// the Serial number of current XBEE module;
        void write(char *tran_buff,uint8_t size);
        void read(char * rece_buff,uint8_t size);
    public:
        Xbee(PinName Tx, PinName Rx, uint32_t Serial_Num);
        
        void Transmit(char * tran_buff, uint8_t size);
        void Receive(char * rece_buff,uint8_t size);
};
#endif