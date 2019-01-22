/*
 * Button.c
 *
 *  Created on: 2018Äê7ÔÂ10ÈÕ
 *      Author: Administrator
 */


#include "BTN0.h"
#include "BTN1.h"

#include "Button.h"

#include "GREEN.h"
#include "System_logic.h"
//#include "logic_config.h"
#include "Voice.h"

BTN_PARA BTN_para[BTN_NUM]={
	{BTN_unpress,0},
	{BTN_unpress,0},
	//{BTN_unpress,0},
	//{BTN_unpress,0},
	//{BTN_unpress,0},
};


static void BTN_unpress_fuc(byte num);
static void BTN_press_fuc(byte num);
static void BTN_value_press_fuc(byte num);
static void BTN_3s_press_fuc(byte num);
static void BTN_6s_press_fuc(byte num);
static void BTN_release_fuc(byte num);


void BTN_check(void)
{
	bool BTN_io[BTN_NUM];
	byte i;
	BTN_io[0] = BTN0_GetVal();		//trig by low level
	BTN_io[1] = BTN1_GetVal();		//trig by low level
	//BTN_io[2] = SW2_GetVal();		//trig by low level
	//BTN_io[3] = BTN0_GetVal();		//trig by high level
	//BTN_io[4] = BTN1_GetVal();		//trig by high level

	for(i=0;i<BTN_NUM;i++)
	{
		if(BTN_io[i])
		{
			BTN_para[i].count++;
			if(BTN_para[i].count > COUNT_6S )
				BTN_para[i].stat = BTN_6s_press;
			else if(BTN_para[i].count > COUNT_3S )
				BTN_para[i].stat = BTN_3s_press;
			else if(BTN_para[i].count > COUNT_value )
				BTN_para[i].stat = BTN_value_press;
			else
				BTN_para[i].stat = BTN_press;
		}
		else
		{
			BTN_para[i].count = 0;
			if(BTN_para[i].stat != BTN_unpress)
			{
				BTN_FUNC(i,BTN_release);
			}
			BTN_para[i].stat = BTN_unpress;
		}
	}
}

void BTN_execute(BTN_PARA_P	BTN_para_p)
{
	byte i;
	for(i=0;i<BTN_NUM;i++)
		BTN_FUNC(i,(BTN_para_p+i)->stat);
}
//-------------------------------
static void BTN_unpress_fuc(byte num)
{

}
//-------------------------------
static void BTN_press_fuc(byte num)
{

}
//-------------------------------
static void BTN_value_press_fuc(byte num)
{
	byte i;
	switch(num)
	{
	case SW0:
		break;
	case SW1:
		break;
	case SW2:
		break;
	case BTN0:
		break;
	case BTN1:
		break;
	default:
		break;
	}
}
//-------------------------------
static void BTN_3s_press_fuc(byte num)
{
	switch(num)
	{
	case SW0:
		break;
	case SW1:
		break;
	case SW2:
		break;
	case BTN0:
		break;
	case BTN1:
		break;
	default:
		break;
	}
}
//-------------------------------
static void BTN_6s_press_fuc(byte num)
{
	;
}
//-------------------------------
static void BTN_release_fuc(byte num)
{
	REV_DATA_FTG_P fatigue_buf_p = (REV_DATA_FTG_P) recv_data_buf[REV_ID_FTG_ADDR];
	if(num == BTN1)
	{
		if(BTN_para[num].stat == BTN_value_press)
		{
			if(working_mode == mode_pause || working_mode == mode_stop)
			{
				working_mode = mode_can;
			}
			else
			{
				if(fatigue_buf_p->DATA0.Bits.FtgGrdWngHSC4 > no_fatigue)
					working_mode = mode_pause;
			}
			load_sys_para();
		}
		else if(BTN_para[num].stat == BTN_3s_press)
		{
			working_mode = mode_stop;
			FATIGUE_FUNC(no_request,(REV_DATA_FTG_P)recv_data_buf[REV_ID_FTG_ADDR]);
			load_sys_para();
		}
		else
		{

		}
//		voice_play_in(voice_addr_in++);
//		if(voice_addr_in > VOICE_ADDR_MAX)
//			voice_addr_in = 0;

	}
	if(num == BTN0)
	{
//		voice_play_out(voice_addr_out++);
//		if(voice_addr_out > VOICE_ADDR_MAX)
//			voice_addr_out = 0;

		voice_play_in(voice_addr_in++);
		if(voice_addr_in > VOICE_ADDR_MAX)
			voice_addr_in = 0;

	}

}


BTN_Func_Ptr BTN_Func[6] =
{
	BTN_unpress_fuc,
	BTN_press_fuc,
	BTN_value_press_fuc,
	BTN_3s_press_fuc,
	BTN_6s_press_fuc,
	BTN_release_fuc,
};

