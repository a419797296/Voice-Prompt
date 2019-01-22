/*
 * Voice.h
 *
 *  Created on: 2018Äê6ÔÂ1ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCES_VOICE_H_
#define SOURCES_VOICE_H_
#include "PE_Types.h"

#define	SPEAK_IN	0
#define SPEAK_OUT	1


#define MUTE	0

#define ALARM_CHANGE_ASC	1
#define ALARM_CHANGE_DEC	2
#define ALARM_DENGDENG	3
#define ALARM_DIDI_FOR_ONE	4
#define ALARM_DIDI_FOR_THREE	5
#define ALARM_DIDI_FOR_FIVE	6
#define ALARM_SECURITY_FOR_TWO	7
#define ALARM_SECURITY_FOR_THREE	8
#define ALARM_SECURITY_FOR_EIGHT	9
#define ALARM_BUG_HIGH_SPEED	10
#define ALARM_BUG_MID_SPEED	11
#define ALARM_UP_LIMIT	12

#define VOICE_YOUR_GO_FIRST	13
#define VOICE_ATTENTION_DRIVELESS	14
#define VOICE_TIRED_ATTENTION_DRIVE	15
#define VOICE_TIRED_REST_SERVICE_CENTER	16
#define VOICE_TIRED_REST_CAR_STOP	17
#define VOICE_TIRED_CHANGE_TO_DRIVELESS	18
#define VOICE_DISTRACTION	19
#define VOICE_ATTENTION_REAR	20
#define VOICE_ATTENTION_RL	21
#define VOICE_ATTENTION_RR	22
#define VOICE_ATTENTION_FORWARD	23
#define VOICE_ATTENTION_FL	24
#define VOICE_ATTENTION_FR	25
#define VOICE_ATTENTION_CAR_IN_REAR	26
#define VOICE_ATTENTION_PEOPLE_IN_REAR	27
#define VOICE_ATTENTION_REAR_SEAT	28

#define END	29

#define VOICE_LOOP_COUNT		2
#define VOICE_ADDR_MAX			END

typedef struct VOICE_GLAG_STAT
{
	union
     {
         dword bytes;
         struct
         {
        	byte	mute											:1;

        	byte	alarm_change_asc 								:1;
        	byte	alarm_change_dec 								:1;
        	byte	alarm_dengdeng	 								:1;
        	byte	alarm_didi_for_one	 							:1;
        	byte	alarm_didi_for_three	 						:1;
        	byte	alarm_didi_for_five								:1;
        	byte	alarm_security_for_two							:1;
        	byte	alarm_security_for_three						:1;
        	byte	alarm_security_for_eight						:1;
        	byte	alarm_bug_high_speed							:1;
        	byte	alarm_bug_mid_speed								:1;
        	byte	alarm_up_limit 									:1;

        	byte	voice_your_go_first	 							:1;
        	byte	voice_attention_driveless	 					:1;
        	byte	voice_tired_attention_drive		 				:1;
        	byte	voice_tired_rest_service_center		 			:1;
        	byte	voice_tired_rest_car_stop						:1;
        	byte	voice_tired_change_to_driveless					:1;
        	byte	voice_distraction								:1;
        	byte	voice_attention_rear							:1;
        	byte	voice_attention_rl							:1;
        	byte	voice_attention_rr		 					:1;
        	byte	voice_attention_forward		 					:1;
        	byte	voice_attention_fl			 					:1;
        	byte	voice_attention_fr			 					:1;
        	byte	voice_attention_car_in_rear						:1;
        	byte	voice_attention_people_in_rear					:1;
        	byte	voice_attention_rear_seat						:1;

			byte 	end												:1;
			byte 	nc												:2;
         }bits;
     }flag;
}VOICE_FLAG_STAT,*VOICE_FLAG_STAT_P;

//typedef enum {
//   mute,
//   voice_you_go_first,
//   voice_be_attention,
//   voice_end
//} VOICE_ADDR;


extern byte voice_loop_count;
extern VOICE_FLAG_STAT 	voice_flag_stat_in,voice_flag_stat_out;
extern VOICE_FLAG_STAT 	voice_flag_stat_in_back,voice_flag_stat_out_back;
extern byte voice_addr_in, voice_addr_out;
extern void voice_init(void);
extern bool voice_play(void);
extern bool voice_play_out(byte addr);
extern bool voice_play_in(byte addr);
extern bool voice_set_flag(byte num, byte addr);
#endif /* SOURCES_VOICE_H_ */
