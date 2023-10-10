/********************************************************************************/
/**    File Name: DC_MOTOR.h                                                    */
/**                                                                             */
/**  Description: Implementation of the DC_MOTOR contain configuration for the module*/
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
/** SaraH     Sara Hossny Hassan          ITI.                                  */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 31/08/2022   0.1       SaraH     Initial Creation                           */
/********************************************************************************/
#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include   STD_TYPES_H
#include   DIO.h
#define U8_DC_MOTOR_OFF           ((uint8) 0x01)
#define U8_DC_MOTOR_u8CLKWISE     ((uint8) 0xAA)
#define U8_DC_MOTOR_u8ANTICLKWISE ((uint8) 0x55)
#define U8_DC_MOTOR_u8NORMAL      ((uint8) 0xAA)
#define U8_DC_MOTOR_u8REVERSE     ((uint8) 0x55)
tenuErrorStatus DC_Motor_OFF(uint8 u8Dc_MotorNumCpy );
tenuErrorStatus DC_Motor_SetDir(uint8 u8Dc_MotorNumCpy , uint8 u8_DirectionCpY);

#endif























