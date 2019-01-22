/*
 * CAN_bsp.h
 *
 *  Created on: 2018Äê6ÔÂ11ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_CAN_BSP_H_
#define SOURCES_CAN_BSP_H_
#include "CAN.h"

extern uint8_t			can_rev_data_buf[8];
extern uint8_t			can_send_data_buf[8];

extern LDD_CAN_TFrame can_send_frame;
extern LDD_CAN_TFrame can_rev_frame;
extern void can_init(void);
extern void can_resolve(void);

#endif /* SOURCES_CAN_BSP_H_ */
