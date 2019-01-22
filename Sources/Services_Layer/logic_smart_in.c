/*
 * logic_smart_in.c
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "logic_smart_in.h"
#include "logic_smart_drive.h"
#include "logic_com.h"
word standby_tm_cnt = 0;

void smart_in_resolve(byte * id_data_p)
{
	REV_DATA_SMART_IN_P smart_in_p = (REV_DATA_SMART_IN_P)id_data_p;

	switch(smart_in_p->data0)
	{
	case	0x06:        //automated driving system disable
		Lightbar_Set(LB_BLUE_DARK);
		smart_drive_stat = manual;
		break;
	case	0x07:		//automated driving system standby
		Lightbar_Set(LB_GREEN_DARK);
		voice_set_flag(SPEAK_IN, ALARM_BUG_HIGH_SPEED);
		smart_drive_stat = standby;
		break;
	case	0x08:		//automated driving system failed
		Lightbar_Set(LB_RED_FLASH_TWICE);
		voice_set_flag(SPEAK_IN, ALARM_CHANGE_DEC);
		smart_drive_stat = standby;
		break;
	case	0x09:		//automated driving system active
		Lightbar_Set(LB_GREEN_BRIGHT);
		voice_set_flag(SPEAK_IN, ALARM_CHANGE_ASC);
		smart_drive_stat = smart;
		break;

	default:
		break;
	}


//
//	standby_tm_cnt++;
//	switch(smart_drive_stat)
//	{
//	case manual:
//		if(standby_tm_cnt > STANDBY_TM_COUNT)        // there is no err happened during the STANDBY_TM_COUNT
//		{
//			smart_drive_stat = standby;
//			Lightbar_Set(LB_GREEN_DARK);
//			voice_set_flag(SPEAK_IN, ALARM_UP_LIMIT);
//
//		}
//		else
//		{
//			Lightbar_Set(LB_OFF);
//		}
//		break;
//	case standby:
//		if(smart_in_p->data0 == 0x09)					//enter smart mode
//		{
//			smart_drive_stat = smart;
//			voice_set_flag(SPEAK_IN, ALARM_CHANGE_ASC);
//		}
//		else
//			Lightbar_Set(LB_GREEN_DARK);
//
//		break;
//	case smart:
//		Lightbar_Set(LB_GREEN_BRIGHT);
//		break;
//	default:
//		break;
//	}




}
