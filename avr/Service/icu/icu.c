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
#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIM1.h"
#include "icu.h"
#include "icu_cfg.h"
#include "icu_priv.h"
#include "icu_external.h"
void Icu_VoidOverInt(void);

void Icu_VoidInt (void){
	SET_BIT(TCCR1B , 6);/*detect rasing edge */
	SET_BIT(TCCR1B , 7);/*cancal nosie*/
	SET_BIT(TIMSK , 5);/*enable input capture uint interput */
	TIM1_voidSetOvfCallback(Icu_VoidOverInt);/* passing function to overflow interput */
	SET_BIT(TIMSK , 5);/*enable timer overflow interput */
}
void Icu_VoidCaluFreq_Duty(float32* f32_Freq_cpy,float32* f32_Duty_cpy){
	*f32_Freq_cpy=FREQ_AFTER_PRESCALER/F32_T_Loc;
	*f32_Duty_cpy=f32_Ton_Updated_Loc/F32_T_Loc;
}

void __vector_6 (void ) __attribute__((signal ,used));
void __vector_6 (void ){
	if(u8_CTR_Reading_Loc==1){
		f32_FirstReading_Loc=(ICR1H<<8|ICR1L);
		u8_CTR_Reading_Loc=2;
		u32_Ctr_Loc=0;
		CLR_BIT(TCCR1B , 6);
	}
	else if (u8_CTR_Reading_Loc==2){
		f32_Ton_Loc=(ICR1H<<8|ICR1L)+u32_Ctr_Loc*U32_OVERFLOW_COUNT-f32_FirstReading_Loc;
		u8_CTR_Reading_Loc=3;
		u32_Ctr_Loc=0;
		SET_BIT(TCCR1B , 6);
	}
	else if (u8_CTR_Reading_Loc==3){
		f32_Ton_Updated_Loc=f32_Ton_Loc;
	    F32_T_Loc=(ICR1H<<8|ICR1L)+u32_Ctr_Loc*U32_OVERFLOW_COUNT-f32_Ton_Loc;
		f32_FirstReading_Loc=F32_T_Loc;
		u8_CTR_Reading_Loc=2;
		u32_Ctr_Loc=0;
		CLR_BIT(TCCR1B , 6);
	}
	
}
void Icu_VoidOverInt(void){
	u32_Ctr_Loc++;
}

