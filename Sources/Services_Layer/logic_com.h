/*
 * logic_com.h
 *
 *  Created on: 2018Äê11ÔÂ12ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_COM_H_
#define SOURCES_SERVICES_LAYER_LOGIC_COM_H_
#include "PE_Types.h"
#include "Voice.h"
#include "globals.h"

#include "BEEP.h"
#include "MOTOR.h"
#include "LED_GREEN.h"
#include "LED_RED.h"
#include "Lightbar.h"

#include "Flash_C.h"
#include "BCM_sig.h"

#include "GREEN.h"
#include "Button.h"

#define COMMUNICATE_CAN				0
#define COMMUNICATE_BLUETOOTH		1


typedef enum
{
	mode_can,
	mode_bluetooth,
	mode_pause,
	mode_stop,
}WORK_MODE;



extern WORK_MODE			working_mode;



extern void logic_save_data(word logic_id, byte * src_data, word length);

#endif /* SOURCES_SERVICES_LAYER_LOGIC_COM_H_ */
