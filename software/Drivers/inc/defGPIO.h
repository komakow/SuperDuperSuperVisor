/*
 *@defGPIO.h
 *
 *@Created on:  5.12.2019
 *@Author: KamilM
 *
 *@brief Header file with define all of used GPIO pins
 */

#ifndef DEFGPIO_H_
#define DEFGPIO_H_

#include <GPIODriver.h>


int GPIO_InitializeAll();


//Encoder CH1, first encoder
#define EncoderCh1_port    PORTA
#define EncoderCh1_pin     PIN0
GPIOcfgType EncoderCh1;

//Encoder CH2, first encoder
#define EncoderCh2_port	  PORTA
#define EncoderCh2_pin    PIN1
GPIOcfgType EncoderCh2;

//Greed Led
#define LedGreen_port     PORTD
#define	LedGreen_pin      PIN12
GPIOcfgType LedGreen;

//Wheel Left PWM Channel_1
#define WheelLeftPWM_port   PORTB
#define WheelLeftPWM_pin    PIN4
GPIOcfgType WheelLeftPWM;


//Sonic ECHO universal
#define HC_ECHO_port     PORTB
#define HC_ECHO_pin      PIN8
GPIOcfgType HC_ECHO;

//Trigger of left sonic sensor
#define HCTriggerLeft_port    PORTE
#define HCTriggerLeft_pin     PIN0
GPIOcfgType HCTriggerLeft;

//UART3 Text
#define UARTText_port    PORTB
#define UARTText_pin     PIN10
GPIOcfgType UARTText;

//UART3 Read
#define UARTRead_port    PORTB
#define UARTRead_pin     PIN11
GPIOcfgType UARTRead;


//Red diode
#define DiodeRed_port    PORTD
#define DiodeRed_pin     PIN14
GPIOcfgType DiodeRed;

//Orange diode
#define DiodeOrange_port    PORTD
#define DiodeOrange_pin     PIN13
GPIOcfgType DiodeOrange;
#endif /* DEFGPIO_H_ */
