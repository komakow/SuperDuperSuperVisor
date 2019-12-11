/**
 * @file aTaskServoMotor.c
 *
 * @Created on: 10.12.2019
 * @Author: Kamil
 *
 * @brief Implementation of Servo Motor task
 */
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "diodesDriver.h"


void vServoMotor( void *pvParameters )
{
    for( ;; )
    {
      for(int a=0;a<7;a++)
      {
        setDiodes(a);
        vTaskDelay( 500 / portTICK_RATE_MS );
      }
    }
    vTaskDelete( NULL );
}

