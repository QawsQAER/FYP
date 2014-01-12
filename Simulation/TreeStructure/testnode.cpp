#include "stdio.h"
#include "node.h"
#include "TreeStructure.h"
int main()
{

	TreeStructure Tree;
	uint8_t ID = 0;
	for(ID = 1;ID < 10;ID++)
		Tree.add_node(ID);
	Tree.display_tree();
	printf("the maximum delay of this tree is %d\n\n\n",Tree.get_max_delay());
	
	TreeStructure Tree2(3);	
	for(ID = 1;ID < 10;ID++)
	Tree2.add_node(ID);
	Tree2.display_tree();
	printf("the maximum delay of this tree is %d\n",Tree2.get_max_delay());
	return 0;
}
