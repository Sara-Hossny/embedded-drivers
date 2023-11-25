/********************************************************************************/
/**    File Name: EXINT_PRIV.h                                                   */
/**                                                                             */
/**  Description: Implementation of the EXINT contain Private file for the module */
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



#ifndef   EXINT_PRIV_H
#define   EXINT_PRIV_H
#include "../../Lib/STD_Types.h"

typedef struct EXINT_PRIV
{   uint32 EXTI_IMR;
    uint32 EXTI_EMR;
    uint32 EXTI_RTSR;
    uint32 EXTI_FTSR;
    uint32 EXTI_SWIER;
    uint32 EXTI_PR;
}EXINT_t;

typedef struct SYS_PRIV
{   uint32 SYSCFG_MEMRMP;
    uint32 SYSCFG_PMC;
    uint32 SYSCFG_EXTICR[4];
	uint32 SYSCFG_CMPCR;
	
}SYS_EXINT_t;
#define MEXINT_BASE_ADDRESS (0x40013C00)
#define MSYSEXINT_BASE_ADDRESS (0x40013800)
#define EXINT (( volatile EXINT_t *) MEXINT_BASE_ADDRESS)
#define SYSEXINT (( volatile SYS_EXINT_t *) MEXINT_BASE_ADDRESS)



#endif
