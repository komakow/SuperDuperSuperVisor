/*
 *@encoder.c
 *
 *@Created on:  5.12.2019
 *@Author: KamilM
 *
 *@brief Source code of encoder driver
 */

#ifndef ENCODER_C_
#define ENCODER_C_

//includes
#include "stm32f4xx.h"
#include "encoder.h"
#include "defGPIO.h"
#include "GPIODriver.h"

#define TRESHOLD_ARR   80
volatile float enc_left = 0;
volatile float enc_right = 0;

static err TIM5_Init()
{
  err ret = 0;

  RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;                 //start clock for TIM5
  TIM5->SMCR = TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;       //count on TI2 and TI1
  TIM5->CCMR1 = TIM_CCMR1_IC1F | TIM_CCMR1_IC2F;      //filtr
  TIM5->ARR = TRESHOLD_ARR;
  TIM5->DIER = TIM_DIER_UIE;
  TIM5->CR1 = TIM_CR1_CEN;

  return ret;
}

err Encoder_Init()
{
  err ret = 0;

  TIM5_Init();                //init and enable TIM5
  Encoder_IRQ_Enable();       //enable interrupts

  return ret;
}

err Encoder_IRQ_Enable()
{
  err ret = 0;

  //TIM5
  NVIC_ClearPendingIRQ(TIM5_IRQn);         //clear pending interrupts
  NVIC_EnableIRQ(TIM5_IRQn);               //enable interrupt

  return ret;
}

err Encoder_IRQ_Disable()
{
  err ret = 0;
  //TIM5
  NVIC_ClearPendingIRQ(TIM5_IRQn);                                //clear pending interrupts
  NVIC_DisableIRQ(TIM5_IRQn);                                     //enable interrupt

  return ret;
}

__attribute__((interrupt)) void TIM5_IRQHandler(void)         //interrupt form encoder
{
  if (TIM5->SR & TIM_SR_UIF)
  {
	  if(TIM5->CNT > (TRESHOLD_ARR-15))
	  {
		  enc_left = 1;
		  enc_right = 0;
	  }
	  else
	  {
		  enc_right = 1;
		  enc_left = 0;
	  }
	  TIM5->CNT = TRESHOLD_ARR / 2;
	  TIM5->SR = ~TIM_SR_UIF;                                   //clear update irq flag
  }
}

#endif /* ENCODER_C_ */
