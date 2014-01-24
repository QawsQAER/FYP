#include "XBEE.h"

//CONSTRUCTOR
XBEE::XBEE(int fd,uint32_t Serial_Num_HI, uint32_t Serial_Num_LO,  uint8_t ID)
{
	this->fd = fd;
	this->Serial_Num_HI = Serial_Num_HI;
	this->Serial_Num_LO = Serial_Num_LO;
	this->ID = ID;
}

//DESTRUCTOR
XBEE::~XBEE()
{
	//for integrity
}

void XBEE::XBEE_write(uint8_t *tran_buff,uint8_t size)
{
	write(this->fd,(void *)tran_buff,size); 
}

uint32_t XBEE::XBEE_read(uint8_t * rece_buff,uint32_t size)
{
	return read(this->fd,(void *)rece_buff,size);
}

void XBEE::XBEE_transmit(uint8_t ID,uint8_t * tran_buff, uint8_t size)
{
    this->XBEE_write((uint8_t *)&ID,1);
    this->XBEE_write(tran_buff,size);
}

void XBEE::XBEE_receive(uint8_t * recv_buff, uint8_t size)
{

}

void XBEE::XBEE_set_baud(uint16_t baudrate)
{
	this->baudrate = baudrate;
	return ;
}

void XBEE::XBEE_read_into_recv_buff()
{
	uint32_t byte_count = this->XBEE_read(this->recv_buff + this->recv_pos,XBEE_BUFF_SIZE/2);
	this->recv_pos+=byte_count;
}

void XBEE::XBEE_parse_XBEE_msg()
{
	uint32_t current = 0, offset_begin = 0;
	uint8_t state = 0;
	XBEE_msg * msg_p = NULL;
	while(current < recv_pos)
	{
		switch(state)
		{
			case 0: //not yet detect a message
				if(recv_buff[current] == 0x7E])
				{
					if(msg_p == NULL)
					{
					//detect a new message
					offset_begin = current;
					msg_p = new XBEE_msg();
					//enter next state if a message is detected
					state++;
					}
					else
					{
						//0x7E inside a message
						//TODO: define error code
						msg_p->set_errorcode(0);
						msg.push(msg_p);
						msg_p = NULL;
					}
					current++;
				}
				break;
			case 1://reading length_HI
				msg_p->set_length_HI(recv_buff[current++]);
				//enter next state to read length_LO
				state++;
				break;	
		}	
	}
}














