#ifndef SPI_H_
#define SPI_H_
void spi_void_intial(void);
void spi_void_read_Syc(uint16 * u8_value_cpy);
uint16 spi_uint8_read_Asyc(void);
void spi_void_write_Syc(uint16 u8_value_cpy);
void spi_void_enable(void);
void spi_void_disable(void );
void spi_void_InterputEmptyEnable(void);
void spi_void_InterputEmptyDisable(void );
void spi_void_InterputReciveDisable(void );
void spi_void_InterputReciveEnable(void);
tenuErrorSpiStatus spi_tenuspi_state(void);
#endif
