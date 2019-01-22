/*
 * Button.h
 *
 *  Created on: 2018Äê7ÔÂ10ÈÕ
 *      Author: Administrator
 */
#include "BTN1.h"
#include "BTN0.h"

#ifndef SOURCES_BUTTON_H_
#define SOURCES_BUTTON_H_

#define VALUE_BUTTON	1
#define TIME_BASE		10   //MS
#define	COUNT_value		(30/TIME_BASE)
#define	COUNT_3S		(3000/TIME_BASE)
#define	COUNT_6S		(6000/TIME_BASE)
#define BTN_NUM			2
#define BTN0			0
#define BTN1			1
#define SW0				2
#define SW1				3
#define SW2				4



typedef enum {
	BTN_unpress,
	BTN_press,
	BTN_value_press,
	BTN_3s_press,
	BTN_6s_press,
	BTN_release
} BTN_STAT;

typedef struct {
	BTN_STAT	 	stat;
	word		count;
} BTN_PARA,*BTN_PARA_P;


typedef void(*BTN_Func_Ptr)(byte);
#define BTN_FUNC(num,BTN_STAT) (BTN_Func[BTN_STAT](num))

BTN_Func_Ptr BTN_Func[6];
extern BTN_PARA BTN_para[BTN_NUM];



extern void BTN_check(void);
extern void BTN_execute(BTN_PARA_P	BTN_para_p);
#endif /* SOURCES_BUTTON_H_ */
