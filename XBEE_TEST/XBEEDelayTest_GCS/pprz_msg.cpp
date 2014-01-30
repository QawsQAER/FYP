#include "pprz_msg.h"


pprz_msg::pprz_msg()
{
	this->_data_ptr = new uint8_t[PPRZ_MSG_MAX_SIZE];
	this->_length = 0;
	this->_pos = 0;
	this->_errorcode = 0;
}

pprz_msg::~pprz_msg()
{
	delete this->_data_ptr;
}


void pprz_msg::pprz_put_byte(uint8_t *ptr)
{
	if(_length + 1 > PPRZ_MSG_MAX_SIZE)
	{
		//SHOULD SET _errorcode
	}
	else
	*(this->_data_ptr + this->_length++) = *ptr;
}

void pprz_msg::pprz_put_2bytes(uint8_t *ptr)
{
	this->pprz_put_byte(ptr);
	this->pprz_put_byte(ptr + 1);
}

void pprz_msg::pprz_put_4bytes(uint8_t *ptr)
{
	this->pprz_put_2bytes(ptr);
	this->pprz_put_2bytes(ptr + 2);
}

uint8_t pprz_msg::pprz_read_byte()
{
	if(this->_pos >= this->_length)
	{
		//set error code when there's no data and the user want to read
		return 0;
	}
	else
		return *(this->_data_ptr + this->_pos++); 
}

uint16_t pprz_msg::pprz_read_2bytes()
{
	return this->pprz_read_byte() << 8 + this->pprz_read_byte();
}

uint32_t pprz_msg::pprz_read_4bytes()
{
	return this->pprz_read_2bytes() << 16 + this->pprz_read_2bytes();
}

void pprz_msg::show_hex()
{
	uint16_t count = 0;
	while(count < this->_length)
	{
		printf("%02x ",*(this->_data_ptr + count++));
	}
	printf("\n");
}

























