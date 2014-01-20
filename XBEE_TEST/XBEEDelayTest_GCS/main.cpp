#include "mbed.h"
#include "port.h"

int main() 
{
  port_init();
  while(1)
  {
    xbee_coor.printf("Hello Xbee   ");
    wait(1);
  }
  return 0;
}    
