CC = g++
CFLAGS = -Wall -g
##############################################
#OPTION = -D_USE_XBEE_ESC=1
#############################################


##########DEBUG OPTION#######################
#DEBUG_MACRO = -D_DEBUG_CHECKSUM=1 
#DEBUG_MACRO += -D_DEBUG_XBEE_parse_XBEE_msg=1 
#DEBUG_MACRO += -D_DEBUG=1
#DEBUG_MACRO += -D_DEBUG_VERIFY_CHECKSUM=1
#DEBUG_MACRO += -D_DEBUG_XBEE_SEND_MSG=1
#############################################


TARGETS= main test test_sender
all: main test
	rm -f *.o	

main: main.o XBEE.o Serial.o 
	$(CC) -o main *.o $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
test: test.o Serial.o XBEE.o XBEE_msg.o
	$(CC) -o test test.o Serial.o XBEE.o XBEE_msg.o $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
	rm -f test.o
	rm -f Serial.o
test_sender: test_sender.o Serial.o XBEE.o XBEE_msg.o
	$(CC) -o test_sender test_sender.o Serial.o XBEE.o XBEE_msg.o $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
	rm -f test_sender.o
	rm -f Serial.o

test.o: test.cpp
	$(CC) -o test.o -c test.cpp $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
test_sender.o: test_sender.cpp
	$(CC) -o test_sender.o -c test_sender.cpp $(CFLAGS) $(DEBUG_MACRO) $(OPTION)

main.o: main.cpp main.h
	$(CC) -o main.o -c main.cpp $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
XBEE.o: XBEE.h XBEE.cpp XBEE_msg.cpp
	$(CC) -o XBEE.o -c XBEE.cpp $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
XBEE_msg.o: XBEE_msg.h XBEE_msg.cpp
	$(CC) -o XBEE_msg.o -c XBEE_msg.cpp $(CFLAGS) $(DEBUG_MACRO) $(OPTION)
Serial.o: Serial.h Serial.cpp
	$(CC) -o Serial.o -c Serial.cpp $(CFLAGS) $(DEBUG_MACRO) $(OPTION)

clean:
	rm -f $(TARGETS)
	rm -f *.o
