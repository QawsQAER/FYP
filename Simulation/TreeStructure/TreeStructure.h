#ifndef _TREE_STRUCTURE_H
#define _TREE_STRUCTURE_H

#include "node.h"

class TreeStructure
{
	private:
	/*------------------------------------\
        /-------------------------------------\
        /---------PRIVATE DATA FIELD----------\ */
	node* root;
	node* current;
	node* last;
	uint32_t total;
	uint8_t max_child;
	uint32_t max_delay;
	

	public:
	/*------------------------------------------\
	/-------------------------------------------\
	/--------------PUBLIC METHOD----------------\ */
	TreeStructure(uint8_t max_child = 2);
	
	node* get_root();

	uint8_t get_max();
	
	uint32_t get_total();
	
	uint32_t get_max_delay();
	
	void add_node(node new_node);
	
	void add_node(uint32_t ID);
	
	void display_tree();
	
};
#endif

