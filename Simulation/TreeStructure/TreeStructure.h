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
	uint32_t total;
	uint8_t max_child;
	public:
	TreeStructure(uint8_t max_child = 2);
	
	node* get_root();

	uint8_t get_max();
	
	uint32_t get_total();
	
	void add_node(node new_node);
	
	void add_node(uint32_t ID);
)
	
};
#endif

