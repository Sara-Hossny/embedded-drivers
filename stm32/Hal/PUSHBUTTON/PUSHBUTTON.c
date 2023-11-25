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

#include "PUSHBUTTON.h"
#include "PUSHBUTTON_cfg.h"
#include "PUSHBUTTON_priv.h"


tenuErrorStatus pushbutton_intial(){
	tenuErrorStatus error = E_OK;
	uint8 u8counterloc;
	for(u8counterloc=0;u8counterloc<PUSHBUTTON_MAX_NUM;u8counterloc++ ){
			if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8PUSHBUTTIONModeConc==PULLUP_CONNECTION){
				MGPIO_vSetPinInputPull(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8GPIOPort, PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8GPIOPinMap , GPIO_PULL_UP);
			}
			else if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8PUSHBUTTIONModeConc==PULLDOWN_CONNECTION){
								MGPIO_vSetPinInputPull(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8GPIOPort, PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8counterloc].u8GPIOPinMap , GPIO_PULL_DOWN);
			}
			else{
				error=E_NOK_CONFIG_PARM_ERROR;
			}
			

	}
	return error;
}

tenuErrorStatus pushbutton_enureadState (uint8 u8PUSHBUTTONNumCpy , uint8 * u8PUSHBUTTONValueCpy){
	tenuErrorStatus error = E_OK;
	
	
	if(u8PUSHBUTTONValueCpy!=NULL_PTR){
		if(u8PUSHBUTTONNumCpy<PUSHBUTTON_MAX_NUM){
		 MGPIO_u8GetPinVal(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8GPIOPort, PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8GPIOPinMap ,u8PUSHBUTTONValueCpy );
	if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8PUSHBUTTIONModeConc==PULLUP_CONNECTION){
				if(*u8PUSHBUTTONValueCpy == GPIO_LOW){
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_PRESSED;
				}
				else{
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_NOT_PRESSED ;
				
				}
			}
			else if(PUSHBUTTION_astrPUSHBUTTIONPinMapping[u8PUSHBUTTONNumCpy].u8PUSHBUTTIONModeConc==PULLDOWN_CONNECTION){
				if(*u8PUSHBUTTONValueCpy == GPIO_HIGH ){
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_PRESSED;
				}
				else{
					*u8PUSHBUTTONValueCpy =PUSHBUTTON_NOT_PRESSED ;
				
				}
				
			}

		else{
			error=E_NOK_PARAM_OUT_OF_RANGE;
		}

		}
		else{
						error=E_NOK_CONFIG_PARM_ERROR;
					}

	}
	else{
		error=E_NOK_PARAM_NULL_POINTER;
	}
	return error;
}

