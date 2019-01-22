/*
 * logic_smart_drive.h
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_SMART_DRIVE_H_
#define SOURCES_SERVICES_LAYER_LOGIC_SMART_DRIVE_H_
#include "PE_Types.h"

typedef enum
{
    manual,
    standby,
    smart,
	quit,

}SMART_DRIVE_STAT;

typedef struct REV_DATA_SMART_DRIVE
{
	byte	err_type;
	byte	exit_type;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_SMART_DRIVE, *REV_DATA_SMART_DRIVE_P;

extern SMART_DRIVE_STAT smart_drive_stat;
void smart_drive_resolve(byte * id_data_p);
#endif /* SOURCES_SERVICES_LAYER_LOGIC_SMART_DRIVE_H_ */
