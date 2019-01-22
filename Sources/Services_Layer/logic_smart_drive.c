/*
 * logic_smart_drive.c
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "logic_smart_drive.h"
#include "logic_smart_in.h"
#include "logic_com.h"

SMART_DRIVE_STAT smart_drive_stat = manual;


void smart_drive_resolve(byte * id_data_p)
{
//	REV_DATA_SMART_DRIVE_P smart_drive_p = (REV_DATA_SMART_DRIVE_P)id_data_p;
//	if(smart_drive_p->err_type)
//	{
//		standby_tm_cnt = 0;
////		if(smart_drive_stat == smart||smart_drive_stat == standby)
//		{
//			smart_drive_stat = manual;
//			Lightbar_Set(LB_RED_FLASH_TWICE);
//			voice_set_flag(SPEAK_IN, ALARM_BUG_HIGH_SPEED);
//		}
//
//	}
//	if(smart_drive_p->exit_type)
//	{
//		standby_tm_cnt = 0;
////		if(smart_drive_stat == smart||smart_drive_stat == standby)
//		{
//			smart_drive_stat = manual;
//			Lightbar_Set(LB_OFF);
//			voice_set_flag(SPEAK_IN, ALARM_CHANGE_DEC);
//		}
//
//	}
//	voice_set_flag(SPEAK_IN, VOICE_ATTENTION_DRIVELESS);
}
