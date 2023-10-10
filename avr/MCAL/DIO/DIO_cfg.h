/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO contain configuration for the module*/
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

/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1       aaboelno     Initial Creation                        */
/** 21/08/2022   0.1       SaraH        ADD toggle function                         */

/********************************************************************************/

#ifndef   DIO_CFG_H
#define   DIO_CFG_H

/** Configuration for Pin out pins        */
/** Values ( DIO_INPUT ,DIO_OUTPUT )      */

/* Group A */
#define DIO_u8DIR_PIN_A0       
#define DIO_u8DIR_PIN_A1        DIO_OUTPUT
#define DIO_u8DIR_PIN_A2        DIO_INPUT
#define DIO_u8DIR_PIN_A3        DIO_OUTPUT
#define DIO_u8DIR_PIN_A4        DIO_OUTPUT
#define DIO_u8DIR_PIN_A5        DIO_OUTPUT
#define DIO_u8DIR_PIN_A6        DIO_OUTPUT
#define DIO_u8DIR_PIN_A7        DIO_OUTPUT
/* Group B */
#define DIO_u8DIR_PIN_B0       
#define DIO_u8DIR_PIN_B1        DIO_OUTPUT
#define DIO_u8DIR_PIN_B2        DIO_INPUT
#define DIO_u8DIR_PIN_B3        DIO_OUTPUT
#define DIO_u8DIR_PIN_B4        DIO_INPUT
#define DIO_u8DIR_PIN_B5        DIO_OUTPUT
#define DIO_u8DIR_PIN_B6        DIO_OUTPUT
#define DIO_u8DIR_PIN_B7        DIO_OUTPUT
/* Group C */
#define DIO_u8DIR_PIN_C0       
#define DIO_u8DIR_PIN_C1        DIO_OUTPUT
#define DIO_u8DIR_PIN_C2        DIO_INPUT
#define DIO_u8DIR_PIN_C3        DIO_OUTPUT
#define DIO_u8DIR_PIN_C4        DIO_INPUT
#define DIO_u8DIR_PIN_C5        DIO_OUTPUT
#define DIO_u8DIR_PIN_C6        DIO_OUTPUT
#define DIO_u8DIR_PIN_C7        DIO_OUTPUT
/* Group D */
#define DIO_u8DIR_PIN_D0       
#define DIO_u8DIR_PIN_D1        DIO_OUTPUT
#define DIO_u8DIR_PIN_D2        DIO_INPUT
#define DIO_u8DIR_PIN_D3        DIO_OUTPUT
#define DIO_u8DIR_PIN_D4        DIO_INPUT
#define DIO_u8DIR_PIN_D5        DIO_OUTPUT
#define DIO_u8DIR_PIN_D6        DIO_OUTPUT
#define DIO_u8DIR_PIN_D7        DIO_OUTPUT

#endif



