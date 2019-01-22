/* ###################################################################
**     Filename    : Events.c
**     Project     : Voice Prompt
**     Processor   : SKEAZ64MLH4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-04-27, 16:42, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"
#include  <string.h>
#include "Bluetooth_bsp.h"
#include "time_base.h"
#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

#include "GREEN.h"
#include "CAN.h"
#include "globals.h"
#include "Voice.h"
#include "CAN_bsp.h"
//#include "logic_config.h"
/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [SKEAZ128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  CAN_OnFreeTxBuffer (module Events)
**
**     Component   :  CAN [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the buffer is empty after a
**         successful transmit of a message. This event is available
**         only if method SendFrame is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     @param
**         BufferIdx       - Receive message buffer index.
*/
/* ===================================================================*/
void CAN_OnFreeTxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx)
{
  /* Write your code here ... */
	/*static int test= 0 ;;
	test+=1;
	can_send_frame.Data[0]+=1;*/
	//play_voice(voice_be_attention);
}

/*
** ===================================================================
**     Event       :  CAN_OnFullRxBuffer (module Events)
**
**     Component   :  CAN [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the buffer is full after a
**         successful receive a message. This event is available only
**         if method ReadFrame or SetRxBufferState is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     @param
**         BufferIdx       - Transmit buffer index.
*/
/* ===================================================================*/
void CAN_OnFullRxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx)
{
  /* Write your code here ... */
	CAN_ReadFrame(UserDataPtr,BufferIdx,&can_rev_frame);
	can_resolve();
}

/*
** ===================================================================
**     Event       :  INT_1MS_OnInterrupt (module Events)
**
**     Component   :  INT_1MS [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void INT_1MS_OnInterrupt(void)
{
  /* Write your code here ... */
	TmBaseCnt(&tm_base);
//	Scheduler_CNT++;
//	if(Scheduler_CNT % 10==0)
//	{
//		Scheduler_Flag_10ms = TRUE;
//
//	}
//	if(Scheduler_CNT  % 100==0)
//	{
//		Scheduler_Flag_100ms = TRUE;
//	}
//	if(Scheduler_CNT  % 500==0)
//	{
//		Scheduler_Flag_500ms = TRUE;
//	}
//	if(Scheduler_CNT  % 1000==0)
//	{
//		Scheduler_Flag_1000ms = TRUE;
//	}
}

/*
** ===================================================================
**     Event       :  Delay_100us_OnInterrupt (module Events)
**
**     Component   :  Delay_100us [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Delay_100us_OnInterrupt(void)
{
  /* Write your code here ... */
	u16DelayTime_100us++;
}

/*
** ===================================================================
**     Event       :  LIN_OnError (module Events)
**
**     Component   :  LIN [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LIN_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LIN_OnRxChar (module Events)
**
**     Component   :  LIN [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LIN_OnRxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LIN_OnTxChar (module Events)
**
**     Component   :  LIN [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LIN_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LIN_OnFullRxBuf (module Events)
**
**     Component   :  LIN [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LIN_OnFullRxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  LIN_OnFreeTxBuf (module Events)
**
**     Component   :  LIN [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LIN_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  BlueTooth_OnError (module Events)
**
**     Component   :  BlueTooth [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BlueTooth_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  BlueTooth_OnRxChar (module Events)
**
**     Component   :  BlueTooth [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BlueTooth_OnRxChar(void)
{
  /* Write your code here ... */
	BT_resolve();
}

/*
** ===================================================================
**     Event       :  BlueTooth_OnTxChar (module Events)
**
**     Component   :  BlueTooth [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BlueTooth_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  BlueTooth_OnFullRxBuf (module Events)
**
**     Component   :  BlueTooth [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BlueTooth_OnFullRxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  BlueTooth_OnFreeTxBuf (module Events)
**
**     Component   :  BlueTooth [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BlueTooth_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
