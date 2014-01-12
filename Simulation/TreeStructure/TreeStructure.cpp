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

void TreeStructure::add_node( uint32_t ID)
{
	node* temp = new node(ID,current);
	
	current->children.push_back(temp);

	temp->prev = last;
	last->next = temp;

	uint8_t size = current->children.size();
	if(size >= max_child)
	{
		//CASE  IF CURRENT NODE IS THE LAST ONE
		current = current->next;	
	}
	last = temp;
}

void TreeStructure::recursive_add_node(node* temp_root, uint32_t ID)
{
	uint8_t size = temp_root->children.size();
	if(size >= this->max_child)
	{	
		//IN CASE THE TEMP_ROOT IS FULL
		for(uint8_t count;count < size;count++)
		{
			if(temp_root->children[count]->children.size() < this->max_child)
			;	
		}
	}
	else if(size == 0)
	{
		//IN CASE THE TEMP_ROOT IS EMPTY
		node* temp = new node(ID,temp_root,temp_root->get_delay() + 1);
		temp->prev = temp_root;
		temp_root->children.push_back(temp);
	}
	else
	{
		//IN CASE THE TEMP_ROOT IS NEITHER FULL NOR EMPTY
		node* prev = temp_root->children[size - 1];
		node* temp = new node(ID,temp_root,prev->get_delay() + 1); 
		temp->prev = prev;
		temp_root->children.push_back(temp);
	}
	
	
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
			printf("%d, ",this_level[this_level.size() - 1]->get_ID());
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






















