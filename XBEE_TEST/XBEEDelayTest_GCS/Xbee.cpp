#include "Xbee.h"

//CONSTRUCTOR
Xbee::Xbee(PinName TX,PinName RX, uint32_t Serial_Num, uint8_t ID)
{
    port = new Serial(TX,RX);
    this->Serial_Num = Serial_Num;
    this->ID = ID;
}

//DESTRUCTOR
Xbee::~Xbee()
{
    free(port);
}

void Xbee::write(char *tran_buff,uint8_t size)
{
    uint8_t count = 0;
    //PUTC VERSION
    for(count = 0 ;count < size;count++)
        port->putc(*(tran_buff + count));   
    /*PRINTF VERSION
    port->printf("%s",tran_buff)
    */
}

void Xbee::read(char * rece_buff,uint8_t size)
{
    uint8_t count = 0;
    //GETC version
    for(count = 0;count < size;count++)
        *(rece_buff + count) = port->getc();
}

void Xbee::transmit(uint8_t ID,char * tran_buff, uint8_t size)
{
    this->write((char *)&ID,1);
    this->write(tran_buff,size);
}

void Xbee::receive(char * recv_buff, uint8_t size)
{

}

void Xbee::baud(uint16_t baudrate)
{
    port->baud(baudrate);
    return ;
}