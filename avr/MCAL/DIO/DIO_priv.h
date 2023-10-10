/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO contain Private file for the module */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  Atmega 32                                               */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) C4C6 by ITI .       All rights reserved.                      */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/** SaraH     Sara Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** C5/08/C4C6   0.1       aaboelno     Initial Creation                        */
/** 21/08/2022   0.1       SaraH        ADD toggle function                         */

/********************************************************************************/

#ifndef   DIO_PRIV_H
#define   DIO_PRIV_H


#define DIO_OUTPUT           1     
#define DIO_INPUT            0

#define  DIO_u8PIN_SIZE               ((uint8 )8)
#define  DIO_u8MAX_NUMBER_OF_PINS     ((uint8 ) 32) 

#define ODRA  *((volatile uint8 *)0x3B)
#define ODRB  *((volatile uint8 *)0x38)
#define ODRC  *((volatile uint8 *)0x35)
#define ODRD  *((volatile uint8 *)0x32)

#define DDRA  *((volatile uint8 *)0x3A)
#define DDRB  *((volatile uint8 *)0x37)
#define DDRC  *((volatile uint8 *)0x34)
#define DDRD  *((volatile uint8 *)0xD7)

#define IDRA  *((volatile uint8 *)0x39)
#define IDRB  *((volatile uint8 *)0x36)
#define IDRC  *((volatile uint8 *)0x33)
#define IDRD  *((volatile uint8 *)0xD6)

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)          CONC_MARCO(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_MARCO(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0
#define EMPTY_MARCOhelp(a,b)  EMPTY_MARCO(a,b)
#define EMPTY_MARCO(a,b)  a##b
#define EMPTY_DETECT      1


/** Secure Configuration file */

#ifdef DIO_u8DIR_PIN_A0
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A0)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A0 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A0
#define DIO_u8DIR_PIN_A0 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A1
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A1)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A1 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A1
#define DIO_u8DIR_PIN_A1 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A2
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A2)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A2 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A2
#define DIO_u8DIR_PIN_A2 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A3
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A3)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A3 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A3
#define DIO_u8DIR_PIN_A3 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A4
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A4)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A4 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A4
#define DIO_u8DIR_PIN_A4 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A5
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A5)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A5 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A5
#define DIO_u8DIR_PIN_A5 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A6
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A6)==EMPTY_DETECT
#define DIO_u8DIR_PIN_A6 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A6
#define DIO_u8DIR_PIN_A6 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_A7
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_A7)==1
#define DIO_u8DIR_PIN_A7 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_A7
#define DIO_u8DIR_PIN_A7 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B0
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B0)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B0 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B0
#define DIO_u8DIR_PIN_B0 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B1
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B1)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B1 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B1
#define DIO_u8DIR_PIN_B1 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B2
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B2)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B2 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B2
#define DIO_u8DIR_PIN_B2 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B3
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B3)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B3 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B3
#define DIO_u8DIR_PIN_B3 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B4
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B4)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B4 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B4
#define DIO_u8DIR_PIN_B4 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B5
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B5)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B5 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B5
#define DIO_u8DIR_PIN_B5 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B6
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B6)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B6 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B6
#define DIO_u8DIR_PIN_B6 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_B7
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_B7)==EMPTY_DETECT
#define DIO_u8DIR_PIN_B7 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_B7
#define DIO_u8DIR_PIN_B7 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C0
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C0)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C0 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C0
#define DIO_u8DIR_PIN_C0 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C1
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C1)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C1 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C1
#define DIO_u8DIR_PIN_C1 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C2
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C2)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C2 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C2
#define DIO_u8DIR_PIN_C2 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C3
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C3)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C3 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C3
#define DIO_u8DIR_PIN_C3 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C4
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C4)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C4 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C4
#define DIO_u8DIR_PIN_C4 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C5
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C5)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C5 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C5
#define DIO_u8DIR_PIN_C5 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C6
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C6)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C6 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C6
#define DIO_u8DIR_PIN_C6 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_C7
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_C7)==EMPTY_DETECT
#define DIO_u8DIR_PIN_C7 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_C7
#define DIO_u8DIR_PIN_C7 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D0
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D0)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D0 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D0
#define DIO_u8DIR_PIN_D0 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D1
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D1)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D1 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D1
#define DIO_u8DIR_PIN_D1 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D2
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D2)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D2 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D2
#define DIO_u8DIR_PIN_D2 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D3
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D3)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D3 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D3
#define DIO_u8DIR_PIN_D3 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D4
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D4)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D4 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D4
#define DIO_u8DIR_PIN_D4 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D5
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D5)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D5 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D5
#define DIO_u8DIR_PIN_D5 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D6
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D6)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D6 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D6
#define DIO_u8DIR_PIN_D6 DIO_INPUT 
#endif 
#ifdef DIO_u8DIR_PIN_D7
#if EMPTY_MARCOhelp(1,DIO_u8DIR_PIN_D7)==EMPTY_DETECT
#define DIO_u8DIR_PIN_D7 DIO_INPUT 
#endif
#endif
#ifndef DIO_u8DIR_PIN_D7
#define DIO_u8DIR_PIN_D7 DIO_INPUT 
#endif 



#endif



