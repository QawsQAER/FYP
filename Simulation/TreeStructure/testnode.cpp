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
	return 0;
}
