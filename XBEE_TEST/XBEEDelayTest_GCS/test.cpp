#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fcntl.h>
#include "Serial.h"

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		printf("Error: Invalid number of parameters\n");
		printf("Usage: ./test [name of the ttyUSBX]\n");
		return 0;
	}
	char portname[32];
	strcpy(portname,argv[1]); 
	printf("name of device %s\n",portname);
	int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		return 0;
	}
	set_interface_attribs(fd,B57600,0);
	set_blocking(fd,0);
	char *buff = new char[1024];
	int receive_byte = 0;
	int pos = 0;
	while(1)
	{
		char input[32];
		scanf("%s",input);
		receive_byte = read(fd,buff + pos,1024);
		printf("Read %d byte\n",receive_byte);
		if(pos + receive_byte + 1 <= 1024)
                write(0,buff + pos,receive_byte + 1);
		pos+=receive_byte;
		//else
		//{
		//	printf("read over buffer size\n");
		//}
		if(pos >= 1024)
		{
			pos = 0;
			memset(buff,0,1024);
			printf("buffer is full and it's clean up\n");  
		}
		printf("\n");
	}







	return 0;
}
