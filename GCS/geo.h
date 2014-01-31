/*

        This source code is written by Edward HUANG, and Tony Yi
        For the development of their Final Year Project
        Department of Computer Science and Engineering
        The Chinese University of HONG KONG

*/

/* 
        This source code referenced to the implemenetation of some geo functions
        in the paparazzi open source project
        http:\\paparazzi.enac.fr
*/

#ifndef _GEO_H
#define _GEO_H
#include "main.h"
#include "GCS_math.h"

//-----------------------------------------------//
//-Struct definition for geographical function---//
//-----------------------------------------------//
struct EcefCoor_i
{
	int32_t x;
	int32_t y;
	int32_t z;
};
////////////////////
struct LlaCoor_i
{
	//in radians *1e7
	int32_t lon;
	int32_t lat;
	int32_t alt;
};
///////////////////
struct NedCoor_i
{
	//north
	int32_t x;
	//east
	int32_t y;
	//down
	int32_t z;
};
//////////////////
struct EnuCoor_i
{
	int32_t x;
	int32_t y;
	int32_t z;
};
//////////////////
struct LtpDef_i
{
	//reference point in ecef coordinate system
	struct EcefCoor_i ecef;
	//reference point in lla coordinate system
	struct LlaCoor_i lla;
	//Rotational matrix of ecef w.r.t local tangent plane
	struct Int32Mat33 ltp_of_ecef;
	//height above mean sea level
	int32_t hmsl;
};

//-----------------------------------------------------//
//-Function prototypes for geographical functionality--//
//-----------------------------------------------------//


//to be implemented in geo.cpp
extern void ned_of_ecef_point_i(struct NedCOor_i * ned, struct LtpDef_i *def, struct EcefCoor_i * ecef);

extern void enuof_ecef_pos_i(struct EnuCoor_i * enu, struct LtpDef_i *def, struct EcefCoor_i * ecef);

extern void enu_of_ecef_point_i(struct EnuCoor_i *enu, struct LtpDef_i *def, struct EcefCoor_i *ecef);

//-----------------------------------------------------//
//--MACRO for implementation of geopraphical functions-//
//-----------------------------------------------------//

#define ENU_OF_TO_NED(_po, _pi) \
{ \
	(_po).x = (_pi).y;\
	(_po).y = (_pi).x;\
	(_po).z = -(_pi).z;\	
}





#endif
