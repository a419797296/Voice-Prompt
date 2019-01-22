/*
 * logic_voice.c
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */
#include "logic_voice.h"
#include "logic_com.h"
#include "CAN.h"
#include "CAN_bsp.h"
#include "Bluetooth_bsp.h"
#include "Voice.h"
#include "globals.h"
void voice_resolve(byte * id_data_p)
{
	REV_DATA_VOICE_P voice_p = (REV_DATA_VOICE_P)id_data_p;

	if(working_mode == mode_stop || working_mode == mode_pause)
		return;

	voice_set_flag(SPEAK_IN, voice_p->DATA0.data);
	voice_set_flag(SPEAK_OUT, voice_p->DATA1);


}
