///*
// * time_base.h
// *
// *  Created on: Nov 22, 2018
// *      Author: Administrator
// */
//
#ifndef TIME_BASE_H_
#define TIME_BASE_H_
#include "PE_Types.h"
#include "System_logic.h"
#include "logic_com.h"
#define TM_BASE_TYPE	6

typedef struct
{
	byte tm_count_1ms;
	byte tm_count_10ms;
	byte tm_count_50ms;
	byte tm_count_100ms;
	byte tm_count_500ms;
	byte tm_count_1s;
	byte tm_count_5s;
	byte tm_count_10s;
	union
		{
		    word R;
		    struct
		    {
		    	byte tm_flag_10ms           : 1;   /*  */
		    	byte tm_flag_50ms      		: 1;   /*  */
		    	byte tm_flag_100ms            : 1;   /**/
		    	byte tm_flag_500ms             : 1;   /*  */
		    	byte tm_flag_1s               : 1;   /*  */
		    	byte tm_flag_5s       : 1;   /*  */
		    	byte tm_flag_10s      : 1;   /* U */
		    	byte tm_flag_50s       : 1;   /* */
		    	byte : 8;                          /* RESERVED */
		    }B;
		}tm_flag;
}TM_BASE, *TM_BASE_P ;
//

typedef enum
{
	tm_10ms,
	tm_50ms,
	tm_100ms,
	tm_500ms,
	tm_1s,
	tm_5s,
}TM_IDX;
typedef void(*TmBase_Func_Ptr)();
#define TM_BASE_FUNC(byte) (TM_BASE_Func[byte]())

//TmBase_Func_Ptr TM_BASE_Func[TM_BASE_TYPE];


extern TM_BASE tm_base;
extern void TmBaseCnt(TM_BASE_P tm_base);
extern void TmBaseSolve(TM_BASE_P tm_base);
#endif /* TIME_BASE_H_ */
