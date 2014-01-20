#include "port.h"

void port_init()
{
    xbee_coor.baud(57600);
    pc.baud(9600);
}