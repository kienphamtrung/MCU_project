/*
 * fsm_auto.c
 *
 *  Created on: Dec 11, 2022
 *      Author: ADMIN
 */
#include "fsm_auto.h"

//int SEG7_buffer[2] = {0, 0};

int counterPEDESTRIAN = -1;

void fsm_auto_run(){

	if(mode == MODE1){
		switch(west_traffic){
		case INIT:

			west_traffic = RED_ON;
			setTimer1(100);
			break;
		case RED_ON:
			if(timer1_flag == 1){
				enableRED_WEST();
//				SEG7_buffer[0] = counterRED_WEST;
				counterRED_WEST--;
				if(counterRED_WEST == INIT){
					counterRED_WEST = AUTO_RED;
					west_traffic = GREEN_ON;
				}
//				if(isButtonPressed(BUTTON4)){
//					PEDESTRIAN_GREEN();
//					counterPEDESTRIAN = 10;
//				}
//				if(counterPEDESTRIAN > 0){
//					PEDESTRIAN_GREEN();
//					counterPEDESTRIAN--;
//					Play_Melody(ERROR_Melody ,5);
//
//				}
//				if(counterPEDESTRIAN == 0){
//					OFF_PEDESTRIAN();
//					Play_Melody(OK_Melody ,5);
//					counterPEDESTRIAN = -1;
//				}
				setTimer1(100);
			}

			break;
		case GREEN_ON:
			if(timer1_flag == 1){
				enableGREEN_WEST();
//				SEG7_buffer[0] = counterGREEN_WEST;
				counterGREEN_WEST--;
				if(counterGREEN_WEST == INIT){
					counterGREEN_WEST = AUTO_GREEN;
					west_traffic = YELLOW_ON;
				}
//				if(isButtonPressed(BUTTON4)){
//					PEDESTRIAN_RED();
//					counterPEDESTRIAN = 10;
//				}
//				if(counterPEDESTRIAN > 0){
//					PEDESTRIAN_RED();
//					counterPEDESTRIAN--;
//					Play_Melody(ERROR_Melody ,5);
//
//				}
//				if(counterPEDESTRIAN == 0){
//					OFF_PEDESTRIAN();
//					Play_Melody(OK_Melody ,5);
//					counterPEDESTRIAN = -1;
//				}
				setTimer1(100);
			}
			break;
		case YELLOW_ON:
			if(timer1_flag == 1){
				enableYELLOW_WEST();
//				SEG7_buffer[0] = counterYELLOW_WEST;
				counterYELLOW_WEST--;
				if(counterYELLOW_WEST == INIT){
					counterYELLOW_WEST = AUTO_YELLOW;
					west_traffic = RED_ON;
				}
				setTimer1(100);
			}
			break;
		default:
			break;
		}

//		int pedestrian = west_traffic;
//		switch(pedestrian){
//
//		case RED_ON:
//			if(isButtonPressed(BUTTON4)){
//				PEDESTRIAN_GREEN();
//				counterPEDESTRIAN = 10;
//				setTimer10(100);
//			}
//			if(timer10_flag == 1){
//			if(counterPEDESTRIAN > 0){
//				PEDESTRIAN_GREEN();
//				counterPEDESTRIAN--;
//				Play_Melody(ERROR_Melody ,5);
//
//			}
//			if(counterPEDESTRIAN == 0){
//				OFF_PEDESTRIAN();
//				Play_Melody(OK_Melody ,5);
//				counterPEDESTRIAN = -1;
//			}
//			setTimer10(100);
//			}
//			break;

//		case GREEN_ON:
//			if(isButtonPressed(BUTTON4)){
//				PEDESTRIAN_RED();
//				counterPEDESTRIAN = 10;
//				setTimer10(100);
//			}
//			if(timer10_flag == 1){
//			if(counterPEDESTRIAN > 0){
//				PEDESTRIAN_RED();
//				counterPEDESTRIAN--;
//				Play_Melody(ERROR_Melody ,5);
//
//			}
//			if(counterPEDESTRIAN == 0){
//				OFF_PEDESTRIAN();
//				Play_Melody(OK_Melody ,5);
//				counterPEDESTRIAN = -1;
//			}
//			setTimer10(100);
//			}
//			break;
//
//		default:
//			break;
//
//		}


		switch(north_traffic){
		case INIT:
			north_traffic = GREEN_ON;
			setTimer2(100);
			break;
		case GREEN_ON:
			if(timer2_flag == 1){
				enableGREEN_NORTH();
//				SEG7_buffer[1] = counterGREEN_NORTH;
				counterGREEN_NORTH--;
				if(counterGREEN_NORTH == INIT){
					counterGREEN_NORTH = AUTO_GREEN;
					north_traffic = YELLOW_ON;
				}
				setTimer2(100);
			}
			break;
		case YELLOW_ON:
			if(timer2_flag == 1){
				enableYELLOW_NORTH();
//				SEG7_buffer[1] = counterYELLOW_NORTH;
				counterYELLOW_NORTH--;
				if(counterYELLOW_NORTH == INIT){
					counterYELLOW_NORTH = AUTO_YELLOW;
					north_traffic = RED_ON;
				}
				setTimer2(100);
			}
			break;
		case RED_ON:
			if(timer2_flag == 1){
				enableRED_NORTH();
//				SEG7_buffer[1] = counterRED_NORTH;
				counterRED_NORTH--;
				if(counterRED_NORTH == INIT){
					counterRED_NORTH = AUTO_RED;
					north_traffic = GREEN_ON;
				}
				setTimer2(100);
			}
			break;
		default:
			break;
		}

//		switch(seg_disp){
//		case INIT:
//			seg_disp = SEG1;
//			setTimer3(100);
//			break;
//		case SEG1:
//			if(timer3_flag == 1){
//				display_chuc(SEG7_buffer[0], SEG7_buffer[1]);
//				seg_disp = SEG2;
//				setTimer3(50);
//			}
//			break;
//		case SEG2:
//			if(timer3_flag == 1){
//				display_don_vi(SEG7_buffer[0], SEG7_buffer[1]);
//				seg_disp = SEG1;
//				setTimer3(50);
//			}
//			break;
//		default:
//			break;
//		}



		switch(mode){
		case MODE1:
			if (isButtonPressed(BUTTON1) == 1) mode = MODE2;
			break;
		case MODE2:
			if (isButtonPressed(BUTTON1) == 1) mode = MODE3;
			break;
//		case MODE3:
//			if (isButtonPressed(BUTTON1) == 1) mode = MODE4;
//			break;
		case MODE3:
			if (isButtonPressed(BUTTON1) == 1) mode = MODE1;
			Setup();
			break;
		default:
			break;
		}
	}
	int pedestrian = west_traffic;
	switch(pedestrian){

	case RED_ON:
		if(isButtonPressed(BUTTON4)){
			PEDESTRIAN_GREEN();
			counterPEDESTRIAN = 10;
			setTimer10(100);
		}
		if(timer10_flag == 1){
		if(counterPEDESTRIAN > 0){
			PEDESTRIAN_GREEN();
			counterPEDESTRIAN--;
			Play_Melody(ERROR_Melody ,5);

		}
		if(counterPEDESTRIAN == 0){
			OFF_PEDESTRIAN();
			Play_Melody(OK_Melody ,5);
			counterPEDESTRIAN = -1;
		}
		setTimer10(100);
		}
		break;

	case GREEN_ON:
		if(isButtonPressed(BUTTON4)){
			PEDESTRIAN_RED();
			counterPEDESTRIAN = 10;
			setTimer10(100);
		}
		if(timer10_flag == 1){
		if(counterPEDESTRIAN > 0){
			PEDESTRIAN_RED();
			counterPEDESTRIAN--;
			Play_Melody(ERROR_Melody ,5);

		}
		if(counterPEDESTRIAN == 0){
			OFF_PEDESTRIAN();
			Play_Melody(OK_Melody ,5);
			counterPEDESTRIAN = -1;
		}
		setTimer10(100);
		}
		break;

	default:
		break;

	}

}


