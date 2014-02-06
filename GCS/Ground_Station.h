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
#include "Swarm.h"

class Ground_Station
{
	private:
		Swarm Swarm_state;
		uint8_t GCS_state;
	
		void Send_Msg_set_home_point_here();
		void Send_Msg_set_home_point_here(uint8_t AC_ID);

		void Send_Msg_holding_Point();
		void Send_Msg_holding_Point(uint8_t AC_ID);

		void Send_Msg_start_engine();
		void Send_Msg_start_engine(uint8_t AC_ID);			

		void Send_Msg_takeoff();
		void Send_Msg_takeoff(uint8_t AC_ID);
		
		void Send_Msg_landhere();
		void Send_Msg_landhere(uint8_t AC_ID);
		
		void Send_Msg_landhome();
		void Send_Msg_landhome(uint8_t AC_ID);		
	public:
		Ground_Station();
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
