#ifndef _NODE_H
#define _NODE_H
#include "../TYPEDEF.h"
#include <list>

class node
{
	private:
	std::list<node>	children;
        uint8_t max_child; 	

	public:
	// Constructor
	node();	
	node(uint8_t max_child);
	
	//get maximum number of children
	uint8_t get_max_child();

	
};
#endif
