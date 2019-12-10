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


volatile float speed_encoder = 0;


static err TIM5_Init()
{
  err ret = 0;

  RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;                 //start clock for TIM5
  TIM5->SMCR = TIM_SMCR_SMS_1;                        //count only TI2
  TIM5->CCMR1 = TIM_CCMR1_IC1F | TIM_CCMR1_IC2F;      //filtr
  TIM5->ARR = 6;
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


float Encoder_SpeedSend()
{
  uint8_t sendSpeed[4];
  sendSpeed[0] = 'V';                                           //char started frame of velocity
  sendSpeed[1] = (uint8_t)speed_encoder;
  sendSpeed[2] = 10;
  sendSpeed[3] = 13;

  return speed_encoder;
}

__attribute__((interrupt)) void TIM5_IRQHandler(void)         //interrupt form encoder
{

  int stop = 0;
  if (TIM5->SR & TIM_SR_UIF)
  {
    stop = TIM6->CNT;
    speed_encoder = (0.15 / stop) * 42000;                     // cm/s
    TIM6->CNT = 0;
    TIM5->SR = ~TIM_SR_UIF;                                   //clear update irq flag

  }
}

#endif /* ENCODER_C_ */
