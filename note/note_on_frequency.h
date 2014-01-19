#define SPEED_OF_XBEE_MAC_LAYER 250 //Kbps
#define THEO_FREQ_OF_32_MSG 968 //HZ
#define THEO_TRANS_OF_32_MSG 1 //ms
#define NUM_OF_32_MSG_PS 1000 //number
#define THEO_TRANS_OF_64_MSG 2 //ms
#define THEO_TRANS_OF_128_MSG 4 //ms



	autopilot_periodic() is called by main_periodic()
	and the frequency is defined by 'RunOnceEvery(NAV_PRESCALER,nav_periodic_task())'
	NAV_PRESCALER is defined by (512/NAV_FREQ), and thus is 512/16 = 32
	NAV_FREQ is defined as 16



	nav_periodic_task() is called by autopilot_periodic()
	and the frequency is defined by 'RunOnceEvery(16,{stage_time++;block_time++;})'	
	and it's the loop useful when AP_NAV_MODE is selected
