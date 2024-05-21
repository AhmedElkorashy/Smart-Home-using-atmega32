/*
 * STEPER_Iterface.h
 *
 *  Created on: Mar 21, 2024
 *      Author: User
 */

#ifndef HALL_STEPER_STEPER_ITERFACE_H_
#define HALL_STEPER_STEPER_ITERFACE_H_

#define NORTH				0
#define EASTERN_NORTH		1
#define EAST				2
#define EASTERN_SOUTH		3
#define SOUTH				4
#define WESTERN_SOUTH		5
#define WEST				6
#define WESTERN_NORTH		7

#include "STEPER_Config.h"
void STEPPER_voidRotate(u8 Copy_u8Direction);
void STEPPER_voidInit(void);


#endif /* HALL_STEPER_STEPER_ITERFACE_H_ */
