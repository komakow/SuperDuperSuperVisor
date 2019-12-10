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



static void prvSetupHardware(void);
void vATaskFunction( void *pvParameters );
void vLedTask1( void *pvParameters );
void vLedTask2( void *pvParameters );

void vApplicationTickHook( void );
TaskHandle_t xLed1;
TaskHandle_t xLed2;

static void prvSetupHardware(void);
void vATaskFunction( void *pvParameters );
void vLedTask1( void *pvParameters );
void vLedTask2( void *pvParameters );

void vApplicationTickHook( void );

int main(void)
{
  int i = 0;

	// Hardware configuration
	prvSetupHardware();

	xTaskCreate( vLedTask1, "LEDTask1", 100, NULL, 1, &xLed1 );
	xTaskCreate( vLedTask2, "LEDTask2", 100, NULL, 2, &xLed2 );

	// Start the scheduler
	vTaskStartScheduler(); // should never return

  /* Infinite loop */
  while (1)
  {
	i++;
  }
}



static void prvSetupHardware(void)
{


}

void vLedTask1( void *pvParameters )
{
    for( ;; )
    {
    }
    vTaskDelete( NULL );
}


void vLedTask2( void *pvParameters )
{
    for( ;; )
    {

    }
    vTaskDelete( NULL );
}

void vApplicationTickHook( void )
{

}
