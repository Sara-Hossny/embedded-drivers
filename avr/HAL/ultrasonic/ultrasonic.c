/********************************************************************************/
/**    File Name:  ULTRASONIC.c                                                        */
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


#include <avr/delay.h>
#include "STD_Types.h"
#include "DIO.h"
#include "TIM0.h"
#include "EXTINT0.h"
#include "ultrasonic.h"
#include "ultrasonic_cfg.h"
#include "LCD.h"

uint8  up=0,start;
uint8  timerCounter;
float32  result=0;
uint32 Start=0;
uint8 start_flag=0;
void ultrasonic_void_callBack(void);
void ultrasonic_void_intial(void){
	EXTINT0_voidSetCallBack(ultrasonic_void_callBack);
}
void ultrasonic_void_Start(void){
	DIO_enuWritePin(ULTRASONI_TRIGGER_PIN , DIO_u8LOW);
		 _delay_us(1);
	 DIO_enuWritePin(ULTRASONI_TRIGGER_PIN  , DIO_u8HIGH);
	 start_flag =1;
	 _delay_us(10);
	 DIO_enuWritePin(ULTRASONI_TRIGGER_PIN , DIO_u8LOW);
	 _delay_us(1);
	EXTINT0_voidSetCallBack(ultrasonic_void_callBack);
}
void ultrasonic_void_callBack(void)
{
        if (start_flag) { //accept interrupts only when sonar was started
                if (up == 0) { // voltage rise, start time measurement
                    start = TIM0_u16GetCntrValue();
                    TIM0_voidSet_TimerCounter();
                	    up = 1;
                        result=0;
                } else {
                        // voltage drop, stop time measurement
                        up = 0;
                        result =((TIM0_u16GetCntrValue()+(TIM0_u32get_TimerCounter())*256-start)/58)*0.1255;
                        start_flag=0;
                }
        }
}
uint8 ultrasonic_f32_get_detect_up(void){
	return up;

}
void ultrasonic_f32_set_up(void){
	 up=0;

}
float32 ultrasonic_f32_get_distance(void){
	return result;
}
void ultrasonic_f32_setter_distance(void){
	 result=-1;
}



