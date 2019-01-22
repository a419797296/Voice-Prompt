/*
 * Voice.c
 *
 *  Created on: 2018年6月1日
 *      Author: Administrator
 */
#include "Voice.h"

#include "globals.h"

#include "IN_BUSY.h"
#include "IN_RST.h"
#include "IN_SDN.h"
#include "IN_DATA1.h"

#include "OUT_BUSY.h"
#include "OUT_RST.h"
#include "OUT_SDN.h"
#include "OUT_DATA1.h"

byte voice_loop_count = 0;
byte voice_addr_in = 0, voice_addr_out = 0;
VOICE_FLAG_STAT 	voice_flag_stat_in,voice_flag_stat_out;
VOICE_FLAG_STAT 	voice_flag_stat_in_back,voice_flag_stat_out_back;


void voice_init(void)
{
	IN_SDN_SetVal();			//使能内喇叭
	OUT_SDN_SetVal();			//使能外喇叭
}

bool voice_set_flag(byte num, byte addr)
{
	dword mask = 1<<addr;

	if(addr == MUTE)    //illegal addr
		return FALSE;
	if(addr >= VOICE_ADDR_MAX)    //illegal addr
		return FALSE;

	if(num == SPEAK_IN)
	{
		if(voice_flag_stat_in.flag.bytes & mask)    //have not play the voice
			return FALSE;
		voice_flag_stat_in.flag.bytes|=mask;
		if(voice_flag_stat_in.flag.bytes == voice_flag_stat_in_back.flag.bytes)
		{
			voice_flag_stat_in.flag.bytes &= ~mask;
		}
		else
		{
			voice_flag_stat_in_back = voice_flag_stat_in;
		}
	}

	if(num == SPEAK_OUT)
	{
		if(voice_flag_stat_out.flag.bytes & mask)    //have not play the voice
			return FALSE;
		voice_flag_stat_out.flag.bytes|=mask;
		if(voice_flag_stat_out.flag.bytes == voice_flag_stat_out_back.flag.bytes)
		{
			voice_flag_stat_out.flag.bytes &= ~mask;
		}
		else
		{
			voice_flag_stat_out_back = voice_flag_stat_out;
		}
	}
	return TRUE;
}

bool voice_play(void)
{
	byte i;
	dword flag_mask;



	for(i=0;i<VOICE_ADDR_MAX;i++)
	{
		flag_mask = 1<<i;

		if(voice_flag_stat_in.flag.bytes & flag_mask)
		{
			if(voice_play_in(i))
			{
				voice_flag_stat_in.flag.bytes &= ~flag_mask;
			}
		}
		if(voice_flag_stat_out.flag.bytes & flag_mask)
		{
			if(voice_play_out(i))
			{
				voice_flag_stat_out.flag.bytes &= ~flag_mask;
			}
		}
	}
	return TRUE;
}



bool voice_play_in(byte addr)
{
	int i;
	if(IN_BUSY_GetVal()==0)
		return FALSE;             //if busy, then return

	if(addr == MUTE)    //illegal addr
		return FALSE;
	if(addr > VOICE_ADDR_MAX)    //illegal addr
		return FALSE;

	//MUTE_ClrVal();
	//Delay_100us(3);

	IN_SDN_SetVal();
//	OUT_SDN_ClrVal();        //disable out AMP
	Delay_100us(100);

	IN_RST_ClrVal();
	Delay_100us(3);
	IN_RST_SetVal();
	Delay_100us(3);
	IN_RST_ClrVal();

	IN_DATA1_ClrVal();
	Delay_100us(50);
	for(i=0;i<=addr;i++)
	{
		IN_DATA1_SetVal();
		Delay_100us(3);
		IN_DATA1_ClrVal();
		Delay_100us(3);

	}


	//MUTE_SetVal();
	return TRUE;
}

bool voice_play_out(byte addr)
{
	int i;
	if(OUT_BUSY_GetVal()==0)
		return FALSE;             //if busy, then return

	if(addr == MUTE)    //illegal addr
		return FALSE;
	if(addr > VOICE_ADDR_MAX)    //illegal addr
		return FALSE;

//	IN_SDN_ClrVal();			//disable in AMP
	OUT_SDN_SetVal();
	Delay_100us(100);

	OUT_RST_ClrVal();
	Delay_100us(3);
	OUT_RST_SetVal();
	Delay_100us(3);
	OUT_RST_ClrVal();

	OUT_DATA1_ClrVal();
	Delay_100us(50);
	for(i=0;i<=addr;i++)
	{
		OUT_DATA1_SetVal();
		Delay_100us(3);
		OUT_DATA1_ClrVal();
		Delay_100us(3);

	}


	//MUTE_SetVal();
	return TRUE;
}

