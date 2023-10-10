/********************************************************************************/
/**    File Name: EXINT.h                                                   */
/**                                                                             */
/**  Description: Implementation of the EXINT contain header of function the module */
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



#ifndef   EXINT_H
#define   EXINT_H
#include "../../Lib/STD_Types.h"
typedef enum{
    MEXINT_RE,
    MEXINT_FE,
    MEXINT_ONChange
}Mode;
typedef enum{
    PortA,
    PortB,
    PortC,
	PortD,
	PortE,
	PortH=7
}Port;
void MEXINT_vInterruptSetEnable(uint8 Copy_u8InterruptLine);
void MEXINT_vInterruptClearEnable(uint8 Copy_u8InterruptLine);
void MEXINTP_vSetSYSCfgEXINT(uint8 copy_u8EXINT_Num ,Port copy_u8Port);
void MEXINT0_vCallBack(void (*ptr)(void));
void MEXINT1_vCallBack(void (*ptr)(void));
void EXIT0_IRQHandler(void);
void EXIT1_IRQHandler(void);
#endif
