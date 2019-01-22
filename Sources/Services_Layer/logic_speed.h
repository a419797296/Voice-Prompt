/*
 * logic_speed.h
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_SPEED_H_
#define SOURCES_SERVICES_LAYER_LOGIC_SPEED_H_
#include "PE_Types.h"



typedef struct REV_DATA_SPEED
{
	byte	speed;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_SPEED, *REV_DATA_SPEED_P;

void speed_resolve(byte * id_data_p);

#endif /* SOURCES_SERVICES_LAYER_LOGIC_SPEED_H_ */
