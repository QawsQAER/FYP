#include "main.h"

#define START_BYTE 0x7E
class XBEE_msg
{
	private:
		uint8_t _errorcode;
		uint8_t _length_HI;
		uint8_t _length_LO;
		uint8_t _Api_type;
		uint8_t _CheckSum;
		char * _framedata;
	public:	
		XBEE_msg();
		~XBEE_msg();
		void set_CheckSum();
		uint8_t get_CheckSum();
		void set_errorcode(uint8_t errorcode);
};
