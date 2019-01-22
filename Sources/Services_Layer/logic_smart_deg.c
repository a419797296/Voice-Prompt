/*
 * logic_smart_deg.c
 *
 *  Created on: 2018Äê11ÔÂ19ÈÕ
 *      Author: Administrator
 */
#include "logic_smart_deg.h"
#include "time_flash.h"
void smart_deg_resolve(byte * id_data_p)
{
	REV_DATA_DEG_P smart_deg_p = (REV_DATA_DEG_P)id_data_p;

	switch(smart_deg_p->sig)
	{
	case	0x01:        //performance degradation
		Lightbar_Set(LB_RED_FLASH_THRICE);
		voice_set_flag(SPEAK_IN, ALARM_BUG_MID_SPEED);
		tm_flash_flag.flag.bits.exit_smt_drv = 1;
		time_flash_set_flag(exit_smt_drv);
		smart_drive_stat = quit;
		break;
	case	0x02:		//system unavailable
		Lightbar_Set(LB_RED_FLASH_THRICE);
		voice_set_flag(SPEAK_IN, ALARM_BUG_HIGH_SPEED);
		tm_flash_flag.flag.bits.exit_smt_drv = 1;
		time_flash_set_flag(exit_smt_drv);
		smart_drive_stat = quit;
		break;

	default:
		break;
	}
}
