#include "main.h"
#include "pprz_msg.h"

int main()
{
	uint8_t sender_id = 1;
	uint8_t msg_id = 90;
	uint32_t pos_x = 10;
	uint32_t pos_y = 100;
	uint32_t pos_z = 88;
	pprz_msg data;
	data.pprz_put_byte(&sender_id);
	data.pprz_put_byte(&msg_id);
	data.pprz_put_4bytes((uint8_t *) &pos_x);
	data.pprz_put_4bytes((uint8_t *) &pos_y);
	data.pprz_put_4bytes((uint8_t *) &pos_z);
	data.show_hex();

	uint8_t recv_sender_id = 0;
	uint8_t recv_msg_id = 0;
	uint32_t recv_pos_x = 0;
	uint32_t recv_pos_y = 0;
	uint32_t recv_pos_z = 0;
	recv_sender_id = data.pprz_read_byte();
	recv_msg_id = data.pprz_read_byte();
	recv_pos_x = data.pprz_read_4bytes();
	recv_pos_y = data.pprz_read_4bytes();
	recv_pos_z = data.pprz_read_4bytes();

	printf("From sender %d ,msg_id %d, pos_x %d, pos_y %d, pos_z %d\n",recv_sender_id,recv_msg_id,recv_pos_x,recv_pos_y,recv_pos_z);
	return 0;
}
