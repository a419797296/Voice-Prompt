/*
 * globals.c
 *
 *  Created on: 2016-09-05
 *      Author: Wu Fan
 */
 
#include "globals.h"

#include "GREEN.h"
#include "BTN1.h"
#include "BTN0.h"
#include "CAN.h"
#include "globals.h"
#include "Delay_100us.h"
#include "Voice.h"
#include "TJA1040_STB.h"
#include "CAN_bsp.h"
#include "Bluetooth_bsp.h"
#include "Button.h"
#include "System_logic.h"

/**********************************************************************************************
* External objects
**********************************************************************************************/


/**********************************************************************************************
* Global variables
**********************************************************************************************/
/* 调度所用全局变量 */
volatile uint16_t Scheduler_CNT = 0;
volatile bool Scheduler_Flag_10ms = FALSE;
volatile bool Scheduler_Flag_100ms = FALSE;
volatile bool Scheduler_Flag_500ms = FALSE;
volatile bool Scheduler_Flag_1000ms = FALSE;
/* 调度所用全局变量 End */

/* 延时所用全局变量 */
volatile uint16_t u16DelayTime_100us = 0;
/* 延时所用全局变量 End */



/**********************************************************************************************
* Global variables
**********************************************************************************************/

/**********************************************************************************************
* Constants and macros
**********************************************************************************************/


/**********************************************************************************************
* Local types
**********************************************************************************************/


/**********************************************************************************************
* Local function prototypes
*********************************************************************************************/

/**********************************************************************************************
* Local variables
**********************************************************************************************/

/**********************************************************************************************
* Global functions
**********************************************************************************************/


/***********************************************************************************************
*
* @brief    System_Scheduler - 系统调度.
* @param    none.
* @return   none.
*
************************************************************************************************/
void System_Scheduler(void)
{
	uint8_t *data_p;
	dword	flag_mask;
	if(Scheduler_Flag_10ms == TRUE)
	{
		Scheduler_Flag_10ms = FALSE;
		BTN_check();
		BTN_execute(BTN_para);



	}
	if(Scheduler_Flag_100ms == TRUE)
	{
		Scheduler_Flag_100ms = FALSE;
		tm_flag.tm_100ms_flag = TRUE;
		logic_resolve(&can_flag_stat);
	}
	if(Scheduler_Flag_500ms == TRUE)
	{
		Scheduler_Flag_500ms = FALSE;
		tm_flag.tm_500ms_flag = TRUE;

	}
	if(Scheduler_Flag_1000ms == TRUE)
	{
		Scheduler_Flag_1000ms = FALSE;
		tm_flag.tm_1000ms_flag = TRUE;

//		logic_resolve(&can_flag_stat);
		voice_play();
		GREEN_SetVal();
	}

}
/***********************************************************************************************
*
* @brief    Delay_100us - 延时程序.
* @param    n100us - specifies the delay time length, in 100us.
* @return   none.
*
************************************************************************************************/
void Delay_100us(uint16_t n100us)
{
	u16DelayTime_100us = 0;
	Delay_100us_Enable();
	while(u16DelayTime_100us < n100us)
	{
	}
	Delay_100us_Disable();
}
