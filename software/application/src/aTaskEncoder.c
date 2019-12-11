/**
 * @file aTaskEncoder.c
 *
 * @Created on: 10.12.2019
 * @Author: Kamil
 *
 * @brief implementation of basic encoder task
 */
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "declarations.h"
#include "encoder.h"


void vEncoder( void *pvParameters )
{
    for( ;; )
    {

      vTaskDelay( 100 / portTICK_RATE_MS );
    }
    vTaskDelete( NULL );
}
