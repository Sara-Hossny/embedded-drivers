#include "STD_Types.h"
#include "BIT_MATH.h"
#include "spi.h"
#include "spi_cfg.h"
#include "spi_priv.h"

uint8 u8_bus_contention ;
uint8 u8_collision_Flag ;
uint16 u16_read_buffer;
void spi_void_intial(void){

	SET_BIT( SPI1->SPI_CR1 , 6) ;
#if SPI_STATE == MASTER
	SPI1->SPI_CR1|=DATA_ORDER;
	SPI1->SPI_CR1|=SPI_STATE;
	SPI1->SPI_CR1|=SPI_CLK_POLARITY;
	SPI1->SPI_CR1|= SCK_FREQUENCY;
#endif


}
void spi_void_read_Syc(uint16 * u16_value_cpy){
	while(GET_BIT(SPI1->SPI_SR , 7)==0);
	*u16_value_cpy=SPI1->SPI_DR;
}
uint16 spi_uint16_read_Asyc(void){
	return u16_read_buffer;
}

void spi_void_write_Syc(uint8 u8_value_cpy){
	SPI1->SPI_DR=u8_value_cpy;
}

void spi_void_enable(void){
	SET_BIT( SPI1->SPI_CR1 , 6) ;	
}
void spi_void_disable(void ){
	CLR_BIT( SPI1->SPI_CR1 , 6) ;
}
void spi_void_InterputEmptyEnable(void){		
	SET_BIT( SPI1->SPI_CR2 , 7) ;
}
void spi_void_InterputEmptyDisable(void ){
	CLR_BIT( SPI1->SPI_CR2 , 7) ;
}
void spi_void_InterputReciveEnable(void){		
	SET_BIT( SPI1->SPI_CR2 , 6) ;
}
void spi_void_InterputReciveDisable(void ){
	CLR_BIT( SPI1->SPI_CR2 , 6) ;
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
