/*
 * Bluetooth.c
 *
 *  Created on: 2018年6月11日
 *      Author: Administrator
 */

#include "Bluetooth_bsp.h"
#include "logic_com.h"
//#include "GREEN.h"
#include  <string.h>
//#include "CAN.h"
//#include "CAN_bsp.h"
/**********************************************************************************************
* Global variables
**********************************************************************************************/
uint8_t			BT_rev_data_buf[8]={0};
uint8_t			BT_send_data_buf[8]={0};
BT_Frame		BT_rev_frame;
BT_Frame		BT_send_frame;

BT_STAT		BT_stat;
//BT_Frame	BT_frame[RECV_ID_NUM];

/**********************************************************************************************
* Constants and macros
**********************************************************************************************/


///**********************************************************************************************
//* Local types
//**********************************************************************************************/
//static void BT_init_frame(void);
//static uint8_t *BT_find_data_pt(word BT_id);
//static dword BT_find_flag_mask(word can_id);
//
///**********************************************************************************************
//* Local function prototypes
//*********************************************************************************************/
//
//static void BT_init_frame(void)
//{
//	BT_frame[0].Data = (uint8_t *)fatigue_p;
//	BT_frame[0].MessageID = REV_ID_FTG;
//
//	BT_frame[1].Data = (uint8_t *)smart_drive_p;
//	BT_frame[1].MessageID = REV_ID_SMART_DRIVE;
//
//	BT_frame[2].Data = (uint8_t *)smart_in_p;
//	BT_frame[2].MessageID = REV_ID_SMART_IN;
//
//	BT_frame[3].Data = (uint8_t *)speed_p;
//	BT_frame[3].MessageID = REV_ID_SPEED;
//
//	BT_frame[4].Data = (uint8_t *)torque_p;
//	BT_frame[4].MessageID = REV_ID_TORQUE;
//
//	BT_frame[5].Data = (uint8_t *)voice_p;
//	BT_frame[5].MessageID = REV_ID_VOICE;
//
//	BT_frame[6].Data = (uint8_t *)smart_deg_p;
//	BT_frame[6].MessageID = REV_ID_SMART_DEG;
//}
//
//static uint8_t *BT_find_data_pt(word BT_id)
//{
//	int i;
//	BT_id = (word)((BT_id & 0xff) << 8 | (BT_id & 0xFF00U) >> 8);     //翻转接收到的字节序
//	for(i=0;i<RECV_ID_NUM;i++)
//	{
//		if(BT_frame[i].MessageID == BT_id)
//			return BT_frame[i].Data;
//	}
//	return FALSE;
//}
//
//static dword BT_find_flag_mask(word BT_id)
//{
//	int i;
//	BT_id = (word)((BT_id & 0xff) << 8 | (BT_id & 0xFF00U) >> 8);     //翻转接收到的字节序
//	for(i=0;i<RECV_ID_NUM;i++)
//	{
//		if(BT_frame[i].MessageID == BT_id)
//			return (1<<i);
//	}
//	return FALSE;
//}



/**********************************************************************************************
* Local variables
**********************************************************************************************/

/**********************************************************************************************
* Global functions
**********************************************************************************************/

void BT_init(void)
{


//	BT_stat.rev_flag_fatigue = FALSE;
//	BT_stat.rev_flag_voice = FALSE;
//	BT_stat.send_flag = FALSE;
	BT_stat.rev_count = 0;

	BT_rev_frame.Data = BT_rev_data_buf;
//	BT_init_frame();

}
void BT_resolve(void)
{
	BT_stat.rev_count ++ ;
	if(BT_stat.rev_count >= FRAME_LENGTH)
	{
		BlueTooth_RecvBlock((BlueTooth_TComData *)&BT_rev_frame.MessageID,2,&BT_rev_frame.Length);
		BlueTooth_RecvBlock(BT_rev_frame.Data ,32,&BT_rev_frame.Length);

		BT_rev_frame.MessageID = (word)((BT_rev_frame.MessageID & 0xff) << 8 | (BT_rev_frame.MessageID & 0xFF00U) >> 8);     //翻转接收到的字节序

		BT_stat.rev_count = 0;
		working_mode = mode_bluetooth;
		logic_save_data(BT_rev_frame.MessageID, BT_rev_frame.Data, BT_rev_frame.Length);
	}
}
//void BT_resolve(void)
//{
//	word Snd=0;
//	uint8_t *data_p;
//	dword	flag_mask;
//	BT_stat.rev_count ++ ;
//	if(BT_stat.rev_count >= FRAME_LENGTH)
//	{
//		BlueTooth_RecvBlock((BlueTooth_TComData *)&BT_rev_frame.MessageID,2,&BT_rev_frame.Length);
//		BlueTooth_RecvBlock(BT_rev_frame.Data ,32,&BT_rev_frame.Length);
//		BT_stat.rev_count = 0;
//		//BlueTooth_SendBlock(BT_rev_data_buf,32,&Snd);
//
//		if(working_mode == mode_stop||working_mode == mode_pause)
//		{
//			load_sys_para();
//			return;
//		}
//
//		working_mode = mode_bluetooth;
//
//		data_p = BT_find_data_pt(BT_rev_frame.MessageID);
//		flag_mask = BT_find_flag_mask(BT_rev_frame.MessageID);
//		if(data_p == FALSE || flag_mask == FALSE)
//		{
//			GREEN_ClrVal();
//			working_mode = mode_can;
//			load_sys_para();
//			return;
//		}
//
//		memcpy(data_p,BT_rev_frame.Data,BT_rev_frame.Length);
//		can_flag_stat.flag.bytes |= flag_mask;
//
//
//	}
//}
