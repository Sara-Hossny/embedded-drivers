/********************************************/
/* Description : RCC */
/* Author      : sara hossny         */
/* Date        : 9/8/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef  RCC_H 
#define  RCC_H
#include "STD_Types.h"
void RCC_VoidInit (void);
void RCC_VoidEnablePeripheral(uint8 copyu8PerNumber ,uint8 copyu8BusNumber );
#endif