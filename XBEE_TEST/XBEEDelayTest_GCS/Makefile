CC = g++
CFLAGS = -Wall
all: main
	rm -f *.o	

main: main.o XBee.o Serial.o 
	$(CC) -o main *.o $(CFLAGS)
test: test.o Serial.o
	$(CC) -o test test.o Serial.o $(CFLAGS)
	rm -f test.o
	rm -f Serial.o
test.o:
	$(CC) -o test.o -c test.cpp $(CFLAGS)
main.o: main.cpp main.h
	$(CC) -o main.o -c main.cpp $(CFLAGS)
Xbee.o: Xbee.h Xbee.cpp
	$(CC) -o Xbee.o -c Xbee.cpp $(CFLAGS)
Serial.o: Serial.h Serial.cpp
	$(CC) -o Serial.o -c Serial.cpp $(CFLAGS)

clean:
	rm -f *.o
	

