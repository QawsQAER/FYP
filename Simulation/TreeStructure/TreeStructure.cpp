#include "../TYPEDEF.h"
#include "TreeStructure.h"

TreeStructure::TreeStructure(uint8_t max_child)
{
	this->max_child = max_child;
	this->root = new node(0,NULL,0);
	this->current = this->root;
	this->total = 0;
}

node* TreeStructure::get_root()
{
	return this->root;
}

uint8_t TreeStructure::get_max()
{
	return this->max_child;
}

uint32_t TreeStructure::get_total()
{
	return this->total;
}

void TreeStructure::add_node(uint32_t ID)
{
	node temp(ID,current);

	//IN CASE CURRENT NODE IS FULL
	if(current->children.size() >= max_child)
	{
			
	}
}
