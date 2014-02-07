#ifndef _SWARM_H
#define _SWARM_H

#include "main.h"

#define QUAD_INIT 0
#define QUAD_RECV 1
#define QUAD_EXEC 2

class Swarm
{
	private:
		uint8_t swarm[16];	
	public:
		Swarm();
		~Swarm();
};
#endif

