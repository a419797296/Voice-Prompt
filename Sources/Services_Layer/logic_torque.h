/*
 * logic_torque.h
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_TORQUE_H_
#define SOURCES_SERVICES_LAYER_LOGIC_TORQUE_H_

#include "PE_Types.h"

#define NO_TORQUE_TM_BASE			100    		//MS

#define NO_TORQUE_1S_CNT			(1000 / NO_TORQUE_TM_BASE)

#define NO_TORQUE_TM_ALARM			1000    	//MS
#define NO_TORQUE_TM_ALARM_CNT		(NO_TORQUE_TM_ALARM/NO_TORQUE_TM_BASE)

#define NO_TORQUE_TM_URGENCY		3000    	//MS
#define NO_TORQUE_TM_URGENCY_CNT	(NO_TORQUE_TM_URGENCY/NO_TORQUE_TM_BASE)

typedef struct REV_DATA_TORQUE
{
	byte	torque;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_TORQUE, *REV_DATA_TORQUE_P;

extern word no_torque_tm_cnt;
void torque_resolve(byte * id_data_p);
#endif /* SOURCES_SERVICES_LAYER_LOGIC_TORQUE_H_ */
