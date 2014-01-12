$(CC) = g++;

testnode: testnode.o node.o
	g++ -o testnode testnode.o node.o
	rm -f *.o
testnode.o: testnode.cpp
	g++ -c testnode.cpp
node.o: node.h node.cpp
	g++ -c node.cpp
clean:
	rm -f *.o
	
