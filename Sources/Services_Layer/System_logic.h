/*
 * System_logic.h
 *
 *  Created on: 2018年7月14日
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_SYSTEM_LOGIC_H_
#define SOURCES_SERVICES_LAYER_SYSTEM_LOGIC_H_

#include "PE_Types.h"
#include "logic_com.h"
#include "logic_fatigue.h"
#include "logic_smart_drive.h"
#include "logic_smart_in.h"
#include "logic_speed.h"
#include "logic_torque.h"
#include "logic_voice.h"
#include "logic_smart_deg.h"
#include "logic_AutodDrvngInfoDspReq.h"




#define SEND_ID_NUM		4
#define	RECV_ID_NUM		8

#define			SEND_ID_SYS_PARA0				0X566
#define			SEND_ID_SYS_PARA1				0X567
#define			SEND_ID_ATMOSPHERE_LAMP_MODE	0X568

#define			REV_ID_FTG			0X16A
#define			REV_ID_FTG_ADDR			0

#define			REV_ID_SMART_DRIVE		0X16B
#define			REV_ID_SMART_DRIVE_ADDR		1

#define			REV_ID_SMART_IN			0X1E0
#define			REV_ID_SMART_IN_ADDR		2

#define			REV_ID_SPEED		0X16D
#define			REV_ID_SPEED_ADDR		3

#define			REV_ID_TORQUE		0X16E
#define			REV_ID_TORQUE_ADDR		4

#define			REV_ID_VOICE		0X16F
#define			REV_ID_VOICE_ADDR		5

#define			REV_ID_SMART_DEG		0X0A
#define			REV_ID_SMART_DEG_ADDR		6

#define			REV_ID_DRV_INFO_DISP		0X170
#define			REV_ID_DRV_INFO_DISP_ADDR		7

typedef struct {
  word MessageID;        /*!< Message ID */
  byte *Data;                       /*!< Message data buffer */
  word Length;
} LOGIC_Frame,LOGIC_Frame_P;

//extern REV_DATA_FTG_P			fatigue_p;
//extern REV_DATA_SMART_DRIVE_P	smart_drive_p;
//extern REV_DATA_SMART_IN_P 		smart_in_p;
//extern REV_DATA_SPEED_P 		speed_p;
//extern REV_DATA_TORQUE_P 		torque_p;
//extern REV_DATA_VOICE_P 		voice_p;



typedef struct CAN_ID_GLAG_STAT
{
	union
     {
         dword bytes;
         struct
         {
        	byte	fatigue					:1;
        	byte	smart_drive 			:1;
        	byte	smart_in 				:1;
        	byte	speed 					:1;
        	byte	torque 					:1;
        	byte	voice 					:1;
        	byte	smart_deg				:1;
        	byte	drv_info_disp			:1;
        	byte	nc2						:8;
        	byte	nc3						:8;
        	byte	nc4						:8;
         }bits;
     }flag;
}CAN_ID_GLAG_STAT,*CAN_ID_GLAG_STAT_P;


typedef struct SEND_DATA_SYS
{

    TG_GRD_WNG_HSC4		FtgGrdWngHSC4				:3;  //疲劳状态
    WORK_MODE			mode						:2;
    SAFETY_BELT_ALARM	safety_alarm				:2;
	bool				BCM							:1;

	SMART_DRIVE_STAT	drive_stat					:2;
	byte				green_led_stat				:1;
	byte				red_led_stat				:1;
	byte				beep_stat					:1;
	byte				motor_stat					:1;
	byte				voice_in_busy				:1;
	byte				voice_out_busy				:1;

	byte				no_torque_tm_cnt			:8;
	byte 				lb_mode						:8;

//	VOICE_FLAG_STAT		voice_flag_stat_in			 ;   //4BYTES
	word				bt_id;
	byte				byte0;
	byte				byte1;

}SEND_DATA_SYS, *SEND_DATA_SYS_P;

typedef struct SEND_DATA_SYS_PARA1
{



}SEND_DATA_SYS_PARA1, *SEND_DATA_SYS_PARA1_P;

typedef struct SEND_DATA__ATMOSPHERE_LAMP_MODE
{

	byte	lamp_mode;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}SEND_DATA_ATMOSPHERE_LAMP_MODE, *SEND_DATA_ATMOSPHERE_LAMP_MODE_P;

byte * ID_DATA_P;
typedef void(*Logic_Func_Ptr)(byte * );
#define LOGIC_FUNC(byte,ID_DATA_P) (LOGIC_Func[byte](ID_DATA_P))

Logic_Func_Ptr LOGIC_Func[RECV_ID_NUM];

extern byte	recv_data_buf[RECV_ID_NUM][8];
extern byte	send_data_buf[SEND_ID_NUM][8];
extern LOGIC_Frame			logic_frame[RECV_ID_NUM];
extern CAN_ID_GLAG_STAT		can_flag_stat;

extern byte *		fatigue_p;
extern byte *		smart_drive_p;
extern byte * 		smart_in_p;
extern byte * 		speed_p;
extern byte * 		torque_p;
extern byte * 		voice_p;
extern byte * 		smart_deg_p;
extern void logic_init(void);
extern void logic_resolve(CAN_ID_GLAG_STAT_P flag_p);
extern void load_sys_para(void);
extern void load_sys_para1(void);
extern void load_atmosphere_lamp_mode(void);
#endif /* SOURCES_SERVICES_LAYER_SYSTEM_LOGIC_H_ */
