/********************************************************************************/
/**    File Name: EXTINT0.h                                                         */
/**                                                                             */
/**  Description: Implementation of the EXTINT0 contain configuration for the module*/
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
/** 30/08/2022   0.1      SaraH     Initial Creation                             */
 
/********************************************************************************/
#ifndef EXTINT0_H
#define EXTINT0_H
typedef void (*pf)(void) ;

void EXTINT0_voidInit(void);

void EXTINT0_voidEnable(void);

void EXTINT0_voidDisable(void);

void EXTINT0_voidSetCallBack(pf pfCallbackCpy);


#endif

