/*
 * logic_speed.c
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */


#include "logic_speed.h"
#include "Voice.h"
void speed_resolve(byte * id_data_p)
{

	REV_DATA_SPEED_P speed_p = (REV_DATA_SPEED_P)id_data_p;

//	voice_flag_stat_in.flag.bits.voice_attention_fr = 1;
	voice_set_flag(SPEAK_IN, VOICE_ATTENTION_FR);
}
