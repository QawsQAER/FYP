#include "../TYPEDEF.h"
#include "node.h"
//Constructor
node::node()
{}

node::node(uint32_t ID, node* parent, uint32_t delay)
{
	this->ID = ID;
	this->parent = parent;
	this->delay = delay;
}


node* node::get_parent()
{
	return this->parent;
}


uint32_t node::get_ID()
{
	return this->ID;
}
uint32_t node::get_delay()
{
	return this->delay;
}
void node::set_delay(uint32_t delay)
{
	this->delay = delay;
}
