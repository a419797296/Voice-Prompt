/*
 * logic_AutodDrvngInfoDspReq.c
 *
 *  Created on: 2018Äê11ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "logic_AutodDrvngInfoDspReq.h"
void info_disp_resolve(byte * id_data_p)
{

	REV_DATA_DRV_INFO_DISP_P info_disp_p = (REV_DATA_DRV_INFO_DISP_P)id_data_p;
	switch(info_disp_p->info)
	{
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
		smart_drive_stat = manual;
		Lightbar_Set(LB_BLUE_DARK);
		break;

	default:
		break;
	}


}
