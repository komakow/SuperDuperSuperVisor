/**
 *@diodesDriver.h
 *@Created on: 24.04.2018
 *@Author: KamilM
 *
 *@brief Source code of diodes driver working at STM32F407
 */

#ifndef INC_DIODESDRIVER_H_
#define INC_DIODESDRIVER_H_

#define NUMBER_OF_ALL_DIODES   6    //number of used diodes

/**
 * @brief Function enable diodes. Enable only first 'numOfDiodes', rest of them are disable
 * @param numOfDiodes - number of diodes to set
 *
 * @return none
 */
void setDiodes(uint8_t numOfDiodes);


#endif /* INC_DIODESDRIVER_H_ */
