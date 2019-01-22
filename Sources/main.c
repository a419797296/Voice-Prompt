/* ###################################################################
**     Filename    : main.c
**     Project     : Voice Prompt
**     Processor   : SKEAZ64MLH4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-04-27, 16:42, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include "time_base.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include "globals.h"
#include "System_logic.h"
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */



int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  logic_init();
  TmBaseSolve(&tm_base);

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
