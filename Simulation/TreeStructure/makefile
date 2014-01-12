$(CC) = g++;

testnode: testnode.o node.o TreeStructure.o
	g++ -o testnode testnode.o node.o TreeStructure.o
	rm -f *.o
testnode.o: testnode.cpp
	g++ -c testnode.cpp
node.o: node.h node.cpp
	g++ -c node.cpp
TreeStructure.o: TreeStructure.h TreeStructure.cpp
	g++ -c TreeStructure.cpp
clean:
	rm -f *.o
	
