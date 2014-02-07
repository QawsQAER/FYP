#include "Swarm.h"

Swarm::Swarm()
{
	/*
	uint8_t count = 0;
	for(count = 0; count < QUAD_NB;count++)
	{
		
	}
	*/
	state[1] = IDLE;
	XBEE_ADDR_HI[1] = XBEE_END_ADDR_A_HI;
	XBEE_ADDR_LO[1] = XBEE_END_ADDR_A_LO;	
}

Swarm::~Swarm()
{
}
uint32_t Swarm::get_address_HI(uint8_t &AC_ID)
{return XBEE_ADDR_HI[AC_ID];}

uint32_t Swarm::get_address_LO(uint8_t &AC_ID)
{return XBEE_ADDR_LO[AC_ID];}
