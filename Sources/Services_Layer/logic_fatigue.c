/*
 * logic_fatigue.c
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "logic_fatigue.h"
#include "logic_com.h"
#include "logic_smart_drive.h"
#include "time_flash.h"
SAFETY_BELT_ALARM	safety_alarm = safety_belt_alarm_none;
SYS_TM_FLAG			tm_flag= {FALSE,FALSE,FALSE};

static void fatigue_no_request_fuc(REV_DATA_FTG_P fatigue_p);
static void fatigue_no_fatigue_fuc(REV_DATA_FTG_P fatigue_p);
static void fatigue_grade1_fuc(REV_DATA_FTG_P fatigue_p);
static void fatigue_grade2_fuc(REV_DATA_FTG_P fatigue_p);
static void fatigue_grade3_fuc(REV_DATA_FTG_P fatigue_p);



Fatigue_Func_Ptr FATIGUE_Func[FATIGUE_LAVEL] = {
		fatigue_no_request_fuc,
		fatigue_no_fatigue_fuc,
		fatigue_grade1_fuc,
		fatigue_grade2_fuc,
		fatigue_grade3_fuc
};

void fatigue_init(void)
{
	working_mode = mode_stop;
}

static void fatigue_no_request_fuc(REV_DATA_FTG_P fatigue_p)
{
	LED_GREEN_SetVal();
	LED_RED_ClrVal();
	BEEP_ClrVal();
//	if(lb_stat.lb_mode == lb_fatigue)
	{
		Lightbar_Set(LB_BLUE_DARK);

		MOTOR_ClrVal();
		Flash_C_SetVal();
		tm_flash_flag.flag.bytes &= (0xfff8+0);
		tm_flash[FLASH_FTG_LEV1].flag = 0;
		tm_flash[FLASH_FTG_LEV2].flag = 0;
		tm_flash[FLASH_FTG_LEV3].flag = 0;
		fatigue_p->DATA0.Bits.FtgGrdWngHSC4 = no_request;
		safety_alarm = safety_belt_alarm_none;
	}


}

static void fatigue_no_fatigue_fuc(REV_DATA_FTG_P fatigue_p)
{
	LED_GREEN_SetVal();
	LED_RED_ClrVal();
	BEEP_ClrVal();
//	if(lb_stat.lb_mode == lb_fatigue)
	{
		Lightbar_Set(LB_BLUE_DARK);

		MOTOR_ClrVal();
		Flash_C_SetVal();
		tm_flash_flag.flag.bytes &= (0xfff8+0);
		tm_flash[FLASH_FTG_LEV1].flag = 0;
		tm_flash[FLASH_FTG_LEV2].flag = 0;
		tm_flash[FLASH_FTG_LEV3].flag = 0;
		fatigue_p->DATA0.Bits.FtgGrdWngHSC4 = no_fatigue;
		safety_alarm = safety_belt_alarm_none;
	}
}
static void fatigue_grade1_fuc(REV_DATA_FTG_P fatigue_p)
{
	LED_GREEN_ClrVal();
	tm_flash_flag.flag.bytes &= (0xfff8+1);
	time_flash_set_flag(ftg_lev1);
	MOTOR_ClrVal();
//	if(tm_flag.tm_1000ms_flag)
//	{
//		tm_flag.tm_1000ms_flag = FALSE;
//		LED_RED_NegVal();
//		BEEP_NegVal();
//		safety_alarm = safety_belt_alarm_none;
//		if(lb_stat.lb_mode == lb_fatigue)
//			Lightbar_Set(LB_RED_FLASH_LOW);
//	}
	Flash_C_SetVal();
}
static void fatigue_grade2_fuc(REV_DATA_FTG_P fatigue_p)
{
	LED_GREEN_ClrVal();
	tm_flash_flag.flag.bytes &= (0xfff8+2);
	time_flash_set_flag(ftg_lev2);

//	if(tm_flag.tm_500ms_flag)
//	{
//		tm_flag.tm_500ms_flag = FALSE;
//		LED_RED_NegVal();
//		BEEP_NegVal();
//		MOTOR_NegVal();
//		//out put of safe balt
//		safety_alarm = safety_belt_alarm_grade1;
//		if(lb_stat.lb_mode == lb_fatigue)
//			Lightbar_Set(LB_RED_FLASH_MID);
//
//	}
	Flash_C_SetVal();
}
static void fatigue_grade3_fuc(REV_DATA_FTG_P fatigue_p)
{
	LED_GREEN_ClrVal();
	tm_flash_flag.flag.bytes &= (0xfff8+4);
	time_flash_set_flag(ftg_lev3);
//	if(tm_flag.tm_100ms_flag)
//	{
//		tm_flag.tm_100ms_flag = FALSE;
//		LED_RED_NegVal();
//		BEEP_NegVal();
//		safety_alarm = safety_belt_alarm_grade2;
//		if(lb_stat.lb_mode == lb_fatigue)
//			Lightbar_Set(LB_RED_FLASH_HIGH);
//	}
//	MOTOR_NegVal();
	MOTOR_SetVal();
	Flash_C_ClrVal();
}

void fatigue_resolve(byte * id_data_p)
{

	REV_DATA_FTG_P fatigue_p = (REV_DATA_FTG_P)id_data_p;
	if(working_mode == mode_stop || working_mode == mode_pause || smart_drive_stat == smart)
		return;
	if(lb_stat.lb_mode != lb_fatigue)
		return;
	if(fatigue_p->DATA0.Bits.FDFitStsHSC4 == fatigue_no_fault)
	{
		FATIGUE_FUNC(fatigue_p->DATA0.Bits.FtgGrdWngHSC4,fatigue_p);
	}
	else
	{
		;
	}


}



