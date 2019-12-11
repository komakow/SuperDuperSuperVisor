/**
 *@ServoDriver.h
 *
 *@Created on: 24.04.2018
 *@Author: KamilM
 *
 *@Brief Interface of servo motor
 *@Brief Phase = 1 reverse rotation
 *@Brief Phase = 0 forward rotation
 */


#ifndef SERVODRIVER_H_
#define SERVODRIVER_H_

#include "stm32f4xx.h"         //TODO: If interface used by other microprocessor, you need to change this header

typedef int err;

#define E_OK                  0			//Operation success
#define E_NOT_INITIALIZED    -1			//Encoder not initialize
#define E_NOT_WORK           -2			//Other type of error
//...TODO multiple if necessary


/*
 * @brief Function used to initialized timers and other periphery used by H Bridge
 *
 * @param None
 *
 * @return Status of operation
 */
err servo_Init();

/*
 * @brief Function used to control left/right wheel of vehicle.
 *
 * @param uint8_t speed - speed of rotation expressed by number between 0-255, where 0-127 is left, 128-255 is right rotation
 *
 * @return Status of operation
 */
err WheelControl(uint8_t speed);


/*
 * @brief Function used to stop both of wheel. This function is use for immediately stop the vehicle
 *
 * @param None
 *
 * @return Status of operation
 */
err WheelStop();

/*
 * @brief Function used to deinitialized all of periphery used by H bridge. All of register of timer would be cleared.
 *
 * @param None
 *
 * @return Status of operation
 */
err servo_DeInit();

#endif /* SERVODRIVER_H_ */
