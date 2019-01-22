/*
 * System_logic.c
 *
 *  Created on: 2018Äê7ÔÂ14ÈÕ
 *      Author: Administrator
 */

#include "System_logic.h"

#include "CAN_bsp.h"
#include "Bluetooth_bsp.h"
#include "time_flash.h"
#include "IN_BUSY.h"
#include "OUT_BUSY.h"

byte	recv_data_buf[RECV_ID_NUM][8] = {0};
byte	send_data_buf[SEND_ID_NUM][8] = {0};



//REV_DATA_FTG_P			fatigue_p = (REV_DATA_FTG_P)recv_data_buf[REV_ID_FTG_ADDR];
//REV_DATA_SMART_DRIVE_P 	smart_drive_p = (REV_DATA_SMART_DRIVE_P)recv_data_buf[REV_ID_SMART_DRIVE_ADDR];
//REV_DATA_SMART_IN_P 	smart_in_p = (REV_DATA_SMART_IN_P)recv_data_buf[REV_ID_SMART_IN_ADDR];
//REV_DATA_SPEED_P 		speed_p = (REV_DATA_SPEED_P)recv_data_buf[REV_ID_SPEED_ADDR];
//REV_DATA_TORQUE_P 		torque_p = (REV_DATA_TORQUE_P)recv_data_buf[REV_ID_TORQUE_ADDR];
//REV_DATA_VOICE_P 		voice_p = (REV_DATA_VOICE_P)recv_data_buf[REV_ID_VOICE_ADDR];

byte *		fatigue_p = recv_data_buf[REV_ID_FTG_ADDR];
byte * 		smart_drive_p = recv_data_buf[REV_ID_SMART_DRIVE_ADDR];
byte * 		smart_in_p = recv_data_buf[REV_ID_SMART_IN_ADDR];
byte * 		speed_p = recv_data_buf[REV_ID_SPEED_ADDR];
byte * 		torque_p = recv_data_buf[REV_ID_TORQUE_ADDR];
byte * 		voice_p = recv_data_buf[REV_ID_VOICE_ADDR];
byte * 		smart_deg_p = recv_data_buf[REV_ID_SMART_DEG_ADDR];

CAN_ID_GLAG_STAT	can_flag_stat;
LOGIC_Frame			logic_frame[RECV_ID_NUM];
static void logic_init_frame(void);

static void logic_init_frame(void)
{
	logic_frame[0].Data = (uint8_t *)fatigue_p;
	logic_frame[0].MessageID = REV_ID_FTG;

	logic_frame[1].Data = (uint8_t *)smart_drive_p;
	logic_frame[1].MessageID = REV_ID_SMART_DRIVE;

	logic_frame[2].Data = (uint8_t *)smart_in_p;
	logic_frame[2].MessageID = REV_ID_SMART_IN;

	logic_frame[3].Data = (uint8_t *)speed_p;
	logic_frame[3].MessageID = REV_ID_SPEED;

	logic_frame[4].Data = (uint8_t *)torque_p;
	logic_frame[4].MessageID = REV_ID_TORQUE;

	logic_frame[5].Data = (uint8_t *)voice_p;
	logic_frame[5].MessageID = REV_ID_VOICE;

	logic_frame[6].Data = (uint8_t *)smart_deg_p;
	logic_frame[6].MessageID = REV_ID_SMART_DEG;

	logic_frame[REV_ID_DRV_INFO_DISP_ADDR].Data = recv_data_buf[REV_ID_DRV_INFO_DISP_ADDR];
	logic_frame[REV_ID_DRV_INFO_DISP_ADDR].MessageID = REV_ID_DRV_INFO_DISP;
}

void logic_init(void)
{
	can_flag_stat.flag.bytes = 0;
	working_mode = mode_can;
	logic_init_frame();
	voice_init();
	can_init();
	BT_init();
	time_flash_init();
	Lightbar_Init(&lb_stat);
}



void logic_resolve(CAN_ID_GLAG_STAT_P flag_p)
{
	byte i;
	dword flag_mask;
	for(i=0;i<RECV_ID_NUM;i++)
	{
		flag_mask = 1<<i;
		if(flag_p->flag.bytes & flag_mask)
		{
			LOGIC_FUNC(i,recv_data_buf[i]);
			flag_p->flag.bytes &= ~flag_mask;

		}
	}
	load_sys_para();
}
Logic_Func_Ptr LOGIC_Func[RECV_ID_NUM] = {
		fatigue_resolve,
		smart_drive_resolve,
		smart_in_resolve,
		speed_resolve,
		torque_resolve,
		voice_resolve,
		smart_deg_resolve,
		info_disp_resolve,
};

void load_sys_para(void)
{
	word snd;
	can_send_frame.MessageID = SEND_ID_SYS_PARA0;
	SEND_DATA_SYS_P send_data_p = (SEND_DATA_SYS_P)can_send_frame.Data;
	REV_DATA_FTG_P	ftg_p = (REV_DATA_FTG_P)recv_data_buf[REV_ID_FTG_ADDR];
	send_data_p->FtgGrdWngHSC4 = ftg_p->DATA0.Bits.FtgGrdWngHSC4;
	send_data_p->mode = working_mode;
	send_data_p->safety_alarm = safety_alarm;
	send_data_p->BCM = BCM_sig_GetVal();
	send_data_p->drive_stat = smart_drive_stat;
	send_data_p->lb_mode = lb_stat.lb_mode;
	send_data_p->no_torque_tm_cnt = no_torque_tm_cnt / NO_TORQUE_1S_CNT;
	send_data_p->green_led_stat = LED_GREEN_GetVal();
	send_data_p->red_led_stat = LED_RED_GetVal();
	send_data_p->beep_stat = BEEP_GetVal();
	send_data_p->motor_stat = MOTOR_GetVal();
	send_data_p->voice_in_busy = IN_BUSY_GetVal();
	send_data_p->voice_out_busy = OUT_BUSY_GetVal();
//	send_data_p->voice_flag_stat_in = voice_flag_stat_out;
	send_data_p->bt_id = BT_rev_frame.MessageID;
	send_data_p->byte0 = BT_rev_frame.Data[0];
	send_data_p->byte1 = BT_rev_frame.Data[1];
	CAN_SendFrame(CAN_DeviceData,1,&can_send_frame);
	BlueTooth_SendBlock((BlueTooth_TComData *)send_data_p,8,&snd);
}

void load_sys_para1(void)
{
	word snd;
	can_send_frame.MessageID = SEND_ID_SYS_PARA1;
	SEND_DATA_SYS_PARA1_P send_data_p = (SEND_DATA_SYS_PARA1_P)can_send_frame.Data;
	CAN_SendFrame(CAN_DeviceData,1,&can_send_frame);
}

void load_atmosphere_lamp_mode(void)
{
	word snd;
	can_send_frame.MessageID = SEND_ID_ATMOSPHERE_LAMP_MODE;
	SEND_DATA_ATMOSPHERE_LAMP_MODE_P send_data_p = (SEND_DATA_ATMOSPHERE_LAMP_MODE_P)can_send_frame.Data;
	send_data_p->lamp_mode = lb_stat.out_stat;
	CAN_SendFrame(CAN_DeviceData,1,&can_send_frame);

}
