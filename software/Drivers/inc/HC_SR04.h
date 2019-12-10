/*
 *@HC-SR04.h
 *
 *@Created on: 07.05.2018
 *@Author: Kamil Malski
 *
 *@brief Header file of ultrasonic sensor used by "Odjechana Platforma" project.
 */

#ifndef HC_SR04_H_
#define HC_SR04_H_


/*
 * @brief Function used to initial all of sonic sensor installed on platform
 *
 * @param None
 *
 * @return None
 */
void HC_SR04_Init();

/*
 * @brief Function used to read distance from sonic sensor installed on platform
 *
 * @param - none
 *
 * @return Read distance from sensor in [cm]
 */
float HC_SR04_ReadDistance();

/*
 * @brief Function used to deinitialization all of periphery used by sonic sensor
 *
 * @param None
 *
 * @return None
 */
void HC_SR04_DeInit();


#endif /* HC_SR04_H_ */
