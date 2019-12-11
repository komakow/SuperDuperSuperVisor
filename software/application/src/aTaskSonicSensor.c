/**
 * @file aTaskSonicSensor.c
 *
 * @Created on: 10.12.2019
 * @Author: Kamil
 *
 * @brief Implementation of Sonic Sensor task
 */
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "HC_SR04.h"

void vSonicSensor( void *pvParameters )
{
	float distance;
    for( ;; )
    {
      taskENTER_CRITICAL();
    	distance = HC_SR04_ReadDistance();
    	taskEXIT_CRITICAL();

      vTaskDelay( 100 / portTICK_RATE_MS );
    }
    vTaskDelete( NULL );
}
