/*

        This source code is written by Edward HUANG, and Tony Yi
        For the development of their Final Year Project
        Department of Computer Science and Engineering
        The Chinese University of HONG KONG

*/

#ifndef _GROUND_STATION_H
#define _GROUND_STATION_H
#include "main.h"
#include "XBEE.h"
#include "pprz_msg.h"
#include "Swarm.h"
#include "Serial.h"

class Ground_Station
{
	private:
		Swarm *Swarm_state;
		XBEE *Com;
		uint8_t GCS_state;
	
		void Send_Msg_set_home_point_here();
		void Send_Msg_set_home_point_here(uint8_t AC_ID);

		void Send_Msg_holding_point();
		void Send_Msg_holding_point(uint8_t AC_ID);

		void Send_Msg_start_engine();
		void Send_Msg_start_engine(uint8_t AC_ID);			

		void Send_Msg_takeoff();
		void Send_Msg_takeoff(uint8_t AC_ID);
		
		void Send_Msg_landhere();
		void Send_Msg_landhere(uint8_t AC_ID);
		
		void Send_Msg_landhome();
		void Send_Msg_landhome(uint8_t AC_ID);		
	public:
		//Ground_Station();
		//This function will initilize the serial port for communication and the xbee module etc.
		Ground_Station(char * port_name);
		~Ground_Station();
		//This function will initilize the navigation of all quadcopters
		void init_nav_quadcopters();
		//This function will initilize the navigation of the quadcopter with AC_ID
		void init_nav_quadcopters(uint8_t AC_ID);
		
		//This function will ask quadcopters to takeoff
		void takeoff_quadcopters();
		//This function will ask the quadcopter to takeoff
		void takeoff_quadcopters(uint8_t AC_ID);
			
};

#endif
