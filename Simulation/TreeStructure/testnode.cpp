#include "stdio.h"
#include "node.h"
#include "TreeStructure.h"
int main()
{
	printf("----------\n--------------\n----------n");
	node a(1,NULL);
	node b(2,&a);
	printf("parent's ID is %d\n",b.get_parent()->get_ID());
	b.set_delay(2);
	a.set_delay(1);

	printf("b's delay is %d\n, a's delay is %d\n",b.get_delay(),a.get_delay());
	
	node c(3,&a,b.get_delay() + 1);
	printf("c's ID is %d\n and its delay is %d\n",c.get_ID(), c.get_delay());
	
	return 0;
}
