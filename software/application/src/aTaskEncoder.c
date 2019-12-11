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

volatile uint8_t directFromISR;


//Task
void vEncoder( void *pvParameters )
{
  //if 0-left, if 1-right
  uint8_t directionOfEncoder;
  uint8_t diodeTouch = 1;
    for( ;; )
    {
      if(xQueueReceive(xEncoderQue,&directionOfEncoder, 0) == pdTRUE)
      {
        if(directionOfEncoder == 0)
        {
          xQueueSend(xDiodePlusQue, &diodeTouch, 0);
        }
        else
        {
          xQueueSend(xDiodeMinusQue, &diodeTouch, 0);
        }
      }
      vTaskDelay( 50 / portTICK_RATE_MS );
    }
    vTaskDelete( NULL );
}

//function called at encoder driver from IRQ
void irsFromEncoder(uint8_t direct)
{
  directFromISR = direct;
  xQueueSendFromISR(xEncoderQue, &directFromISR, pdFALSE);
}
