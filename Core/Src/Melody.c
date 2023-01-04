/*
 * Melody.c
 *
 *  Created on: Dec 12, 2022
 *      Author: AdminPC
 */


#include <Melody.h>


extern TIM_HandleTypeDef htim3;


/* Example Melody */

const Melody_Typedef OK_Melody = {
		/*notes*/	{NOTE_CS6 ,NOTE_FS6},
		/*tempo*/	{5 ,8},
		/*Count*/	2
};

const Melody_Typedef ERROR_Melody = {
		/*notes*/	{NOTE_F6 ,NOTE_FS6,  NOTE_F6},
		/*tempo*/	{8, 8, 8},
		/*Count*/	3
};

const Melody_Typedef TOUCH1_Melody = {
		/*notes*/	{NOTE_GS6},
		/*tempo*/	{6},
		/*Count*/	1
};

void Play_Melody(Melody_Typedef MelodyName ,uint8_t Volume){

	//Volume = 10;
	__HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL, Volume);
	TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_ENABLE);

	for(uint8_t i=0; i < MelodyName.noteCount; i++){

		TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_ENABLE);

		TIMER->PSC = SET_FREQ(MelodyName.notes[i]);

		HAL_Delay(1000/MelodyName.noteDuration[i]);

		TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_DISABLE);

		HAL_Delay(10);

	}
	TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_DISABLE);

}
