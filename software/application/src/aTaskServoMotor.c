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


void vServoMotor( void *pvParameters )
{
    for( ;; )
    {

    }
    vTaskDelete( NULL );
}

