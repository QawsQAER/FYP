/*

        This source code is written by Edward HUANG, and Tony Yi
        For the development of their Final Year Project
        Department of Computer Science and Engineering
        The Chinese University of HONG KONG

*/

/* 
        This source code refered to the implemenetation of some 
	mathematic functions in the paparazzi open source project
        http:\\paparazzi.enac.fr
*/

#ifndef _GCS_MATH_H
#define _GCS_MATH_H
#include "main.h"

//------------------------------------------------//
//--Struct Definition for Math functionality------//
//------------------------------------------------//


//a 3 by 3 matrix with int32 type as its elements
struct Int32Mat33
{
	int32_t m[3 * 3];
};

//------------------------------------------------//
//--MACRO For realizing Math functionality--------//
//------------------------------------------------//

#define INT32_POS_FRAC

#define HIGH_RES_TRIG_FRAC

#define VECT3_DIFF

#define INT32_VECT3_LSHIFT




#endif
