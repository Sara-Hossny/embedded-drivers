/********************************************************************************/
/**    File Name: spi.c                                                        */
/**                                                                             */
/**  Description: Implementation of the spi contain configuration for the module*/
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
#include "BIT_MATH.h"
#include "spi.h"
#include "spi_cfg.h"
#include "spi_priv.h"
uint8 u8_bus_contention ;
uint8 u8_collision_Flag ;
uint8 u8_read_buffer;
void spi_void_intial(void){

	SET_BIT( SPCR , 6) ;
	SET_BIT( SPCR , 0) ;
	SPCR|=DATA_ORDER;
	SPCR|=SPI_STATE;
	SPCR|=SPI_CLK_POLARITY;
#if SPI_STATE == MASTER
	SPCR|= SCK_FREQUENCY;
#if SCK_FREQUENCY==FREQ_DIV_2
	SET_BIT( SPSR , 0) ;
    #elif SCK_FREQUENCY==FREQ_DIV_8
	SET_BIT( SPSR , 0) ;
    #elif SCK_FREQUENCY==FREQ_DIV_32
	SET_BIT( SPSR , 0) ;
   #endif
#endif


}
uint8 SPI_u8DataTransfer_Sync(uint8 u8DataCpy)
{
	SPDR  =  u8DataCpy ;
	while (GET_BIT(SPSR , 7) == 0);
	return SPDR ;
}
void spi_void_read_Syc(uint8 * u8_value_cpy){
	while(!(SPSR &(1<<7)));
	*u8_value_cpy=SPDR;
}
uint8 spi_uint8_read_Asyc(void){
	return u8_read_buffer;
}

void spi_void_write_Syc(uint8 u8_value_cpy){
	SPDR=u8_value_cpy;
}

void spi_void_enable(void){
	SET_BIT( SPCR , 6) ;	
}
void spi_void_disable(void ){
	CLR_BIT( SPCR , 6) ;
}
void spi_void_InterputEnable(void){		
	SET_BIT( SPCR , 7) ;
}
void spi_void_InterputDisable(void ){
	CLR_BIT( SPCR , 7) ;
}
tenuErrorSpiStatus spi_tenuspi_state(void){
	tenuErrorSpiStatus state=E_OK_WRITE_DONE;
	if(u8_bus_contention==1){
		state=E_NOK_BUS_CONTENTION;
		u8_bus_contention=0;
	}
	else if(u8_collision_Flag ==1) {
		state=E_NOK_COLLISION;
		u8_collision_Flag=0;
	}
	else {

	}
}

void __vector_12 (void ) __attribute__((signal,used));
void __vector_12 (void ){

	if((GET_BIT(SPCR , 4)==0)&&(SPI_STATE==MASTER)){
		u8_bus_contention=1;
	}
	else if((GET_BIT(SPSR , 6)==1)){
		u8_collision_Flag =1;
	}
	else{
		u8_read_buffer=SPDR;
	}
	CLR_BIT( SPCR , 7) ;
}
