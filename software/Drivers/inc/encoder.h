/*
 *@encoder.c
 *
 *@Created on:  5.12.2019
 *@Author: KamilM
 *
 *@brief Driver for basic encoder
 */

#ifndef ENCODER_H_
#define ENCODER_H_

typedef int err;

#define E_OK                0    //Operation success
#define E_NOT_INITIALIZED  -1    //Encoder not initialize
#define E_NOT_READ         -2    //Data is not read from register
//...TODO multiple if necessary

/**
 * @brief user callback used at IRQ from encoder
 * @param direction - 0 - if left, 1- if right side
 */
typedef void (*userCB)(uint8_t direction);

/**
 * @brief Initial function for encoder
 *
 * @param callback - callback called at IRS from encoder
 *
 * @return Status of operation
 */
err Encoder_Init(userCB);

/**
 * @brief Function enabling interrupts used by Encoder driver
 *
 * @param None
 *
 * @return Status of operation
 */
err Encoder_IRQ_Enable();

/**
 * @brief Function disabling interrupts used by Encoder driver
 *
 * @param None
 *
 * @return Status of operation
 */
err Encoder_IRQ_Disable();

/**
 * @brief Function for deinitialization encoder and all connected peripheral
 *
 * @param None
 *
 * @return Status of operation
 */
err Encoder_DeInit();


#endif /* ENCODER_H_ */
