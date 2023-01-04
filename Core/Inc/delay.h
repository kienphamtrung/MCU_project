/*
 * delay.h
 *
 *  Created on: Dec 12, 2022
 *      Author: AdminPC
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

void delay(__IO uint32_t nTime);

void delay_decrement(void);

void _delay_us(TIM_TypeDef *timer, unsigned int time) ;

void _delay_ms(TIM_TypeDef *timer, unsigned int time) ;



#endif /* INC_DELAY_H_ */
