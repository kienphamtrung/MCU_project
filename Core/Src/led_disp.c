/*
 * led_disp.c
 *
 *  Created on: Dec 11, 2022
 *      Author: ADMIN
 */

#include "led_disp.h"

void toggleREDS(){

	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
		HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);

}
void toggleGREENs(){
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
		HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);

}


void toggleYELLOWs(){
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
}
void reset(){// In each case when we want to modify the time for each led, we reset it before let it blink every second(toggle)
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
}

void enableRED_WEST(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
}
void enableYELLOW_WEST(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
}
void enableGREEN_WEST(){
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
}

void enableRED_NORTH(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
}
void enableGREEN_NORTH(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
}
void enableYELLOW_NORTH(){
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
}
void PEDESTRIAN_RED(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);

}
void PEDESTRIAN_GREEN(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);

}
void OFF_PEDESTRIAN(){
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
}

