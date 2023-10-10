/********************************************************************************/
/**    File Name:  ULTRASONIC_h                                                       */
/**                                                                             */
/**  Description: Implementation of the TIM0 contain configuration for the module*/
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
/** SaraH    Sara Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 17/09/2022   0.1      SaraH     Initial Creation                             */

/********************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
void ultrasonic_void_intial(void);
void ultrasonic_f32_setter_distance(void);
float32 ultrasonic_f32_get_distance(void);
uint8 ultrasonic_f32_get_detect_up(void);
void ultrasonic_f32_set_up(void);
void ultrasonic_void_Start(void);
#endif
