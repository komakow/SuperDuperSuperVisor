/*
 *@ServoDriver.c
 *@Created on: 24.04.2018
 *@Author: KamilM
 *
 *@brief Source code of servo driver working at STM32F407
 */
#include <ServoDriver.h>
#include "defGPIO.h"


static err Init_TIM3()
{
	err ret = 0;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;	                                        //enable clock for TIM3
	TIM3->CCMR1   = TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;      //enable preload and PWM mode 1, Channel_1

	TIM3->CCER |= TIM_CCER_CC1E| TIM_CCER_CC2E;   //enable channel_1 and channel_2 as a output pin

	TIM3->PSC	= 1249;    //prescaler
	TIM3->ARR	= 255;      //f=160Mhz/[(1249+1)(255+1)]=500 Hz

	TIM3->CCR1	= 127;      //default value of PWM_CH_1 Left

	TIM3->EGR |=TIM_EGR_UG;
	TIM3->CR1 |=TIM_CR1_ARPE| TIM_CR1_CEN;

	return ret;
}
static err Control_Left(uint8_t speed)
{
	err ret = 0;

	TIM3->CCR1 = speed;                       //set Duty of channel_1

	return ret;
}



err servo_Init()
{
	err ret = 0;

	ret = Init_TIM3();															//Initialize PWM channel 1&2 on Timer3

	return ret;
}

err WheelControl(uint8_t speed)
{
	err ret = 0;

	ret = Control_Left(speed);    //change state of wheel


	return ret;
}

err WheelStop()
{
	err ret = 0;
	TIM3->CCR1 = 0;																//if Duty = 0% motor is compact and will stop

	return ret;
}


err servo_DeInit()
{
	err ret = 0;
	TIM3->CR1 &= ~TIM_CR1_CEN;													//disable timer
	for(int a=0;a<50;a++)
	{
		__NOP();
	}
	RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN;										//disable clock for TIM3

	return ret;
}
