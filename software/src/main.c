/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2019-11-06
*/
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "defGPIO.h"
#include "encoder.h"
#include "declarations.h"
#include "aTaskSonicSensor.h"
#include "aTaskServoMotor.h"
#include "aTaskEncoder.h"
#include "ServoDriver.h"
#include "HC_SR04.h"



static void prvSetupHardware(void);
static void prvSetupHardware(void);


void vATaskFunction( void *pvParameters );
void vApplicationTickHook( void );
void vApplicationTickHook( void );
void vATaskFunction( void *pvParameters );



int main(void)
{
  int i = 0;

	// Hardware configuration
	prvSetupHardware();

	//create tasks
	xTaskCreate( vSonicSensor, "sonic", 100, NULL, 3, &xSonicSensor );
	xTaskCreate( vServoMotor, "servo", 100, NULL, 2, &xServoMotor );
	xTaskCreate( vEncoder, "encoder", 100, NULL, 2, &xEncoder );

	//create queue
	xEncoderQue = xQueueCreate(1, sizeof(uint8_t));
	xDiodePlusQue = xQueueCreate(1, sizeof(uint8_t));
  xDiodeMinusQue = xQueueCreate(1, sizeof(uint8_t));
  xSonicSensorQue = xQueueCreate(1, sizeof(uint16_t));


	// Start the scheduler
	vTaskStartScheduler();

  /* Infinite loop */
  while (1)
  {
	i++;
  }
}



static void prvSetupHardware(void)
{
  uint8_t err = 0;
	err += GPIO_InitializeAll();            //init GPIO
	err += Encoder_Init(&irsFromEncoder);   //init Encoder
  HC_SR04_Init();                         //init sonic sensor
	err += servo_Init();                    //init servo

	if(err !=0)
	{
	  gpioPinSetState(DiodeRed_port,DiodeRed_pin, 1);
	}

}



void vApplicationTickHook( void )
{

}
