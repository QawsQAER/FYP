CC = g++
CFLAGS = -Wall -g
DEBUG_MACRO = -D_DEBUG_CHECKSUM=1 
#DEBUG_MACRO += -D_DEBUG_XBEE_parse_XBEE_msg=1 
DEBUG_MACRO += -D_DEBUG=1
DEBUG_MACRO += -D_DEBUG_VERIFY_CHECKSUM=1
TARGETS= main test
all: main test
	rm -f *.o	

main: main.o XBEE.o Serial.o 
	$(CC) -o main *.o $(CFLAGS) $(DEBUG_MACRO)
test: test.o Serial.o XBEE.o XBEE_msg.o
	$(CC) -o test test.o Serial.o XBEE.o XBEE_msg.o $(CFLAGS) $(DEBUG_MACRO)
	rm -f test.o
	rm -f Serial.o
test.o:
	$(CC) -o test.o -c test.cpp $(CFLAGS) $(DEBUG_MACRO)
main.o: main.cpp main.h
	$(CC) -o main.o -c main.cpp $(CFLAGS) $(DEBUG_MACRO)
XBEE.o: XBEE.h XBEE.cpp XBEE_msg.cpp
	$(CC) -o XBEE.o -c XBEE.cpp $(CFLAGS) $(DEBUG_MACRO)
XBEE_msg.o: XBEE_msg.h XBEE_msg.cpp
	$(CC) -o XBEE_msg.o -c XBEE_msg.cpp $(CFLAGS) $(DEBUG_MACRO)
Serial.o: Serial.h Serial.cpp
	$(CC) -o Serial.o -c Serial.cpp $(CFLAGS) $(DEBUG_MACRO)

clean:
	rm -f $(TARGETS)
	rm -f *.o
