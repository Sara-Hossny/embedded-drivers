/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO contain interfaces for the module   */
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
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/** SaraH     Sara Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1       aaboelno     Initial Creation                        */
/** 21/08/2022   0.1       SaraH        ADD toggle function                         */

/********************************************************************************/

#ifndef   DIO_H
#define   DIO_H

typedef struct {
	
	uint8 u8PinNum   ;
	uint8 u8PinValue ;
	tenuErrorStatus enuStatus;
	
}tstrPinMapping ;


#define DIO_u8OUTPUT           ((uint8)0x01)     
#define DIO_u8INPUT            ((uint8)0x00)

/*-------------------------------------------------*/
#define DIO_u8HIGH              ((uint8)0x01)     
#define DIO_u8LOW               ((uint8)0x00)
/*-------------------------------------------------*/
#define DIO_u8ACTIVATE       ((uint8)0x01)     
#define DIO_u8DEACTIVATE     ((uint8)0x00)

/*-------------------------------------------------*/
#define DIO_u8PIN_A0     ((uint8 )40)
#define DIO_u8PIN_A1     ((uint8 )39)
#define DIO_u8PIN_A2     ((uint8 )38)
#define DIO_u8PIN_A3     ((uint8 )37)
#define DIO_u8PIN_A4     ((uint8 )36)
#define DIO_u8PIN_A5     ((uint8 )35)
#define DIO_u8PIN_A6     ((uint8 )34)
#define DIO_u8PIN_A7     ((uint8 )33)

/*-------------------------------------------------*/
#define DIO_u8PIN_B0     ((uint8 ) 1)
#define DIO_u8PIN_B1     ((uint8 ) 2)
#define DIO_u8PIN_B2    ((uint8 )  3)
#define DIO_u8PIN_B3    ((uint8 )  4)
#define DIO_u8PIN_B4    ((uint8 )  5)
#define DIO_u8PIN_B5    ((uint8 )  6)
#define DIO_u8PIN_B6    ((uint8 )  7)
#define DIO_u8PIN_B7    ((uint8 )  8)
						
/*-------------------------------------------------*/
#define DIO_u8PIN_C0     ((uint8 ) 22)
#define DIO_u8PIN_C1     ((uint8 ) 23)
#define DIO_u8PIN_C2     ((uint8 ) 24)
#define DIO_u8PIN_C3     ((uint8 ) 25)
#define DIO_u8PIN_C4     ((uint8 ) 26)
#define DIO_u8PIN_C5     ((uint8 ) 27)
#define DIO_u8PIN_C6     ((uint8 ) 28)
#define DIO_u8PIN_C7     ((uint8 ) 29)

/*-------------------------------------------------*/
#define DIO_u8PIN_D0     ((uint8 ) 14)  
#define DIO_u8PIN_D1     ((uint8 ) 15)  
#define DIO_u8PIN_D2     ((uint8 ) 16)  
#define DIO_u8PIN_D3     ((uint8 ) 17)  
#define DIO_u8PIN_D4     ((uint8 ) 18)  
#define DIO_u8PIN_D5     ((uint8 ) 19)  
#define DIO_u8PIN_D6     ((uint8 ) 20)  
#define DIO_u8PIN_D7     ((uint8 ) 21)  

/*-------------------------------------------------*/

/********************************************************************************/
/** Description : Scan cfg file and Apply on pins registers the configurations  */
/********************************************************************************/

void DIO_voidInit(void);

/* Description : function write DIO_u8HIGH or DIO_u8LOW on Pin start 0 to 31 */
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCpy);


tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy , uint8 * pu8PinValueCpy);

tenuErrorStatus DIO_enuPullWrite(uint8 u8PinNumCpy , uint8 u8PinStateCpy);

tenuErrorStatus DIO_enuWriteBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy );

tenuErrorStatus DIO_enuReadBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy );

tenuErrorStatus DIO_enuWritePinDir(uint8 u8PinNumCpy , uint8 u8PinDirCpy);

tenuErrorStatus DIO_enuTogglePin(uint8 u8PinNumCpy);

#endif

