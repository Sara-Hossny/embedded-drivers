/********************************************************************************/
/**    File Name: EXTINT0_PRIV.h                                                         */
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

#ifndef EXTINT0_PRIV_H
#define EXTINT0_PRIV_H

#define LOW_LEVEL        0
#define IOC              5
#define FALLING_EDGE     10
#define RISING_EDGE      15


#define GIFR        *((volatile uint8 * )0x5A)
#define GICR        *((volatile uint8 * )0x5B)
#define MCUCR       *((volatile uint8 * )0x55)


#endif 






