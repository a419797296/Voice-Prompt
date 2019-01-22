/*
 * Lightbar.h
 *
 *  Created on: 2018Äê11ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_ECU_ABSTRACTION_LAYER_LIGHTBAR_H_
#define SOURCES_ECU_ABSTRACTION_LAYER_LIGHTBAR_H_
#include "LIGHT_BAR.h"

#define LB_OFF					0X00
#define LB_RED_FLASH_TWICE		0X01
#define LB_RED_FLASH_THRICE		0X02
#define LB_RED_FLASH_MORE		0X03
#define LB_RED_FLASH_LOW		0X0C
#define LB_RED_FLASH_MID		0X0D
#define LB_RED_FLASH_HIGH		0X0E

#define LB_GREEN_DARK			0X09
#define LB_GREEN_BRIGHT			0X0A

#define LB_BLUE_DARK			0XFF

typedef enum {
   lb_fatigue,
   lb_smart_drive,
} LB_MODE;

typedef struct LB_STAT
{
	byte 		out_stat;
	LB_MODE		lb_mode;
}LB_STAT,*LB_STAT_P;
extern LB_STAT lb_stat;

extern void Lightbar_Set(byte stat);
extern void Lightbar_Init(LB_STAT_P lb_stat_p);
#endif /* SOURCES_ECU_ABSTRACTION_LAYER_LIGHTBAR_H_ */
