#include "main.h"
#include "Ground_Station.h"

int main(int argc, char **argv)
{
	Ground_Station * GCS;
	if(argc == 2)
		GCS = new Ground_Station(argv[1]);	
	else	
		GCS = new Ground_Station("/dev/ttyUSB0");

	uint8_t ac_id = 1;
	while(1)
	{
		sleep(5);
		GCS->init_nav_quadcopters(ac_id);
	}	
	return 0;
}
