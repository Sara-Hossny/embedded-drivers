/********************************************************************************/
/**    File Name: icu.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PWM contain configuration for the module*/
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
/** saraH     Sara Hossny Hassan          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 6/09/2022   0.1       saraH     Initial Creation                        */
/********************************************************************************/
#ifndef ICU_PRIV_H
#define ICU_PRIV_H
#define U32_OVERFLOW_COUNT   65536
#define TCCR1B *((volatile uint8 *)  0x1  )
#define TIMSK *((volatile uint8 *) 0x2 )
#define ICR1H *((volatile uint8 *) 0x4 )
#define ICR1L *((volatile uint8 *) 0x3)
extern float32 f32_Ton_Loc,f32_FirstReading_Loc,f32_Ton_Updated_Loc ,f32_T_Loc;
extern uint8 u8_CTR_Reading_Loc;
extern uint32 u32_Ctr_Loc;
#endif
