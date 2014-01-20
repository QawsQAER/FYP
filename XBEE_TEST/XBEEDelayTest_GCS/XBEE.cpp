#include "XBEE.h"

Xbee::Xbee(PinName TX,PinName RX, uint32_t Serial_Num)
{
    port = new Serial(TX,RX);
    this->Serial_Num = Serial_Num;
}

void Xbee::write(char *tran_buff,uint8_t size)
{
    
}

void Xbee::read(char * rece_buff,uint8_t size)
{
}