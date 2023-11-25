/********************************************************************************/
/**    File Name: UART_CGF.c                                                    */
/**                                                                             */
/**  Description: Implementation of the UART contain CONFG of the module */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana    Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 23/08/2023   0.1       Rana Hossny   Initial Creation                        */
/** 25/08/2023   0.2       Sara Hossny   EDIT AND ADD MORE FUNCTION              */

/********************************************************************************/
#include "UART_CFG.h"
#include"UART_PRIV.h"
#include "STD_Types.h"
UART_CONG_T uart_astruartPinMapping[NUM_UART_USED]={
	
	{UARTNUM0  ,0x08B ,NINE_BITS,NO_PARITY,EVEN_PARITY,NO_BREAK,ONE_STOP_BIT },

	
};
