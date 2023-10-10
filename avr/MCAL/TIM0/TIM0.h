/********************************************************************************/
/**    File Name: TIMER0.h                                                         */
/**                                                                             */
/**  Description: Implementation of the TIMER0 contain configuration for the module*/
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
/** 1/9/2022   0.1      SaraH     Initial Creation                             */
 
/********************************************************************************/
#ifndef TIM0_H
#define TIM0_H

void TIM0_voidInit(void);
void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM0_voidEnableOVFIntterrupt(void);
void TIM0_voidDisableOVFIntterrupt(void);
void TIM0_voidEnableCTCIntterrupt(void);
void TIM0_voidDisableCTCIntterrupt(void);
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM0_voidSetCtcCallback(pf pfCtcCallbackCpy);
void TIM0_voidDelayMsInit(void);
void TIM0_voidDelayMs(uint32 u32DalayTimeCpy);
void TIM0_voidDelayUsInit(void);
void TIM0_voidDelayUs(uint32 u32DalayTimeCpy);

#endif