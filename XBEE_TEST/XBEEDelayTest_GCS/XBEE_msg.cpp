/*
	THIS FILE IS THE IMPLEMENTATION OF XBEE_msg:: CLASS
	WRITTEN BY EDWARD HUANG
*/
#include "XBEE_msg.h"

XBEE_msg::XBEE_msg()
{
	_errorcode = 0;
	_length_HI = 0;
	_length_LO = 0;
	_API_type = 0;
	_CheckSum = 0;
	_recv_CheckSum = 0;
	_frameptr = NULL;
	frame_length = 0;		
}

XBEE_msg::~XBEE_msg()
{
	#if _DEBUG
	printf("~XBEE_msg(): pointer is %p\n",_frameptr);
	#endif
	//if(_frameptr != NULL)
	//delete _frameptr;
	delete _frameptr;
}

void XBEE_msg::set_frameptr(uint8_t *ptr)
{_frameptr = ptr;}

uint8_t * XBEE_msg::get_frameptr()
{return _frameptr;}

//TODO implement this checksum algorithm
void XBEE_msg::set_CheckSum()
{
	uint8_t ck = 0;
	uint16_t count = 0;
	for(count = 0;count <= frame_length;count++)
	{
		ck+=*(_frameptr + count);
		#if _DEBUG_CHECKSUM
		printf("At count [%d], add [%x] ck is [%x], recv_ck is [%x]\n",count,*(_frameptr + count),ck,_recv_CheckSum);
		#endif
	}
	_CheckSum = ck;
}

uint8_t XBEE_msg::get_CheckSum()
{return _CheckSum;}

void XBEE_msg::set_errorcode(uint8_t errorcode)
{_errorcode = errorcode;}

void XBEE_msg::set_length_LO(uint8_t length_LO)
{_length_LO = length_LO;}

void XBEE_msg::set_length_HI(uint8_t length_HI)
{_length_HI = length_HI;}

void XBEE_msg::set_API_type(uint8_t API_type)
{_API_type = API_type;}

void XBEE_msg::set_recv_CheckSum(uint8_t recv_CheckSum)
{_recv_CheckSum = recv_CheckSum;}

void XBEE_msg::show_hex()
{
	printf("%x ", START_BYTE);
	printf("%x ", _length_HI);
	printf("%x ", _length_LO);
	uint16_t count = 0;
	while(count <= frame_length)
		printf("%x ",*(_frameptr + count++));
	printf("\n");	

}

//frame length is the length between the length and the checksum
void XBEE_msg::set_frame_length()
{frame_length = (_length_HI << 8) + _length_LO;}

uint16_t XBEE_msg::get_frame_length()
{return frame_length;}

uint8_t* XBEE_msg::get_recv_packet_data_ptr()
{return (_frameptr + FRAME_RECV_DATA_OFFSET);}

uint16_t XBEE_msg::get_recv_packet_data_length()
{return (frame_length - FRAME_RECV_DATA_OFFSET + 1);}

uint64_t XBEE_msg::get_recv_source_addr()
{
	uint32_t temp_hi = 0;
	uint32_t temp_lo = 0;
	temp_hi = *(_frameptr + FRAME_RECV_ADDR_OFFSET) << 24;
	temp_hi += *(_frameptr + FRAME_RECV_ADDR_OFFSET + 1) << 16;
	temp_hi += *(_frameptr + FRAME_RECV_ADDR_OFFSET + 2) << 8;
	temp_hi += *(_frameptr + FRAME_RECV_ADDR_OFFSET + 3);
	
	temp_lo = *(_frameptr + FRAME_RECV_ADDR_OFFSET + 4) << 24;
	temp_lo += *(_frameptr + FRAME_RECV_ADDR_OFFSET + 5) << 16;
	temp_lo += *(_frameptr + FRAME_RECV_ADDR_OFFSET + 6) << 8;
	temp_lo += *(_frameptr + FRAME_RECV_ADDR_OFFSET + 7);
	//printf("hi [%08x],lo[%08x]\n",temp_hi,temp_lo);
	uint64_t temp = 0;
 	memcpy(&temp,&temp_hi,sizeof(uint32_t));
	memcpy((uint8_t *)&temp + sizeof(uint32_t),&temp_lo,sizeof(uint32_t));
	return 	temp;
}

uint16_t XBEE_msg::get_recv_source_net_addr()
{return ((*(_frameptr + FRAME_RECV_NET_ADDR_OFFSET)) << sizeof(uint8_t)) + (*(_frameptr + FRAME_RECV_NET_ADDR_OFFSET + sizeof(uint8_t)));}

uint8_t XBEE_msg::get_recv_option()
{return *(_frameptr + FRAME_RECV_OPTION_OFFSET);}

void XBEE_msg::detect_esc()
{frame_length--;}



















