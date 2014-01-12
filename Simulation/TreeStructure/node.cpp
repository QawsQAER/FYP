#include "../TYPEDEF.h"
#include "node.h"
//Constructor
node::node()
{}

node::node(uint32_t ID, node* parent)
{
	this->ID = ID;
	this->parent = parent;
}


node* node::get_parent()
{
	return this->parent;
}

uint32_t node::get_ID()
{
	return this->ID;
}
