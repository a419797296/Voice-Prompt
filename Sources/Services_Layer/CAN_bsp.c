/*
 * CAN_bsp.c
 *
 *  Created on: 2018Äê6ÔÂ11ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_CAN_BSP_C_
#define SOURCES_CAN_BSP_C_
#include "CAN_bsp.h"
#include "logic_com.h"
#include "System_logic.h"
#include  <string.h>
#include "GREEN.h"
/**********************************************************************************************
* Global variables
**********************************************************************************************/
uint8_t			can_rev_data_buf[8]={0};
uint8_t			can_send_data_buf[8]={0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};


LDD_CAN_TFrame can_send_frame;
LDD_CAN_TFrame can_rev_frame;
LDD_CAN_TFrame can_frame[RECV_ID_NUM];
/**********************************************************************************************
* Constants and macros
**********************************************************************************************/


///**********************************************************************************************
//* Local types
//**********************************************************************************************/
//static void can_init_frame(void);
//static uint8_t *can_find_data_pt(LDD_CAN_TMessageID can_id);
//static dword can_find_flag_mask(LDD_CAN_TMessageID can_id);
///**********************************************************************************************
//* Local function prototypes
//*********************************************************************************************/
//
//
//static void can_init_frame(void)
//{
//	can_frame[0].Data = (uint8_t *)fatigue_p;
//	can_frame[0].MessageID = REV_ID_FTG;
//
//	can_frame[1].Data = (uint8_t *)smart_drive_p;
//	can_frame[1].MessageID = REV_ID_SMART_DRIVE;
//
//	can_frame[2].Data = (uint8_t *)smart_in_p;
//	can_frame[2].MessageID = REV_ID_SMART_IN;
//
//	can_frame[3].Data = (uint8_t *)speed_p;
//	can_frame[3].MessageID = REV_ID_SPEED;
//
//	can_frame[4].Data = (uint8_t *)torque_p;
//	can_frame[4].MessageID = REV_ID_TORQUE;
//
//	can_frame[5].Data = (uint8_t *)voice_p;
//	can_frame[5].MessageID = REV_ID_VOICE;
//
//	can_frame[6].Data = (uint8_t *)smart_deg_p;
//	can_frame[6].MessageID = REV_ID_SMART_DEG;
//}
//
//static uint8_t *can_find_data_pt(LDD_CAN_TMessageID can_id)
//{
//	int i;
//	for(i=0;i<RECV_ID_NUM;i++)
//	{
//		if(can_frame[i].MessageID == can_id)
//			return can_frame[i].Data;
//	}
//	return FALSE;
//}
//static dword can_find_flag_mask(LDD_CAN_TMessageID can_id)
//{
//	int i;
//	for(i=0;i<RECV_ID_NUM;i++)
//	{
//		if(can_frame[i].MessageID == can_id)
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

/***********************************************************************************************
*
* @brief    can_init - init buf and frame.
* @param    none.
* @return   none.
*
************************************************************************************************/

void can_init(void)
{
	can_send_frame.Data = can_send_data_buf;
	can_send_frame.FrameType = LDD_CAN_DATA_FRAME;
	can_send_frame.Length = 8;
	can_send_frame.LocPriority = 1;
	can_send_frame.MessageID = SEND_ID_SYS_PARA0;
	can_send_frame.TimeStamp = 50;

	can_rev_frame.Data = can_rev_data_buf;
//	can_init_frame();
}
/***********************************************************************************************
*
* @brief    can_resolve - resolve the receive buf.
* @param    none.
* @return   none.
*
************************************************************************************************/

void can_resolve(void)
{
	if(working_mode == mode_bluetooth)
	{
		return;
	}
	logic_save_data(can_rev_frame.MessageID, can_rev_frame.Data, can_rev_frame.Length);
}
//
//void can_resolve(void)
//{
//	uint8_t *data_p;
//	dword	flag_mask;
//
//	if(working_mode == mode_stop||working_mode == mode_bluetooth)
//	{
//		load_sys_para();
//		return;
//	}
//	data_p = can_find_data_pt(can_rev_frame.MessageID);
//	flag_mask = can_find_flag_mask(can_rev_frame.MessageID);
//
//
//	if(data_p == FALSE || flag_mask == FALSE)
//	{
//		GREEN_ClrVal();
//		return;
//	}
//
//	memcpy(data_p,can_rev_frame.Data,can_rev_frame.Length);
//	can_flag_stat.flag.bytes |= flag_mask;
//
//
//
//}
#endif /* SOURCES_CAN_BSP_C_ */
