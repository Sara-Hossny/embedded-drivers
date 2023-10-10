/********************************************/
/* file name : LED.h */
/* Author      : sara hossny         */
/* Date        : 14/8/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef LED_H
#define LED_H

#include "LED_cfg.h"

#define LED_u8ON    ((uint8) 0x01)
#define LED_u8OFF   ((uint8) 0x00)


tenuErrorStatus LED_enuWriteValue (uint8 u8LedNumCpy , uint8 u8LedValueCpy);
tenuErrorStatus LED_enuToggle (uint8 u8LedNumCpy );



#endif









