/**
 * @file declarations.h
 *
 * @Created on: 10.12.2019
 * @Author: Kamil
 *
 * @brief FreeRTOS declaration of tasks, queue, semaphores and other
 */

#ifndef DECLARATIONS_H_
#define DECLARATIONS_H_

#include "task.h"

TaskHandle_t xSonicSensor;
TaskHandle_t xServoMotor;
TaskHandle_t xEncoder;

#endif /* DECLARATIONS_H_ */
