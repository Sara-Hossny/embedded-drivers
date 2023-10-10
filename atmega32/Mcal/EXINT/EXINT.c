/********************************************************************************/
/**    File Name: EXINT.c                                                   */
/**                                                                             */
/**  Description: Implementation of the EXINT contain the module */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Sara Hossny .       All rights reserved.              */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Sara    Sara Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 14/08/2023   0.1       Sara Hossny   Initial Creation                        */
/********************************************************************************/
#include"EXINT.h"
#include"EXINT_PRIV.h"
#include"EXINT_CONFG.h"
#include "STD_Types.h"
#include "BIT_Math.h"

static void(*Global_Exitptr[16])(void)={NULL_PTR};


void MEXINT_vInterruptSetEnable(uint8 Copy_u8InterruptLine){
	SET_BIT(EXINT->EXTI_IMR,Copy_u8InterruptLine);

}
void MEXINT_vInterruptClearEnable(uint8 Copy_u8InterruptLine){
	CLR_BIT(EXINT->EXTI_IMR,Copy_u8InterruptLine);
    
    
}
void MEXINTP_vSetSYSCfgEXINT(uint8 copy_u8EXINT_Num ,Port copy_u8Port){
	SYSEXINT->SYSCFG_EXTICR[copy_u8EXINT_Num/4]=copy_u8Port<<(4*(copy_u8EXINT_Num%4));
}
void MEXINTP_VSet_Mode(Mode COPY_Mode, uint8 Copy_u8InterruptLine) {
    switch (COPY_Mode) {
        case MEXINT_RE:
            SET_BIT(EXINT->EXTI_RTSR, Copy_u8InterruptLine);
            CLR_BIT(EXINT->EXTI_FTSR, Copy_u8InterruptLine);
            break;
        case MEXINT_FE:
            SET_BIT(EXINT->EXTI_FTSR, Copy_u8InterruptLine);
            CLR_BIT(EXINT->EXTI_RTSR, Copy_u8InterruptLine);
            break;
        case MEXINT_ONChange:
            SET_BIT(EXINT->EXTI_RTSR, Copy_u8InterruptLine);
            SET_BIT(EXINT->EXTI_FTSR, Copy_u8InterruptLine);
            break;
        default:
            break;
    }
}

void MEXINT0_vCallBack(void (*ptr)(void)){
	Global_Exitptr[0]=ptr;
}
void MEXINT1_vCallBack(void (*ptr)(void)){
	Global_Exitptr[0]=ptr;
	
}
void EXIT0_IRQHandler(void){
	Global_Exitptr[0]();
	EXINT->EXTI_PR=1;
	
}
void EXIT1_IRQHandler(void){
	Global_Exitptr[1]();
	EXINT->EXTI_PR=1;
	
}
