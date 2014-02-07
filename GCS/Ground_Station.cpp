#include "Ground_Station.h"
/*
Ground_Station::Ground_Station()
{
}
*/
Ground_Station::Ground_Station(char * port_name)
{
	this->Swarm_state = new Swarm();
	int fd = open(port_name, O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0)
	{
		fprintf(stderr,"%s\n",strerror(errno));
		//the program should stop immediately
	}
	else
	{
		set_interface_attribs(fd,B57600,0);
		set_blocking(fd,0);
		this->Com = new XBEE(fd,0x00000000,0x0000ffff,0);
	}
	this->GCS_state = 0;	
}

Ground_Station::~Ground_Station()
{
	delete this->Swarm_state;
	delete this->Com;
}

void Ground_Station::init_nav_quadcopters(uint8_t AC_ID)
{
	this->Send_Msg_set_home_point_here(AC_ID);
}

void Ground_Station::Send_Msg_set_home_point_here(uint8_t AC_ID)
{	
	pprz_msg data;
	uint8_t block_id = BLOCK_ID_HOME_POINT;
	data.pprz_set_block(AC_ID,block_id);
	data.show_hex();
	XBEE_msg msg;
	Swarm *temp = this->Swarm_state;
	msg.set_tran_packet(temp->get_address_HI(AC_ID),temp->get_address_LO(AC_ID),0xFF,0xFE,data.pprz_get_data_ptr(),data.pprz_get_length());
	msg.show_hex();
	this->Com->XBEE_send_msg(msg);	
}
void Ground_Station::Send_Msg_holding_point(uint8_t AC_ID)
{
	
}
