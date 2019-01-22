/*
 * logic_voice.h
 *
 *  Created on: 2018Äê10ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_VOICE_H_
#define SOURCES_SERVICES_LAYER_LOGIC_VOICE_H_
#include "PE_Types.h"
//--------------------------------------------------------
typedef struct CAN_REV_DATA_VOICE
{
	union
     {
         byte data;
         struct
         {
        	byte	undefined			:8;
         }Bits;
     }DATA0;
	byte	DATA1;
	byte	DATA2;
	byte	DATA3;
    byte	DATA4;
    byte	DATA5;
    byte	DATA6;
    byte	DATA7;
}REV_DATA_VOICE, *REV_DATA_VOICE_P;

extern void voice_resolve(byte * id_data_p);

#endif /* SOURCES_SERVICES_LAYER_LOGIC_VOICE_H_ */
