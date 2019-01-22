/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Pins1.h"
#include "GREEN.h"
#include "BitIoLdd2.h"
#include "BTN1.h"
#include "BitIoLdd3.h"
#include "BitIoLdd4.h"
#include "CAN.h"
#include "BlueTooth.h"
#include "ASerialLdd1.h"
#include "OUT_SDN.h"
#include "BitIoLdd5.h"
#include "BTN0.h"
#include "BitIoLdd6.h"
#include "IN_BUSY.h"
#include "BitIoLdd21.h"
#include "IN_RST.h"
#include "BitIoLdd22.h"
#include "LIGHT_BAR.h"
#include "BitsIoLdd1.h"
#include "OUT_DATA1.h"
#include "BitIoLdd7.h"
#include "BitIoLdd9.h"
#include "TJA1028_EN.h"
#include "BitIoLdd12.h"
#include "LIN.h"
#include "ASerialLdd2.h"
#include "Flash_C.h"
#include "BitIoLdd13.h"
#include "BEEP.h"
#include "BitIoLdd19.h"
#include "MOTOR.h"
#include "BitIoLdd20.h"
#include "IN_SDN.h"
#include "BitIoLdd1.h"
#include "IN_DATA1.h"
#include "LED_GREEN.h"
#include "BitIoLdd14.h"
#include "LED_RED.h"
#include "BitIoLdd15.h"
#include "INT_1MS.h"
#include "TimerIntLdd1.h"
#include "FTM0.h"
#include "Delay_100us.h"
#include "TimerIntLdd2.h"
#include "FTM1.h"
#include "OUT_BUSY.h"
#include "BitIoLdd16.h"
#include "OUT_RST.h"
#include "BitIoLdd17.h"
#include "TJA1040_STB.h"
#include "BitIoLdd18.h"
#include "BCM_sig.h"

#ifdef __cplusplus
extern "C" {
#endif 

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
void Cpu_OnNMI(void);


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
void CAN_OnFreeTxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx);

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
void CAN_OnFullRxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx);

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
void INT_1MS_OnInterrupt(void);

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
void Delay_100us_OnInterrupt(void);

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
void LIN_OnError(void);

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
void LIN_OnRxChar(void);

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
void LIN_OnTxChar(void);

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
void LIN_OnFullRxBuf(void);

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
void LIN_OnFreeTxBuf(void);

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
void BlueTooth_OnError(void);

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
void BlueTooth_OnRxChar(void);

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
void BlueTooth_OnTxChar(void);

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
void BlueTooth_OnFullRxBuf(void);

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
void BlueTooth_OnFreeTxBuf(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
