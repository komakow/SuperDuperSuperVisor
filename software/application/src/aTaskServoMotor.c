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
#include "declarations.h"

//one step of one diode
#define ONE_STEP_OF_DIODE  (uint16_t)10



void vServoMotor( void *pvParameters )
{
  //all diode enable at 50cm from sonic sensor
  uint16_t treshholdDiode = 20;
  uint16_t distance;
  uint8_t encoderFoo;
    for( ;; )
    {
      //queue from sonic sensor
      if(xQueueReceive(xSonicSensorQue, &distance, 0) == pdTRUE)
      {
        if(distance < treshholdDiode)
        {
          setDiodes(1);  //set only one diode
        }
        if((distance - treshholdDiode) > (ONE_STEP_OF_DIODE * 1))
        {
          setDiodes(2);  //set only two diodes
        }
        if((distance - treshholdDiode) > (ONE_STEP_OF_DIODE * 2))
        {
          setDiodes(3);
        }
        if((distance - treshholdDiode) > (ONE_STEP_OF_DIODE * 3))
        {
          setDiodes(4);
        }
        if((distance - treshholdDiode) > (ONE_STEP_OF_DIODE * 4))
        {
          setDiodes(5);
        }
        if((distance - treshholdDiode) > (ONE_STEP_OF_DIODE * 5))
        {
          setDiodes(6);
        }
      }

      //queue from encoder
      if(xQueueReceive(xDiodeMinusQue, &encoderFoo, 0) == pdTRUE)
      {
        if(treshholdDiode > ONE_STEP_OF_DIODE)
        {
          treshholdDiode = treshholdDiode - ONE_STEP_OF_DIODE;
        }
      }
      //queue from encoder
      if(xQueueReceive(xDiodePlusQue, &encoderFoo, 0) == pdTRUE)
      {
        treshholdDiode = treshholdDiode + ONE_STEP_OF_DIODE;
      }
      vTaskDelay( 20 / portTICK_RATE_MS );

    }
    vTaskDelete( NULL );
}

