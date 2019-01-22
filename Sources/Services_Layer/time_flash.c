/*
 * time_flash.c
 *
 *  Created on: 2018Äê11ÔÂ30ÈÕ
 *      Author: Administrator
 */
#include "time_flash.h"
TM_FLSH_FLAG	tm_flash_flag;
TM_FLASH tm_flash[FLASH_EVENT_NUM];

static void flash_ftg_lev1(void);
static void flash_ftg_lev2(void);
static void flash_ftg_lev3(void);
static void flash_exit_smt_drv(void);
static void flash_alarm_manual_drv(void);


TmBase_Func_Ptr TM_FLASH_Func[FLASH_EVENT_NUM] = {
	flash_ftg_lev1,
	flash_ftg_lev2,
	flash_ftg_lev3,
	flash_exit_smt_drv,
	flash_alarm_manual_drv,

};


static void flash_ftg_lev1(void)
{
	if(lb_stat.lb_mode != lb_fatigue)
		return;
	LED_RED_NegVal();
	BEEP_NegVal();
	safety_alarm = safety_belt_alarm_none;
	Lightbar_Set(LB_RED_FLASH_LOW);
}
static void flash_ftg_lev2(void)
{
	if(lb_stat.lb_mode != lb_fatigue)
		return;
	LED_RED_NegVal();
	BEEP_NegVal();
	MOTOR_NegVal();
	//out put of safe balt
	safety_alarm = safety_belt_alarm_grade1;
	Lightbar_Set(LB_RED_FLASH_MID);
}
static void flash_ftg_lev3(void)
{
	if(lb_stat.lb_mode != lb_fatigue)
		return;
	LED_RED_NegVal();
	BEEP_NegVal();
	safety_alarm = safety_belt_alarm_grade2;
	Lightbar_Set(LB_RED_FLASH_HIGH);
}
static void flash_exit_smt_drv(void)
{
	MOTOR_NegVal();

}
static void flash_alarm_manual_drv(void)
{
	MOTOR_NegVal();

}



void time_flash_init(void)   //flash event register
{
	tm_flash[ftg_lev1].tm_base = tm_1s;
	tm_flash[ftg_lev1].cnt_finish = 0xffff;

	tm_flash[ftg_lev2].tm_base = tm_500ms;
	tm_flash[ftg_lev2].cnt_finish = 0xffff;

	tm_flash[ftg_lev3].tm_base = tm_100ms;
	tm_flash[ftg_lev3].cnt_finish = 0xffff;

	tm_flash[exit_smt_drv].tm_base = tm_500ms;
	tm_flash[exit_smt_drv].cnt_finish = 6;

	tm_flash[alarm_manual_drv].tm_base = tm_100ms;
	tm_flash[alarm_manual_drv].cnt_finish = 6;
}
//ftg_lev1,
//ftg_lev2,
//ftg_lev3,
//exit_smt_drv,
//alarm_manual_drv,
void time_flash_set_flag(TM_FLASH_IDX tm_flash_idx)   //flash set flag
{
	byte i;

	dword mask = 0;

	if(tm_flash_idx <=ftg_lev3)
	{
		for(i=0;i<3;i++)
		{
			if(tm_flash_idx == i)
				tm_flash[i].flag = 1;
			else
				tm_flash[i].flag = 0;
		}
		mask = 1 << tm_flash_idx;
		tm_flash_flag.flag.bytes &= (0xfff8+mask);

	}
	else
	{
		tm_flash[tm_flash_idx].flag = 1;
		tm_flash_flag.flag.bytes |= (1<<tm_flash_idx);
	}


	tm_flash[tm_flash_idx].cnt = 0;
}

void time_flash_resolve(TM_IDX tm_idx)   //flash event register
{
	byte i;
	dword flag_mask;
	if(working_mode == mode_stop || working_mode == mode_pause)
		return;
	for(i=0;i<FLASH_EVENT_NUM;i++)
	{
		flag_mask = 1<<i;

		if(tm_flash[i].tm_base != tm_idx)
			continue;
//		if(tm_flash_flag.flag.bytes & flag_mask)
		if(tm_flash[i].flag)
		{
			if(tm_flash[i].cnt++ >= tm_flash[i].cnt_finish)
				tm_flash[i].flag = 0;
//				tm_flash_flag.flag.bytes &= ~flag_mask;
			else
				TM_FLASH_FUNC(i);
		}
	}
}
