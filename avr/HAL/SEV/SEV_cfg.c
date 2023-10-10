/********************************************************************************/
/**    File Name: SEV_cfg.c                                                         */
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

#include "SEV_cfg.h"
#include "SEV_priv.h"

tstrSevPinMappingCfg SEV_astrPinMapping [SEV_MAX_NUM]={
	{
	 {DIO_u8PIN_0,DIO_u8PIN_2,
	  DIO_u8PIN_5,DIO_u8PIN_6,
	  DIO_u8PIN_7,DIO_u8PIN_8,
	  DIO_u8PIN_9},
	  DIO_u8PIN_31,
	  SEV_u8COMMON_ANODE
	},
	{
	 {DIO_u8PIN_12,DIO_u8PIN_13,
	  DIO_u8PIN_14,DIO_u8PIN_15,
	  DIO_u8PIN_16,DIO_u8PIN_17,
	  DIO_u8PIN_18},
	  DIO_u8PIN_30,
	  SEV_u8COMMON_CATHODE
	} 
};

