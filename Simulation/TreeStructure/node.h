#ifndef _NODE_H
#define _NODE_H
#include "../TYPEDEF.h"
#include <vector>

class node
{
	private:
	/*--------------------------------------------\
	/--------------------------------------------\
	/-------------PRIVATE DATA FIELD-------------*/ 
	//pointer pointing to its parent
	node* parent;
 	
	uint32_t ID;
	uint32_t delay;

	public:
	/*--------------------------------------------\
	/--------------------------------------------\
	/---------PUBLIC DATA FIELD------------------*/
	std::vector<node*> children;
	node* prev;
	node* next;
	/*--------------------------------------------\
	/---------------------------------------------\
	/---------PUBLIC METHOD-----------------------*/
	
	// Constructor
	node();		
	node(uint32_t ID, node* parent = NULL, uint32_t delay = 0);
	//get pointer to parent	
	node* get_parent();
	//get ID
	uint32_t get_ID();
	//get delay
	uint32_t get_delay();
	//set delay
	void set_delay(uint32_t delay);	
};
#endif
