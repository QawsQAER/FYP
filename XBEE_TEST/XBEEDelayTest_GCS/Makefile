CC = g++
CFLAGS = -Wall
all: main
	rm -f *.o	

main: main.o XBee.o Serial.o 
	$(CC) -o main *.o $(CFLAGS)

main.o: main.cpp main.h
	$(CC) -c main.cpp $(CFLAGS)
Xbee.o: Xbee.h Xbee.cpp
	$(CC) -c Xbee.cpp $(CFLAGS)
Serial.o:
	$(CC) -c Serial.h $(CFLAGS)

clean:
	rm -f *.o
	

