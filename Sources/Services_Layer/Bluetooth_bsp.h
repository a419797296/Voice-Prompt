/*
 * Bluetooth.h
 *
 *  Created on: 2018Äê6ÔÂ11ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_BLUETOOTH_BSP_H_
#define SOURCES_BLUETOOTH_BSP_H_
#include "BlueTooth.h"
#include "System_logic.h"


#define FRAME_LENGTH		10

typedef struct BT_STAT
{
    bool	send_flag;
    bool	rev_flag_fatigue;
    bool	rev_flag_voice;
    word	rev_count;
}BT_STAT;


typedef struct {
  word MessageID;        /*!< Message ID */
  byte *Data;                       /*!< Message data buffer */
  word Length;
} BT_Frame,BT_Frame_P;


extern uint8_t			BT_rev_data_buf[8];
extern uint8_t			BT_send_data_buf[8];
extern BT_STAT			BT_stat;

extern BT_Frame	BT_frame[RECV_ID_NUM];
extern BT_Frame	BT_rev_frame;
extern BT_Frame	BT_send_frame;

extern void BT_init(void);
extern void BT_resolve(void);
//extern void BT_resolve_fatigue(REV_DATA_FTG_P fatigue_p);
//extern void BT_resolve_voice(REV_DATA_VOICE_P	voice_p);

#endif /* SOURCES_BLUETOOTH_BSP_H_ */
