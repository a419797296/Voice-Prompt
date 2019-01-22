/*
 * logic_smart_deg.h
 *
 *  Created on: 2018Äê11ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_SMART_DEG_H_
#define SOURCES_SERVICES_LAYER_LOGIC_SMART_DEG_H_
#include "logic_com.h"
typedef struct REV_DATA_DEG
{
	byte	sig;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_DEG, *REV_DATA_DEG_P;
extern void smart_deg_resolve(byte * id_data_p);
#endif /* SOURCES_SERVICES_LAYER_LOGIC_SMART_DEG_H_ */
