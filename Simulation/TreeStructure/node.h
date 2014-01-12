#ifndef _NODE_H
#define _NODE_H
#include "../TYPEDEF.h"
#include <list>

class node
{
	private:
	/*--------------------------------------------\
	/--------------------------------------------\
	/-------------PRIVATE DATA FIELD-------------*/ 
	//pointer pointing to its parent
	node* parent; 	
	uint32_t ID;


	public:
	/*--------------------------------------------\
	/--------------------------------------------\
	/---------PUBLIC DATA FIELD------------------*/
	std::list<node> children;

	/*--------------------------------------------\
	/---------------------------------------------\
	/---------PUBLIC METHOD-----------------------*/
	
	// Constructor
	node();	
        node(uint32_t ID = 0, node* parent = NULL);	
	
	//get pointer to parent	
	node* get_parent();
	//get ID
	uint32_t get_ID();	
};
#endif
