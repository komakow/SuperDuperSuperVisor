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
#include "declarations.h"

void vSonicSensor( void *pvParameters )
{
	uint16_t distance[3];
	uint16_t distanceMean = 0;
    for( ;; )
    {
      distanceMean = 0;
      for(int a=0;a<3;a++)
      {
        distance[a] = (uint16_t)HC_SR04_ReadDistance();
        distanceMean += distance[a];
      }
      distanceMean = distanceMean /3;

    	xQueueSend(xSonicSensorQue,&distanceMean, 100);

      vTaskDelay( 40 / portTICK_RATE_MS );
    }
    vTaskDelete( NULL );
}
