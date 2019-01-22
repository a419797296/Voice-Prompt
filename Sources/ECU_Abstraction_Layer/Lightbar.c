/*
 * Lightbar.c
 *
 *  Created on: 2018Äê11ÔÂ19ÈÕ
 *      Author: Administrator
 */
#include "Lightbar.h"


LB_STAT lb_stat;
static LB_MODE Lightbar_judge_mode(LB_STAT_P lb_stat_p);



static LB_MODE Lightbar_judge_mode(LB_STAT_P lb_stat_p)
{
	switch(lb_stat_p->out_stat)
	{
	case LB_RED_FLASH_TWICE:
	case LB_RED_FLASH_THRICE:
	case LB_RED_FLASH_MORE:
	case LB_GREEN_DARK:
	case LB_GREEN_BRIGHT:
		lb_stat_p->lb_mode = lb_smart_drive;
		break;
	default:
		lb_stat_p->lb_mode = lb_fatigue;
		break;
	}
	return lb_stat_p->lb_mode;
}

void Lightbar_Init(LB_STAT_P lb_stat_p)
{
	lb_stat_p->lb_mode = lb_fatigue;
	lb_stat_p->out_stat = LB_BLUE_DARK;
	Lightbar_Set(lb_stat_p->out_stat);
}
void Lightbar_Set(byte stat)
{
	byte i;
	LB_STAT_P lb_stat_p = &lb_stat;
	lb_stat_p -> out_stat = stat;                             //save stat
	lb_stat_p ->lb_mode = Lightbar_judge_mode(lb_stat_p);		//judege working mode
	for(i=0;i<4;i++)
	{
		if(stat&(1<<i))
		{
			LIGHT_BAR_SetBit(i);
		}
		else
		{
			LIGHT_BAR_ClrBit(i);
		}
	}
}
