#include <stdlib.h>
#include <stdio.h>
#include <string>
//for O_RDWR, O_NOCITTY, O_SYNC those MACRO
#include <fcntl.h>
#include "Serial.h"
#include "XBEE.h"

int main(int argc, char ** argv)
{
	char portname[32];
	if(argc < 2)
	{
		/*
		printf("Error: Invalid number of parameters\n");
		printf("Usage: ./test [name of the ttyUSBX]\n");
		return 0;
		*/
		printf("Warning: Using default port /dev/ttyUSB1\n");
		strcpy(portname,"/dev/ttyUSB1");
	}
	else
		strcpy(portname,argv[1]);
	 
	printf("name of device %s\n",portname);
	#if _DEBUG
		printf("!!!DEBUG MODE\n");
	#endif
	#if _DEBUG_XBEE_parse_XBEE_msg
		printf("!!!DEBUGING XBEE_parse_XBEE_msg()\n");
	#endif
	int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		return 0;
	}
	set_interface_attribs(fd,B57600,0);
	set_blocking(fd,0);
	XBEE xbee_coor(fd,0x00000000,0x0000ffff,0);
	//char dummy[32];
	const char data[] = "hello A!";  
	uint8_t *frameptr = new uint8_t[512];
	uint32_t addr_hi = 0x0013a200;
	uint32_t addr_lo = 0x409c278a;
	uint8_t net_addr_hi = 0xFF;
	uint8_t net_addr_lo = 0xFE;
	uint8_t radius = 0x00;
	uint8_t option = 0x00;
	XBEE_msg msg;
        msg.set_frameptr(frameptr);
	*(frameptr) = 0x10;
	*(frameptr + 1) = 0x00;
	msg.set_tran_dest_addr_HI(addr_hi);
	msg.set_tran_dest_addr_LO(addr_lo);
	msg.set_tran_net_dest_addr_HI(net_addr_hi);
	msg.set_tran_net_dest_addr_LO(net_addr_lo);
	msg.set_tran_radius(radius);
	msg.set_tran_option(option);
	msg.set_tran_data((uint8_t *)data,strlen(data) + 1);
	uint16_t length = (14 + strlen(data) + 1);
	uint8_t length_hi = length >> 8;
	uint8_t length_lo = (length << 8 ) >> 8;
	printf("length_lo is %d\n",length_lo);
	msg.set_length_HI(length_hi);
	msg.set_length_LO(length_lo);
	msg.set_frame_length();
	printf("length should be %d\n",msg.get_frame_length());
	msg.set_CheckSum();
	printf("msg :");
	msg.show_hex();
	
	XBEE_msg msg1;
	msg1.set_frameptr(new uint8_t[512]);
	char data2[] = "???";
	msg1.set_tran_packet(addr_hi,addr_lo,net_addr_hi,net_addr_lo,(uint8_t *)data2,strlen(data2) + 1);
	printf("msg1:");
	msg1.show_hex();	
	while(1)
	{
		sleep(2);
		//msg.show_hex();
		xbee_coor.XBEE_send_msg(msg);
		sleep(1);
		xbee_coor.XBEE_send_msg(msg1);
	}
	return 0;
}
