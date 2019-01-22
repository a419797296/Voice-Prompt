/*
 * globals.h
 *
 *  Created on: 2016-09-05
 *      Author: Wu Fan
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
/*******************************************************************************
* Includes
********************************************************************************/
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/*******************************************************************************
* Constants
********************************************************************************/


/*******************************************************************************
* Macros
********************************************************************************/


/*******************************************************************************
* Types
********************************************************************************/


/*******************************************************************************
* Variables
********************************************************************************/


/*******************************************************************************
* Global Variables
********************************************************************************/
/* ��������ȫ�ֱ��� */
extern volatile uint16_t Scheduler_CNT;
extern volatile bool Scheduler_Flag_10ms;
extern volatile bool Scheduler_Flag_100ms;
extern volatile bool Scheduler_Flag_500ms;
extern volatile bool Scheduler_Flag_1000ms;

/* ��������ȫ�ֱ��� End */

/* ��ʱ����ȫ�ֱ��� */
extern volatile uint16_t u16DelayTime_100us;
/* ��ʱ����ȫ�ֱ��� End */


/*******************************************************************************
* Global Functions
********************************************************************************/
extern void System_Scheduler(void);
void Delay_100us(uint16_t n100us);

#endif /* GLOBAL_VARIABLES_H_ */