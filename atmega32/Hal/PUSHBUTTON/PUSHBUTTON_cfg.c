/********************************************************************************/
/**    File Name: PUSHBUTTON.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PUSHBUTTON contain configuration for the module*/
/* Author      : sara hossny         													*/
/* Date        : 14/8/2023                  											*/
/* Version     : 0.1V                       											*/
/****************************************************************************************/
 
#include "STD_Types.h"

#include "GPIO.h"

#include "PUSHBUTTON_cfg.h"
#include "PUSHBUTTON_priv.h"

tstrPinMappingCfg PUSHBUTTION_astrPUSHBUTTIONPinMapping[PUSHBUTTON_MAX_NUM]={
	{GPIO_PORTB, 1 , PULLUP_CONNECTION }

	
};





