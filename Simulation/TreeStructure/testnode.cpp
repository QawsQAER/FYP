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
		printf("Usage: testnode [number of tree] [maximum child of a node]\n");
		return 0;
	}

	TreeStructure Tree(max_child);
	uint32_t ID = 0;
	for(ID = 1;ID < num_of_node;ID++)
		Tree.add_node(ID);
//	Tree.display_tree();
	printf("the maximum delay of this tree with %d max child is %d, overall delay is %d\n\n",Tree.get_max(),Tree.get_max_delay(),Tree.get_overall_delay());

	return 0;
}
