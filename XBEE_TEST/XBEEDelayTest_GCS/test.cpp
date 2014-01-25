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
		printf("Warning: Using default port /dev/ttyUSB0\n");
		strcpy(portname,"/dev/ttyUSB0");
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
	while(1)
	{
		//scanf("%s",dummy);
		//sleep for 5s
		//printf("\n\nSLEEPING\n");
		//sleep(5);
		//printf("1.READING\n");
		xbee_coor.XBEE_read_into_recv_buff();
		//printf("2.PARSING\n");
		xbee_coor.XBEE_parse_XBEE_msg();
		//printf("3.SHOWING\n");
		xbee_coor.XBEE_show_msg();	
	}
	return 0;
}
