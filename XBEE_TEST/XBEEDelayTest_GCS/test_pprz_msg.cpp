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
	return 0;
}
