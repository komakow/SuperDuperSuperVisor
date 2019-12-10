/*
 *@defGPIO.c
 *
 *@Created on: 5.12.2019
 *@Author: KamilM
 *
 *@brief Source code for config all of GPIO ports and pins.
 */

#include <GPIODriver.h>
#include "defGPIO.h"
#include "stm32f4xx.h"

int GPIO_InitializeAll()
{

	int ret=0;

	LedGreen.mode 	= output;
	LedGreen.pin 	  = LedGreen_pin;
	LedGreen.port 	= LedGreen_port;
	LedGreen.pull	  = pullDown;
	LedGreen.typ	  = pushPull;
	if(gpioCfg(&LedGreen) != 0) 			//if status of init GPIO is 'error'
	{
		ret = -1;
	}


	EncoderCh1.mode 	= alternate;
	EncoderCh1.pin 		= EncoderCh1_pin;
	EncoderCh1.port 	= EncoderCh1_port;
	EncoderCh1.pull		= pullUp;
	EncoderCh1.typ		= pushPull;
	EncoderCh1.speed 	= medium;
	EncoderCh1.alter	= AF2;
	if(gpioCfg(&EncoderCh1) != 0) 			//if status of init GPIO is 'error'
	{
		ret = -2;
	}


	EncoderCh2.mode 	= alternate;
	EncoderCh2.pin 		= EncoderCh2_pin;
	EncoderCh2.port 	= EncoderCh2_port;
	EncoderCh2.pull		= pullUp;
	EncoderCh2.typ		= pushPull;
	EncoderCh2.speed 	= medium;
	EncoderCh2.alter	= AF2;
	if(gpioCfg(&EncoderCh2) != 0) 	  //if status of init GPIO is 'error'
	{
		ret = -3;
	}

	WheelLeftPWM.mode 	  = alternate;
	WheelLeftPWM.pin 	    = WheelLeftPWM_pin;
	WheelLeftPWM.port 	  = WheelLeftPWM_port;
	WheelLeftPWM.pull	    = pullUp;
	WheelLeftPWM.typ	    = pushPull;
	WheelLeftPWM.speed 	  = high;
	WheelLeftPWM.alter	  = AF2;
	if(gpioCfg(&WheelLeftPWM) != 0)     //if status of init GPIO is 'error'
	{
		ret = -4;
	}

	HC_ECHO.mode 	  = alternate;
	HC_ECHO.pin 	  = HC_ECHO_pin;
	HC_ECHO.port 	  = HC_ECHO_port;
	HC_ECHO.pull	  = pullDown;
	HC_ECHO.typ		  = pushPull;
	HC_ECHO.speed 	= medium;
	HC_ECHO.alter	  = AF3;
	if(gpioCfg(&HC_ECHO) != 0) 	 //if status of init GPIO is 'error'
	{
		ret = -5;
	}

	HCTriggerLeft.mode 		= output;
	HCTriggerLeft.pin 		= HCTriggerLeft_pin;
	HCTriggerLeft.port 		= HCTriggerLeft_port;
	HCTriggerLeft.pull		= pullDown;
	HCTriggerLeft.typ		  = pushPull;
	HCTriggerLeft.speed 	= medium;
	if(gpioCfg(&HCTriggerLeft) != 0)   //if status of init GPIO is 'error'
	{
		ret = -6;
	}

	UARTText.mode 		= alternate;
	UARTText.pin 		  = UARTText_pin;
	UARTText.port 		= UARTText_port;
	UARTText.pull		  = pullUp;
	UARTText.typ		  = pushPull;
	UARTText.speed 		= medium;
	UARTText.alter		= AF7;
	if(gpioCfg(&UARTText) != 0)   //if status of init GPIO is 'error'
	{
		ret = -7;
	}

	UARTRead.mode 		= alternate;
	UARTRead.pin 		  = UARTRead_pin;
	UARTRead.port 		= UARTRead_port;
	UARTRead.pull		  = pullUp;
	UARTRead.typ		  = pushPull;
	UARTRead.speed 		= medium;
	UARTRead.alter		= AF7;
	if(gpioCfg(&UARTRead) != 0)   //if status of init GPIO is 'error'
	{
		ret = -8;
	}


	DiodeRed.mode     = output;
	DiodeRed.pin      = DiodeRed_pin;
	DiodeRed.port     = DiodeRed_port;
	DiodeRed.pull     = pullDown;
	DiodeRed.typ      = pushPull;
	DiodeRed.speed    = medium;
	if(gpioCfg(&DiodeRed) != 0)   //if status of init GPIO is 'error'
	{
		ret = -9;
	}


  DiodeOrange.mode     = output;
  DiodeOrange.pin      = DiodeOrange_pin;
  DiodeOrange.port     = DiodeOrange_port;
  DiodeOrange.pull     = pullDown;
  DiodeOrange.typ      = pushPull;
  DiodeOrange.speed    = medium;
  if(gpioCfg(&DiodeOrange) != 0)   //if status of init GPIO is 'error'
  {
	ret = -10;
  }

return ret;
}
