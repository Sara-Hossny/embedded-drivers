/********************************************************************************/
/**    File Name: SEV.h                                                         */
/**                                                                             */
/**  Description: Implementation of the SEV contain configuration for the module*/
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
/** SaraH     Sara Hossny          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 30/08/2022   0.1       SaraH     Initial Creation                        */
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "SEV.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"

static  void Sev_voidHelp(uint8 u8SevNumCpy , uint8 u8ValueCpy , uint8 u8ModeCpy);

static tstrbfSevPinValueParam SEV_astrbfPinValue [SEV_u8WRITE_MAX_NUM] = 
{
	{1,1,1,1,1,1,0}, /*0x3F*/
	{0,1,1,0,0,0,0}, /*0x06*/
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};


tenuErrorStatus SEV_enuWrite(uint8 u8SevNumCpy , uint8 u8ValueCpy)
{
	tenuErrorStatus enuReturnStateLoc = E_OK;
	
	if(u8SevNumCpy < SEV_MAX_NUM)
	{
		if(u8ValueCpy <= SEV_u8WRITE_NUM_9)
		{
			Sev_voidHelp(u8SevNumCpy , u8ValueCpy , SEV_astrPinMapping[u8SevNumCpy].u8SevConnection);
		}
		else
		{
			 enuReturnStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
		}
		
	}
	else
	{
		enuReturnStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	
	return enuReturnStateLoc ;
	
}

tenuErrorStatus SEV_enuMode(uint8 u8SevNumCpy  , uint8 u8ModeCpy)
{
	tenuErrorStatus enuReturnStateLoc = E_OK ;
	
	if (u8SevNumCpy < SEV_MAX_NUM )
	{
		switch(u8ModeCpy)
		{
			case  SEV_u8ON :
				if(SEV_astrPinMapping[u8SevNumCpy].u8SevConnection == SEV_u8COMMON_ANODE)
				{
					enuReturnStateLoc = DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevCommonPin , DIO_u8HIGH) ;
				}
				else if (SEV_astrPinMapping[u8SevNumCpy].u8SevConnection == SEV_u8COMMON_CATHODE)
				{
					enuReturnStateLoc = DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevCommonPin , DIO_u8LOW) ;
				}
				else 
				{
					 enuReturnStateLoc = E_NOK_CONFIG_PARM_ERROR ;
				}
			break ;
			case SEV_u8OFF :
				if(SEV_astrPinMapping[u8SevNumCpy].u8SevConnection == SEV_u8COMMON_ANODE)
				{
					enuReturnStateLoc = DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevCommonPin , DIO_u8LOW) ;
				}
				else if (SEV_astrPinMapping[u8SevNumCpy].u8SevConnection == SEV_u8COMMON_CATHODE)
				{
					enuReturnStateLoc = DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevCommonPin , DIO_u8HIGH) ;
				}
				else 
				{
					 enuReturnStateLoc = E_NOK_CONFIG_PARM_ERROR ;
				}
			break;
			default:
				enuReturnStateLoc = E_NOK_PARAM_OUT_OF_RANGE ; 
			break ;
		}
	}
	else
	{
		enuReturnStateLoc = E_NOK_PARAM_OUT_OF_RANGE ; 
	}
	
	return enuReturnStateLoc ;
	
}


static  void Sev_voidHelp(uint8 u8SevNumCpy , uint8 u8ValueCpy , uint8 u8ModeCpy)
{
	if (u8ModeCpy == SEV_u8COMMON_CATHODE)
	{
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[0],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_A);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[1],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_B);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[2],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_C);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[3],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_D);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[4],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_E);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[5],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_F);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[6],SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_G);
	}
	else  if(u8ModeCpy == SEV_u8COMMON_ANODE)
	{
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[0],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_A);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[1],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_B);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[2],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_C);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[3],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_D);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[4],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_E);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[5],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_F);
		DIO_enuWritePin(SEV_astrPinMapping[u8SevNumCpy].u8SevPins[6],~SEV_astrbfPinValue[u8ValueCpy].u8Sev_pin_G);
	
		
	}
	else
	{
		
	}
	
}



