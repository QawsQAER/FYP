CC = g++
CFLAGS = -Wall
all: main
	rm -f *.o	

main: main.o XBEE.o Serial.o 
	$(CC) -o main *.o $(CFLAGS)
test: test.o Serial.o
	$(CC) -o test test.o Serial.o $(CFLAGS)
	rm -f test.o
	rm -f Serial.o
test.o:
	$(CC) -o test.o -c test.cpp $(CFLAGS)
main.o: main.cpp main.h
	$(CC) -o main.o -c main.cpp $(CFLAGS)
XBEE.o: XBEE.h XBEE.cpp
	$(CC) -o XBEE.o -c XBEE.cpp $(CFLAGS)
Serial.o: Serial.h Serial.cpp
	$(CC) -o Serial.o -c Serial.cpp $(CFLAGS)

clean:
	rm -f *.o
