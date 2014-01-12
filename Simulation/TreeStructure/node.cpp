#include "../TYPEDEF.h"
#include "node.h"
#include "stdio.h"
//Constructor
node::node()
{
	this->max_child = 2;
	printf("when constructed max_child = %d\n",this->max_child);	
}

node::node(uint8_t max_child)
{
	this->max_child = max_child;	
}

//
uint8_t node::get_max_child()
{
	return this->max_child;
}
