/*
 * logic_com.c
 *
 *  Created on: 2018年11月12日
 *      Author: Administrator
 */
#include "logic_com.h"
#include  <string.h>
#include "System_logic.h"

WORK_MODE			working_mode;



static uint8_t *logic_find_data_pt(word logic_id);
static dword logic_find_flag_mask(word logic_id);


static uint8_t *logic_find_data_pt(word logic_id)
{
	int i;
//	logic_id = (word)((logic_id & 0xff) << 8 | (logic_id & 0xFF00U) >> 8);     //翻转接收到的字节序
	for(i=0;i<RECV_ID_NUM;i++)
	{
		if(logic_frame[i].MessageID == logic_id)
			return logic_frame[i].Data;
	}
	return FALSE;
}

static dword logic_find_flag_mask(word logic_id)
{
	int i;
//	logic_id = (word)((logic_id & 0xff) << 8 | (logic_id & 0xFF00U) >> 8);     //翻转接收到的字节序
	for(i=0;i<RECV_ID_NUM;i++)
	{
		if(logic_frame[i].MessageID == logic_id)
			return (1<<i);
	}
	return FALSE;
}

void logic_save_data(word logic_id, byte * src_data, word length)
{
	uint8_t *data_p;
	dword	flag_mask;

	if(working_mode == mode_stop)
	{
		//load_sys_para();
		return;
	}
	data_p = logic_find_data_pt(logic_id);
	flag_mask = logic_find_flag_mask(logic_id);


	if(data_p == FALSE || flag_mask == FALSE)
	{
		GREEN_ClrVal();
		working_mode = mode_can;
		load_sys_para();
		return;
	}
	memcpy(data_p,src_data,length);
	can_flag_stat.flag.bytes |= flag_mask;
}
