#define _USE_MBED 0



//-------------------------------------------//

#if _USE_MBED

#else

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned char uint8_t;
typedef unsigned long long uint64_t;

#define my_write(fd,buff,size) write(fd,buff,size)
#define my_read(fd,buff,size) read(fd,buff,size) 

//for POSIX timer, should link with -lrt
#include <signal.h>
#include <time.h>

#endif
//-------------------------------------------//

#define KB 1024
#define MB KB * KB
