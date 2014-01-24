#include "Xbee.h"

//CONSTRUCTOR
Xbee::Xbee(int fd,uint32_t Serial_Num_HI, uint32_t Serial_Num_LO,  uint8_t ID)
{
	this->fd = fd;
	this->Serial_Num_HI = Serial_Num_HI;
	this->Serial_Num_LO = Serial_Num_LO;
	this->ID = ID;
}

//DESTRUCTOR
Xbee::~Xbee()
{
	//for integrity
}

void Xbee::write(char *tran_buff,uint8_t size)
{
	uint8_t count = 0;
	/*
	for(count = 0 ;count < size;count++)
	port->putc(*(tran_buff + count));
	*/
	write(fd,tran_buff,size); 
}

void Xbee::read(char * rece_buff,uint8_t size)
{
	uint8_t count = 0;
	//GETC version
	/*
	for(count = 0;count < size;count++)
        *(rece_buff + count) = port->getc();
	*/
	read(fd,rece_buff,size);
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
