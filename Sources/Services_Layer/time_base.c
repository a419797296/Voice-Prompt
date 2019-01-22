/*
 * time_base.c
 *
 *  Created on: Nov 22, 2018
 *      Author: Administrator
 */
#include "time_base.h"
#include "time_flash.h"
TM_BASE tm_base;

static void fuc_10ms(void);
static void fuc_50ms(void);
static void fuc_100ms(void);
static void fuc_500ms(void);
static void fuc_1s(void);
static void fuc_5s(void);

TmBase_Func_Ptr TM_BASE_Func[TM_BASE_TYPE] = {
		fuc_10ms,
		fuc_50ms,
		fuc_100ms,
		fuc_500ms,
		fuc_1s,
		fuc_5s,
//		fuc_10s,
//		fuc_50s,
};
byte motor_idx = 0;


void TmBaseCnt(TM_BASE_P tm_base)
{
	tm_base->tm_count_1ms++;
	if(tm_base->tm_count_1ms == 10)
	{
		tm_base->tm_count_1ms = 0;
		tm_base->tm_count_10ms++;
		tm_base->tm_flag.B.tm_flag_10ms = 1;
		if(tm_base->tm_count_10ms == 5)
		{
			tm_base->tm_count_10ms = 0;
			tm_base->tm_count_50ms++;
			tm_base->tm_flag.B.tm_flag_50ms = 1;
			if(tm_base->tm_count_50ms == 2)
			{
				tm_base->tm_count_50ms = 0;
				tm_base->tm_count_100ms++;
				tm_base->tm_flag.B.tm_flag_100ms = 1;
				if(tm_base->tm_count_100ms == 5)
				{
					tm_base->tm_count_100ms = 0;
					tm_base->tm_count_500ms++;
					tm_base->tm_flag.B.tm_flag_500ms = 1;
					if(tm_base->tm_count_500ms == 2)
					{
						tm_base->tm_count_500ms = 0;
						tm_base->tm_count_1s++;
						tm_base->tm_flag.B.tm_flag_1s = 1;
						if(tm_base->tm_count_1s == 5)
						{
							tm_base->tm_count_1s = 0;
							tm_base->tm_count_5s++;
							tm_base->tm_flag.B.tm_flag_5s = 1;
						}
					}
				}
			}
		}
	}
}

void TmBaseSolve(TM_BASE_P tm_base)
{
	byte i;
	word flag_mask;

	tm_flash_flag.flag.bits.alarm_manual_drv = 1;
	tm_flash[FLASH_ALARM_MANUAL_DRV].flag = 1;
	can_flag_stat.flag.bits.torque = 1;

	for(i=0;i<TM_BASE_TYPE;i++)
	{
		flag_mask = 1<<i;
		if(tm_base->tm_flag.R & flag_mask)
		{
			TM_BASE_FUNC(i);
			time_flash_resolve((TM_IDX)i);
			tm_base->tm_flag.R &= ~flag_mask;

		}
	}
}

static void fuc_10ms(void)
{
	tm_base.tm_flag.B.tm_flag_10ms = 0;
	BTN_check();
	BTN_execute(BTN_para);
}
static void fuc_50ms(void)
{
	tm_base.tm_flag.B.tm_flag_50ms = 0;
	load_sys_para();
	Delay_100us(10);
	load_atmosphere_lamp_mode();
}

static void fuc_100ms(void)
{
	tm_base.tm_flag.B.tm_flag_100ms = 0;
	logic_resolve(&can_flag_stat);
}
static void fuc_500ms(void)
{
	tm_base.tm_flag.B.tm_flag_500ms = 0;
}
static void fuc_1s(void)
{
	tm_base.tm_flag.B.tm_flag_1s = 0;
	voice_play();
	GREEN_SetVal();

}
static void fuc_5s(void)
{
	tm_base.tm_flag.B.tm_flag_5s = 0;
}

