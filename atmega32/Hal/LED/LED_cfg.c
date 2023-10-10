/********************************************/
/* file name : LED_cfg.c */
/* Author      : sara hossny         */
/* Date        : 14/8/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 
#include "STD_Types.h"

#include "GPIO.h"

#include "LED_cfg.h"
#include "LED_priv.h"

tstrPinMappingCfg LED_astrLedPinMapping[LED_MAX_NUM]={
	
	{GPIO_PORTA, 1 , LED_u8NORMAL },

	
};





