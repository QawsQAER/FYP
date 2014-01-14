#include "../TYPEDEF.h"
#include "TreeStructure.h"
#include "stdio.h"
#include <queue>
#include <vector>

TreeStructure::TreeStructure(uint8_t max_child)
{
	this->max_child = max_child;
	this->root = new node(0,NULL,0);
	this->current = this->root;
	this->last = this->root;
	this->max_delay = 0;
	this->overall_delay = 0;
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

uint32_t TreeStructure::get_max_delay()
{
	return this->max_delay;
}
uint32_t TreeStructure::get_overall_delay()
{
	return this->overall_delay;
}

void TreeStructure::add_node(uint32_t ID)
{
	node* temp = new node(ID,current);
	
	//CASE FOR THE FIRST CHILDREN OF A NODE
	if(current->children.size() == 0)
	temp->set_delay(current->get_delay() + 1);
	else//OTHERWISE
	temp->set_delay(last->get_delay() + 1);
	
	//UPDATE MAX_DELAY
	if(temp->get_delay() > this->max_delay)
	this->max_delay = temp->get_delay();
	
	//ADD TO THE OVERALL DELAY
	this->overall_delay += temp->get_delay();
	//ADD THE NODE AS THE CURRENT NODE'S CHILD
	current->children.push_back(temp);
	//UPDATE TOTAL
	this->total++;
	//UPDATE LAST ADDED NODE
	temp->prev = last;
	last->next = temp;

	uint8_t size = current->children.size();
	//IF CURRENT NODE IS THE LAST POSSIBLE CHILD OF CURRENT
	if(size >= max_child)
	{
		//MOVE CURRENT TO THE NEXT NODE
		current = current->next;	
	}
	last = temp;
}

void TreeStructure::display_tree()
{
	std::queue<node*> the_queue;
	the_queue.push(root);
	uint8_t level = 0;
	while(!the_queue.empty())
	{
		printf("level %d: ",level);
		std::vector<node*> this_level;
		
		while(!the_queue.empty())
		{
			this_level.push_back(the_queue.front());
			the_queue.pop(); 
			printf("(%d,%d)",this_level[this_level.size() - 1]->get_ID(),this_level[this_level.size() - 1]->get_delay());
		}
		uint16_t count = 0;
		
		for(count = 0;count < this_level.size();count++)
		{
			uint16_t count1 = 0;
			for(count1 = 0;count1 < this_level[count]->children.size();count1++)
			{
				the_queue.push(this_level[count]->children[count1]);
			}
		}
		level++;
		printf("\n");	
	}
}






















