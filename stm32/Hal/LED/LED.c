/********************************************/
/* file name : LED.c */
/* Author      : sara hossny         */
/* Date        : 14/8/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 
#include "STD_Types.h"

#include "GPIO.h"

#include "LED.h"
#include "LED_cfg.h"
#include "LED_priv.h"


tenuErrorStatus LED_enuWriteValue (uint8 u8LedNumCpy , uint8 u8LedValueCpy  )
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	if (u8LedNumCpy < LED_MAX_NUM )
	{
		switch(u8LedValueCpy)
		{
			case LED_u8ON :
				if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8NORMAL)
				{
					enuReturnStatLoc =MGPIO_u8SetPinVal(LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPort,LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPinMap, GPIO_HIGH );
					
				}
				else if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8REVERSE)
				{
					enuReturnStatLoc =MGPIO_u8SetPinVal(LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPort,LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPinMap, GPIO_LOW );			
				}
				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}
			break ;
			case LED_u8OFF:
			   if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8NORMAL)
				{
					enuReturnStatLoc =MGPIO_u8SetPinVal(LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPort,LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPinMap, GPIO_LOW );
				}
				else if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8REVERSE)
				{
					enuReturnStatLoc =MGPIO_u8SetPinVal(LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPort,LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPinMap, GPIO_HIGH );		
				}
				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}					
			break ;
			default :
				enuReturnStatLoc =E_NOK_PARAM_OUT_OF_RANGE ;
            break ;				
		}
	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
	
}

tenuErrorStatus LED_enuToggle (uint8 u8LedNumCpy )
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	if (u8LedNumCpy < LED_MAX_NUM )
	{
		enuReturnStatLoc = MGPIO_u8ToglePinVal(LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPort,LED_astrLedPinMapping[u8LedNumCpy].u8GPIOPinMap);
	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
}

