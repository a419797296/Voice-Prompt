/*
 * time_flash.h
 *
 *  Created on: 2018Äê11ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_TIME_FLASH_H_
#define SOURCES_SERVICES_LAYER_TIME_FLASH_H_
#include "PE_Types.h"
#include "time_base.h"
#include "logic_com.h"
#define 	FLASH_EVENT_NUM		5

#define 	FLASH_FTG_LEV1				0
#define 	FLASH_FTG_LEV2				1
#define 	FLASH_FTG_LEV3				2
#define 	FLASH_EXIT_SMT_DRV			3
#define 	FLASH_ALARM_MANUAL_DRV		4
typedef enum
{
	ftg_lev1,
	ftg_lev2,
	ftg_lev3,
	exit_smt_drv,
	alarm_manual_drv,
}TM_FLASH_IDX;

typedef struct
{
	byte 	flag;
	word 	cnt;
	word 	cnt_finish;
	TM_IDX	tm_base;
}TM_FLASH, *TM_FLASH_P;

typedef struct TM_EXE_FLAG
{
	union
     {
         dword bytes;
         struct
         {
//        	union
//			{
//        		byte ftg_grp				:3;
//				struct
//				{
//                	byte	ftg_lev1				:1;
//                	byte	ftg_lev2 				:1;
//                	byte	ftg_lev3 				:1;
//				}bits;
//			}ftg;
        	byte	ftg_lev1				:1;
        	byte	ftg_lev2 				:1;
        	byte	ftg_lev3 				:1;
        	byte	exit_smt_drv 			:1;
        	byte	alarm_manual_drv		:1;
        	byte	nc0 					:1;
        	byte	nc00					:1;
        	byte	nc1						:1;
        	byte	nc2						:8;
        	byte	nc3						:8;
        	byte	nc4						:8;
         }bits;
     }flag;
}TM_FLSH_FLAG,*TM_FLSH_FLAG_P;

typedef void(*TmFlash_Func_Ptr)();
#define TM_FLASH_FUNC(byte) (TM_FLASH_Func[byte]())

extern TM_FLSH_FLAG	tm_flash_flag;
extern TM_FLASH tm_flash[FLASH_EVENT_NUM];
extern void time_flash_init(void);   //flash event register
extern void time_flash_set_flag(TM_FLASH_IDX tm_flash_idx);   //flash set flag
extern void time_flash_resolve(TM_IDX tm_idx);   //flash event register

#endif /* SOURCES_SERVICES_LAYER_TIME_FLASH_H_ */
