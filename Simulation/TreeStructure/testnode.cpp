#include "stdio.h"
#include "stdlib.h"
#include "node.h"
#include "TreeStructure.h"
int main(int argc, char ** argv)
{

	uint32_t num_of_node;
	unsigned char max_child;
	if(argc == 3)
	{
		num_of_node = atoi(argv[1]);
		max_child = atoi(argv[2]);
	}
	else
	{
		printf("Error: invalid number of arguments\n");
		return 0;
	}
	for(int count = 1; count < num_of_node/2;count++)
	{
	TreeStructure Tree(count);
	uint32_t ID = 0;
	for(ID = 1;ID < num_of_node;ID++)
		Tree.add_node(ID);
//	Tree.display_tree();
	printf("the maximum delay of this tree with %d max child is %d\n\n",Tree.get_max(),Tree.get_max_delay());
	}
	return 0;
}
