/*
 * logic_AutodDrvngInfoDspReq.h
 *
 *  Created on: 2018Äê11ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_AUTODDRVNGINFODSPREQ_H_
#define SOURCES_SERVICES_LAYER_LOGIC_AUTODDRVNGINFODSPREQ_H_
#include "PE_Types.h"
#include "logic_smart_drive.h"
#include "Lightbar.h"
typedef struct REV_DATA_DRV_INFO_DISP
{
	byte	info;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_DRV_INFO_DISP, *REV_DATA_DRV_INFO_DISP_P;

extern void info_disp_resolve(byte * id_data_p);
#endif /* SOURCES_SERVICES_LAYER_LOGIC_AUTODDRVNGINFODSPREQ_H_ */
