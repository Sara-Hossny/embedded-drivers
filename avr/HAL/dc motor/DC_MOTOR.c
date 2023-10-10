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


#include DC_MOTOR.h
#include DC_MOTOR_cfg.h
#include DC_MOTOR_priv.h
tenuErrorStatus DC_Motor_OFF(uint8 u8Dc_MotorNumCpy ){
	tenuErrorStatus error =E_OK;
	if(u8Dc_MotorNumCpy<DC_MOTOR_MAX_NUM ){
			switch(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_connection){
				case U8_DC_MOTOR_u8NORMAL :
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[0],DIO_u8LOW );
				break;
				case U8_DC_MOTOR_u8REVERSE  :
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[1],DIO_u8LOW );
				break;
				default:
				error=E_NOK_CONFIG_PARM_ERROR;
				break;
		}	
	}
	else{
	      error =E_NOK_PARAM_OUT_OF_RANGE;	
	}
	
}
tenuErrorStatus DC_Motor_SetDir(uint8 u8Dc_MotorNumCpy , uint8 u8_DirectionCpY){
	tenuErrorStatus error =E_OK;
	if(u8Dc_MotorNumCpy<DC_MOTOR_MAX_NUM ){
		switch(State){
			case U8_DC_MOTOR_u8CLKWISE   :
			switch(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_connection){
				case U8_DC_MOTOR_u8NORMAL :
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[0],DIO_u8HIGH );
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[1],DIO_u8LOW );
				break;
				case U8_DC_MOTOR_u8REVERSE  :
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[0],DIO_u8LOW );
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[1],DIO_u8HIGH );
				break;
				default:
				error=E_NOK_CONFIG_PARM_ERROR;
				break;
			}
			break;
			case U8_DC_MOTOR_u8ANTICLKWISE :
			switch(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_connection){
				case U8_DC_MOTOR_u8NORMAL :
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[0],DIO_u8LOW );
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[1],DIO_u8HIGH );
				break;
				case U8_DC_MOTOR_u8REVERSE  :
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[0],DIO_u8HIGH );
				DIO_enuWritePin(DcMotorMapping[u8Dc_MotorNumCpy].Dc_Motor_Dio_mapping[1],DIO_u8LOW );
				break;
				default:
				error=E_NOK_CONFIG_PARM_ERROR;
				break;
				
			}
			break;
			default:
			error=E_NOK_CONFIG_PARM_ERROR;
			break;
	
		}
		
	}
	else{
	      error =E_NOK_PARAM_OUT_OF_RANGE;	
	}
}


