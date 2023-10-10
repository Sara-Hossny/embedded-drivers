/********************************************************************************/
/**    File Name: PUSHBUTTON.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PUSHBUTTON contain configuration for the module*/
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
/** SaraH     Sara Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      SaraH     Initial Creation                             */
 
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "PUSHBUTTON_cfg.h"
#include "PUSHBUTTON_priv.h"

tstrPinMappingCfg PUSHBUTTON_astrPUSHBUTTONPinMapping[PUSHBUTTON_MAX_NUM]={
	
	{DIO_u8PIN_4  , PULLUP_CONNECTION },
	{DIO_u8PIN_5  , PULLUP_CONNECTION },
	{DIO_u8PIN_15 , PULLUP_CONNECTION  },
	{DIO_u8PIN_22 , PULLUP_CONNECTION  },
	{DIO_u8PIN_31 , PULLUP_CONNECTION  }
	
};





