#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define LSB_FIRST        0x80
#define MSB_FIRST        0x00
#define MASTER           0x04
#define SLAVE            0x00
#define LEADING_RISING   0x02
#define LEADING_FAILING  0x00
#define FIRST_CLK   0x01
#define SEC_CLK    0x00
#define FREQ_DIV_2       0x00
#define FREQ_DIV_4       0x08
#define FREQ_DIV_8       0x10
#define FREQ_DIV_16      0x18
#define FREQ_DIV_32      0x20
#define FREQ_DIV_64      0x28
#define FREQ_DIV_128     0x30
#define FREQ_DIV_256     0x38
typedef struct SPI_PRIV
{   uint32 SPI_CR1;
    uint32 SPI_CR2;
    uint32 SPI_SR;
    uint32 SPI_DR;


}SPI_t;
#define SPI1_BASE_ADDRESS (0x4001 3000)
#define SPI1 (( volatile SPI_t *) SPI1_BASE_ADDRESS)
#define SPI2_BASE_ADDRESS (0x4000 3800)
#define SPI2 (( volatile SPI_t *) SPI2_BASE_ADDRESS)
#define SPI3_BASE_ADDRESS (0x4000 3C00)
#define SPI3 (( volatile SPI_t *) SPI3_BASE_ADDRESS)
#define SPI4_BASE_ADDRESS (0x4001 3400)
#define SPI4 (( volatile SPI_t *) SPI4_BASE_ADDRESS)

#endif
