#include "main.h"
#ifndef _XBEE_H
#define _XBEE_H

#if _USE_MBED

#include "mbed.h"

#else
//for interaction with uer
#include <stdio.h>

//for memset() and uint8_t
#include <stdlib.h>
//for read() and write()
#include <unistd.h>
#include <queue>
#include "XBEE_msg.h"
#include "Serial.h"

#endif

//#include "ADDRESS.h"
#define XBEE_BUFF_SIZE 1 * MB

class XBEE
{
    private:
	int fd;// The file descriptor for the port.
        uint32_t Serial_Num_HI;
	uint32_t Serial_Num_LO;// the Serial number of current XBEE module;
        uint8_t ID;
	uint8_t	tran_buff[XBEE_BUFF_SIZE];
	uint8_t recv_buff[XBEE_BUFF_SIZE];
	uint32_t tran_pos;
	uint32_t recv_pos;
	uint16_t baudrate;
	std::queue<XBEE_msg *> msg;
    public:
        XBEE(int fd,uint32_t Serial_Num_HI = 0x00000000,uint32_t Serial_Num_LO = 0x0000ffff, uint8_t ID = 0);
        ~XBEE();
        void XBEE_write(uint8_t *tran_buff,uint8_t size);
        uint32_t XBEE_read(uint8_t * rece_buff,uint32_t size);
        void XBEE_transmit(uint8_t ID,uint8_t * tran_buff, uint8_t size);
        void XBEE_receive(uint8_t * rece_buff,uint8_t size);
        void XBEE_set_baud(uint16_t baudrate);
	void XBEE_read_into_recv_buff();
	void XBEE_parse_XBEE_msg();
	void XBEE_show_msg();
	void XBEE_show_recv_buff();
};
#endif
