#include "stdio.h"
#include "node.h"

int main()
{
	node a(1,NULL);
	node b(2,&a);
	printf("parent's ID is %d\n",b.get_parent()->get_ID());
	return 0;
}
