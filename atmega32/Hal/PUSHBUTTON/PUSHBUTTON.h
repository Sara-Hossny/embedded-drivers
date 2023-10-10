/********************************************************************************/
/**    File Name: PUSHBUTTON.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PUSHBUTTON contain configuration for the module*/
/* Author      : sara hossny         													*/
/* Date        : 14/8/2023                  											*/
/* Version     : 0.1V                       											*/
/****************************************************************************************/
 /* Gaurd */
#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#define  PUSHBUTTON_PRESSED    ((uint8) 1)
#define  PUSHBUTTON_NOT_PRESSED    ((uint8) 0)

#include "PUSHBUTTON_cfg.h"

tenuErrorStatus pushbutton_intial();

tenuErrorStatus pushbutton_enureadState (uint8 u8PUSHBUTTONNumCpy , uint8 * u8PUSHBUTTONValueCpy);




#endif








