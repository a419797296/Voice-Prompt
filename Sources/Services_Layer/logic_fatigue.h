/*
 * logic_fatigue.h
 *
 *  Created on: 2018年10月30日
 *      Author: Administrator
 */

#ifndef SOURCES_SERVICES_LAYER_LOGIC_FATIGUE_H_
#define SOURCES_SERVICES_LAYER_LOGIC_FATIGUE_H_
#include "PE_Types.h"

#define			FATIGUE_LAVEL	5


typedef enum
{
	fatigue_no_fault,
	fatigue_fault

}FD_FIT_STS_HSC4;

typedef enum
{
    no_request,
    no_fatigue,
    fatigue_grade1,
    fatigue_grade2,
    fatigue_grade3

}TG_GRD_WNG_HSC4;

typedef struct CAN_REV_DATA_FTG
{
	union
     {
         byte data0;
         struct
         {
        	byte	DrvrEyeStsHC4			:1;
        	byte	FtgGradeWrnngHC4		:3;
        	TG_GRD_WNG_HSC4	FtgGrdWngHSC4			:3;  //疲劳状态
        	FD_FIT_STS_HSC4	FDFitStsHSC4			:1;  //疲劳检测是否失效

         }Bits;
     }DATA0;
	byte	data1;
	byte	data2;
	byte	data3;
    byte	data4;
    byte	data5;
    byte	data6;
    byte	data7;
}REV_DATA_FTG, *REV_DATA_FTG_P;


typedef struct SYS_TM_FLAG
{
	bool		tm_100ms_flag;
	bool		tm_500ms_flag;
	bool		tm_1000ms_flag;
}SYS_TM_FLAG;

//--------------------------------------------------------

typedef enum
{
	safety_belt_alarm_none,
	safety_belt_alarm_grade1,
	safety_belt_alarm_grade2,
}SAFETY_BELT_ALARM;


typedef void(*Fatigue_Func_Ptr)(REV_DATA_FTG_P);
#define FATIGUE_FUNC(TG_GRD_WNG_HSC4,REV_DATA_FTG_P) (FATIGUE_Func[TG_GRD_WNG_HSC4](REV_DATA_FTG_P))

Fatigue_Func_Ptr FATIGUE_Func[FATIGUE_LAVEL];

extern SAFETY_BELT_ALARM	safety_alarm;
extern SYS_TM_FLAG			tm_flag;
extern void fatigue_resolve(byte * id_data_p);


#endif /* SOURCES_SERVICES_LAYER_LOGIC_FATIGUE_H_ */
