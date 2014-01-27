#include "main.h"

#define START_BYTE 0x7E
#define ESC_BYTE 0x7D
#define XON_BYTE 0x11
#define XOFF_BYTE 0x13
#define XOR_BYTE 0x20
/*---------MACRO FOR XBEE receive RF packet----------------
-----------------------------------------------------------
-----------------------------------------------------------*/

//frame type 1 byte, serial number 8 byte, network address 2 byte, option 1 byte 
#define FRAME_RECV_ADDR_OFFSET 1
#define FRAME_RECV_NET_ADDR_OFFSET 9
#define FRAME_RECV_OPTION_OFFSET 11
#define FRAME_RECV_DATA_OFFSET 12 

/*--------MACRO FOR THE XBEE TRANSMIT REQUEST---------------
------------------------------------------------------------
-----------------------------------------------------------*/
#define FRAME_TRAN_ID_OFFSET 1
#define FRAME_TRAN_ADDR_OFFSET 2
#define FRAME_TRAN_NET_ADDR_OFFSET 10
#define FRAME_TRAN_RADIUS_OFFSET 12
#define FRAME_TRAN_OPTION_OFFSET 13
#define FRAME_TRAN_DATA_OFFSET 14
class XBEE_msg
{
	private:
		uint8_t _errorcode;
		uint8_t _length_HI;
		uint8_t _length_LO;
		uint8_t _API_type;
		uint8_t _CheckSum;
		uint8_t _recv_CheckSum;
		uint8_t * _frameptr;
		uint16_t frame_length;
	public:	
		XBEE_msg();
		~XBEE_msg();
		void set_frameptr(uint8_t *ptr);
		uint8_t * get_frameptr();
		void set_CheckSum();
		uint8_t get_CheckSum();
		void set_errorcode(uint8_t errorcode);
		void set_length_LO(uint8_t length_LO);
		void set_length_HI(uint8_t length_HI);
		void set_API_type(uint8_t API_type);
		void set_recv_CheckSum(uint8_t recv_CheckSum);
		void show_hex();
		void detect_esc();
		/*
			this function compute frame length according to the _length_HI and _length_LO
		*/
		void set_frame_length();
		uint16_t get_frame_length();
		/*---------------------------------------------------------------
		IF THIS PACKET IS A XBEE RECEIVE PACKET WITH FRAME TYPE AS 0x90
		THEN THE FOLLOWING FUNCTION WOULD BE USEFUL
		---------------------------------------------------------------*/
		uint8_t *get_recv_packet_data_ptr();
		uint16_t get_recv_packet_data_length();
		uint64_t get_recv_source_addr();
		uint16_t get_recv_source_net_addr();
		uint8_t get_recv_option();
		bool verify_CheckSum();


		/*
			The following functions are defined for message
			sending out.
		*/
		uint32_t get_length_HI();
		uint32_t get_length_LO();
		void set_dest_addr_HI(const uint32_t &ADDR_HI);
		void set_dest_addr_LO(const uint32_t &ADDR_LO);
		void set_frame_id(uint8_t frame_id);		
};





