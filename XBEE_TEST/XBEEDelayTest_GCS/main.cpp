#include "mbed.h"
#include "port.h"
#include "Xbee.h"

Xbee xbee_coor(TX_PIN,RX_PIN);


void Test1() //TESTING BROADCASTING 32 BYTE WITH 1 HZ
{
        char message[32] = "123456789abcdef123456789abcdef";
        uint8_t count = 0;
        while(count++ < 5)
        {
            xbee_coor.transmit(0xff,message,strlen(message));
            wait(1);
        }
}


int main() 
{
  port_init();

  while(1)
  {
    Test1();
  }
  return 0;
}    
