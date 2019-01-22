/*
 * logic_smart_in.h
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_SMART_IN_H_
#define SOURCES_SERVICES_LAYER_LOGIC_SMART_IN_H_

#include "PE_Types.h"

#define STANDBY_TM_BASE		100    		//MS
#define STANDBY_1S_CNT		(1000 / STANDBY_TM_BASE)
#define STANDBY_TM_IN		5000    	//MS
#define STANDBY_TM_COUNT	(STANDBY_TM_IN/STANDBY_TM_BASE)


typedef struct REV_DATA_SMART_IN
{
	byte	data0;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_SMART_IN, *REV_DATA_SMART_IN_P;

extern word standby_tm_cnt;

void smart_in_resolve(byte * id_data_p);

#endif /* SOURCES_SERVICES_LAYER_LOGIC_SMART_IN_H_ */
