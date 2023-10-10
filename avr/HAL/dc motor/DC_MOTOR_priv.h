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
#ifndef U8_DC_MOTOR_PRIV_H
#define U8_DC_MOTOR_PRIV_H
#define U8_DC_MOTOR_PINS_MAX_NUM  ((uint8) 0x2)

typedef stuct {
	uint8 Dc_Motor_Dio_mapping[DC_MOTOR_PINS_MAX_NUM];
	uint8 Dc_Motor_connection;
	
}tstDcMotorMapping;
extern tstDcMotorMapping DcMotorMapping[DC_MOTOR_MAX_NUM ];

#endif