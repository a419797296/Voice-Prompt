/*
 * logic_torque.c
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */


#include "logic_torque.h"
#include "logic_smart_drive.h"
#include "logic_smart_in.h"
#include "logic_fatigue.h"
#include "logic_com.h"
#include "time_flash.h"
word no_torque_tm_cnt = 0;

void torque_resolve(byte * id_data_p)
{
	REV_DATA_TORQUE_P torque_p = (REV_DATA_TORQUE_P)id_data_p;
	if(smart_drive_stat == quit)
	{
		if(torque_p->torque == 0)     //no torque signal
		{
			no_torque_tm_cnt++;
			if(no_torque_tm_cnt > NO_TORQUE_TM_URGENCY_CNT)
			{
				voice_set_flag(SPEAK_IN, ALARM_DIDI_FOR_FIVE);
				Lightbar_Set(LB_RED_FLASH_MORE);
				tm_flash_flag.flag.bits.alarm_manual_drv = 1;
				time_flash_set_flag(alarm_manual_drv);
//				if(tm_flag.tm_100ms_flag)
//				{
//					tm_flag.tm_100ms_flag = FALSE;
//					MOTOR_NegVal();
//				}
			}
//			else if(no_torque_tm_cnt > NO_TORQUE_TM_ALARM_CNT)
//			{
//				voice_set_flag(SPEAK_IN, ALARM_DENGDENG);
//				Lightbar_Set(LB_RED_FLASH_THRICE);
//				if(tm_flag.tm_500ms_flag)
//				{
//					tm_flag.tm_500ms_flag = FALSE;
//					MOTOR_NegVal();
//				}
//			}
			else
			{

			}
		}
		else
		{
			no_torque_tm_cnt = 0;
			smart_drive_stat = manual;
			Lightbar_Set(LB_BLUE_DARK);
		}

	}
//	voice_flag_stat_in.flag.bits.voice_attention_left = 1;
//	voice_set_flag(SPEAK_IN, VOICE_ATTENTION_LEFT);

}
