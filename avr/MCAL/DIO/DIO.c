/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO  module                             */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  Atmega 32                                               */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2022 by ITI .       All rights reserved.                      */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1       aaboelno     Initial Creation                        */
/********************************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"


#include  "DIO.h"
#include  "DIO_cfg.h"
#include  "DIO_priv.h"



void DIO_voidInit(void)
{
	
	DDRA = CONC(DIO_u8DIR_PIN_A7,DIO_u8DIR_PIN_A6,DIO_u8DIR_PIN_A5,DIO_u8DIR_PIN_A4,DIO_u8DIR_PIN_A3,DIO_u8DIR_PIN_A2,DIO_u8DIR_PIN_A1,DIO_u8DIR_PIN_A0);
	DDRB = CONC(DIO_u8DIR_PIN_B7,DIO_u8DIR_PIN_B6,DIO_u8DIR_PIN_B5,DIO_u8DIR_PIN_B4,DIO_u8DIR_PIN_B3,DIO_u8DIR_PIN_B2,DIO_u8DIR_PIN_B1,DIO_u8DIR_PIN_B0);
	DDRC = CONC(DIO_u8DIR_PIN_C7,DIO_u8DIR_PIN_C6,DIO_u8DIR_PIN_C5,DIO_u8DIR_PIN_C4,DIO_u8DIR_PIN_C3,DIO_u8DIR_PIN_C2,DIO_u8DIR_PIN_C1,DIO_u8DIR_PIN_C0);
	DDRD = CONC(DIO_u8DIR_PIN_D7,DIO_u8DIR_PIN_D6,DIO_u8DIR_PIN_D5,DIO_u8DIR_PIN_D4,DIO_u8DIR_PIN_D3,DIO_u8DIR_PIN_D2,DIO_u8DIR_PIN_D1,DIO_u8DIR_PIN_D0);
	
	
}

/* Description : function write DIO_u8HIGH or DIO_u8LOW on Pin start 0 to 31 */
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	
	switch (u8PinValueCpy)
		{
			case DIO_u8HIGH :
				if (u8PinNumCpy >= DIO_u8PIN_B0  && u8PinNumCpy <= DIO_u8PIN_B7 )
				{
					SET_BIT(ODRB ,u8PinNumCpy-DIO_u8PIN_B0   ) ;

				}
				else if (u8PinNumCpy >= DIO_u8PIN_D0  && u8PinNumCpy <= DIO_u8PIN_D7 )
				{
					SET_BIT(ODRD ,u8PinNumCpy-DIO_u8PIN_D0   ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_C0  && u8PinNumCpy <= DIO_u8PIN_C7 )
				{
					SET_BIT(ODRC ,u8PinNumCpy-DIO_u8PIN_C0 ) ;
				}
				else if (u8PinNumCpy <= DIO_u8PIN_A0  && u8PinNumCpy >= DIO_u8PIN_D7 )
				{
					SET_BIT(ODRA , DIO_u8PIN_A0-u8PinNumCpy ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			break ;
			case DIO_u8LOW :
				if (u8PinNumCpy >= DIO_u8PIN_B0  && u8PinNumCpy <= DIO_u8PIN_B7 )
				{
					CLR_BIT(ODRB ,u8PinNumCpy-DIO_u8PIN_B0   ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_D0  && u8PinNumCpy <= DIO_u8PIN_D7 )
				{
					CLR_BIT(ODRD , u8PinNumCpy-DIO_u8PIN_D0 ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_C0  && u8PinNumCpy <= DIO_u8PIN_C7 )
				{
					CLR_BIT(ODRC ,u8PinNumCpy-DIO_u8PIN_C0 ) ;
				}
				if (u8PinNumCpy <= DIO_u8PIN_A0  && u8PinNumCpy >= DIO_u8PIN_A7 )
				{
					CLR_BIT(ODRA , DIO_u8PIN_A0-u8PinNumCpy ) ;
				}

				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			
			break ;
			default :
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
			break ;
			
		}
	
	return enuReturnStatusLoc ;
	
}

tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy , uint8 * pu8PinValueCpy)
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;
	
	if (pu8PinValueCpy != NULL_PTR)
		
	{

				if (u8PinNumCpy >= DIO_u8PIN_B0  && u8PinNumCpy <= DIO_u8PIN_B7 )
				{
					*pu8PinValueCpy = GET_BIT(IDRB ,u8PinNumCpy-DIO_u8PIN_B0   ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_D0  && u8PinNumCpy <= DIO_u8PIN_D7 )
				{
					*pu8PinValueCpy = GET_BIT(IDRD , u8PinNumCpy-DIO_u8PIN_D0 ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_C0  && u8PinNumCpy <= DIO_u8PIN_C7 )
				{
					*pu8PinValueCpy = GET_BIT(IDRC ,u8PinNumCpy-DIO_u8PIN_C0 ) ;
				}

				else if (u8PinNumCpy <= DIO_u8PIN_A0  && u8PinNumCpy >= DIO_u8PIN_A7 )
				{
				*pu8PinValueCpy = GET_BIT(IDRA , DIO_u8PIN_A0-u8PinNumCpy ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
	}	     
	
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	
	return enuReturnStatusLoc ;
	
}

tenuErrorStatus DIO_enuPullWrite(uint8 u8PinNumCpy , uint8 u8PinStateCpy)
{
	return DIO_enuWritePin(u8PinNumCpy , u8PinStateCpy );
}

tenuErrorStatus DIO_enuWriteBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy )
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;
	uint8 u8CntrLoc ;
	if(pastrPinMappingCpy !=NULL_PTR)
	{
		if (u8SizeCpy <= DIO_u8MAX_NUMBER_OF_PINS )
		{
			for (u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
			{
				pastrPinMappingCpy[u8CntrLoc]. enuStatus  = DIO_enuWritePin(pastrPinMappingCpy[u8CntrLoc].u8PinNum , pastrPinMappingCpy[u8CntrLoc].u8PinValue );
			}
		}
		else
		{
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
		}
		
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	return enuReturnStatusLoc ;
}

tenuErrorStatus DIO_enuReadBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy )
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;
	uint8 u8CntrLoc ;
	
	if(pastrPinMappingCpy != NULL_PTR )
	{
		if (u8SizeCpy <= DIO_u8MAX_NUMBER_OF_PINS)
		{
			for (u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
			{
				pastrPinMappingCpy[u8CntrLoc]. enuStatus  = DIO_enuReadPin(pastrPinMappingCpy[u8CntrLoc].u8PinNum , &(pastrPinMappingCpy[u8CntrLoc].u8PinValue) );
			}
		}
		else
		{
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
		}
		
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	return enuReturnStatusLoc ;
}

tenuErrorStatus DIO_enuWritePinDir(uint8 u8PinNumCpy , uint8 u8PinDirCpy)
	{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	
	switch (u8PinDirCpy)
		{
			case DIO_u8OUTPUT  :
				if (u8PinNumCpy >= DIO_u8PIN_B0  && u8PinNumCpy <= DIO_u8PIN_B7 )
				{
					SET_BIT(DDRB ,u8PinNumCpy-DIO_u8PIN_B0   ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_D0  && u8PinNumCpy <= DIO_u8PIN_D7 )
				{
				SET_BIT(DDRD , u8PinNumCpy-DIO_u8PIN_D0 ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_C0  && u8PinNumCpy <= DIO_u8PIN_C7 )
				{
					SET_BIT(DDRC ,u8PinNumCpy-DIO_u8PIN_C0 ) ;
				}
				else if (u8PinNumCpy <= DIO_u8PIN_A0  && u8PinNumCpy >= DIO_u8PIN_A7 )
				{
					SET_BIT(DDRA , DIO_u8PIN_A0-u8PinNumCpy ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			break ;
			case DIO_u8INPUT:
				if (u8PinNumCpy >= DIO_u8PIN_B0  && u8PinNumCpy <= DIO_u8PIN_B7 )
				{
					CLR_BIT(DDRB ,u8PinNumCpy-DIO_u8PIN_B0   ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_D0  && u8PinNumCpy <= DIO_u8PIN_D7 )
				{
					CLR_BIT(DDRD , u8PinNumCpy-DIO_u8PIN_D0 ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_C0  && u8PinNumCpy <= DIO_u8PIN_C7 )
				{
					CLR_BIT(DDRC ,u8PinNumCpy-DIO_u8PIN_C0 ) ;
				}

				else if (u8PinNumCpy <= DIO_u8PIN_A0  && u8PinNumCpy >= DIO_u8PIN_A7 )
				{
					CLR_BIT(DDRA , DIO_u8PIN_A0-u8PinNumCpy ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
			
			break ;
			default :
			enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
			break ;
			
		}
	
	return enuReturnStatusLoc ;
	
	
}

tenuErrorStatus DIO_enuTogglePin(uint8 u8PinNumCpy)
{
	tenuErrorStatus enuReturnStatusLoc = E_OK ;

				if (u8PinNumCpy >= DIO_u8PIN_B0  && u8PinNumCpy <= DIO_u8PIN_B7 )
				{
					TGL_BIT(ODRB ,u8PinNumCpy-DIO_u8PIN_B0   ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_D0  && u8PinNumCpy <= DIO_u8PIN_D7 )
				{
					TGL_BIT(ODRD , u8PinNumCpy-DIO_u8PIN_D0 ) ;
				}
				else if (u8PinNumCpy >= DIO_u8PIN_C0  && u8PinNumCpy <= DIO_u8PIN_C7 )
				{
					TGL_BIT(ODRC ,u8PinNumCpy-DIO_u8PIN_C0 ) ;
				}
				else if (u8PinNumCpy <= DIO_u8PIN_A0  && u8PinNumCpy >= DIO_u8PIN_A7 )
				{
					TGL_BIT(ODRA , DIO_u8PIN_A0-u8PinNumCpy ) ;
				}
				else
				{
					enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
				}
	
	return enuReturnStatusLoc ;
}

