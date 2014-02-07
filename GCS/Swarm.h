#ifndef _SWARM_H
#define _SWARM_H

#include "main.h"

#define QUAD_INIT 0
#define QUAD_RECV 1
#define QUAD_EXEC 2

#define QUAD_NB 4
class Swarm
{
	private:
		uint8_t state[QUAD_NB];	
		uint32_t XBEE_ADDR_HI[QUAD_NB];
		uint32_t XBEE_ADDR_LO[QUAD_NB];	
	public:
		Swarm();
		~Swarm();
		uint32_t get_address_HI(uint8_t ac_id);
		uint32_t get_address_LO(uint8_t ac_id);
};
#endif

