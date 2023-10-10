/********************************************/
/* Description : RCC */
/* Author      : sara hossny        		*/
/* Date        : 9/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef  RCC_PRIV_H 
#define  RCC_PRIV_H
#include "STD_Types.h"
typedef struct {
  volatile uint32  RCC_CR;
  volatile uint32  RCC_PLLCFGR;
  volatile uint32  RCC_CFGR;
  volatile uint32  RCC_CIR;
  volatile uint32  RCC_AHB1RSTR;
  volatile uint32  RCC_AHB2RSTR;
  volatile uint32  Reserved_1;
  volatile uint32  Reserved_2;
  volatile uint32  RCC_APB1RSTR;
  volatile uint32  RCC_APB2RSTR;
  volatile uint32  Reserved_3;
  volatile uint32  Reserved_4;
  volatile uint32  RCC_AHB1ENR;
  volatile uint32  RCC_AHB2ENR;
  volatile uint32  Reserved_5;
  volatile uint32  Reserved_6;
  volatile uint32  RCC_APB1ENR;
  volatile uint32  RCC_APB2ENR;
  volatile uint32  Reserved_7;
  volatile uint32  Reserved_8;
  volatile uint32  RCC_AHB1LPENR;
  volatile uint32  RCC_AHB2LPENR;
  volatile uint32  Reserved_9;
  volatile uint32  Reserved_10;
  volatile uint32  RCC_APB1LPENR;
  volatile uint32  RCC_APB2LPENR;
  volatile uint32  Reserved_11;
  volatile uint32  Reserved_12;
  volatile uint32  RCC_BDCR;
  volatile uint32  RCC_CSR;
  volatile uint32  Reserved_13;
  volatile uint32  Reserved_14;
  volatile uint32  RCC_SSCGR;
  volatile uint32  RCC_PLLI2SCFGR;
  volatile uint32  Reserved_15;
  volatile uint32  RCC_DCKCFGR;
	
}RCC_T ;
#define RCC_BASE 0x40023800
#define RCC ((RCC_T *) RCC_BASE)
#define RCC_HSI   0
#define RCC_HSE   16
#define RCC_PLL   24
#define HSE_BYPASS  1
#define HSE_NOTBYPASS 0
/*types of system buses*/ 
#define RCC_AHB1	0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2	3
/* peripheral for RCC_AHB1*/
#define RCC_AHB1ENR_GPIOA	0
#define	RCC_AHB1ENR_GPIOB	1
#define	RCC_AHB1ENR_GPIOC	2
#define RCC_AHB1ENR_GPIOD	3
#define	RCC_AHB1ENR_GPIOE	4
#define	RCC_AHB1ENR_GPIOH	7
#define RCC_AHB1ENR_CRC		12
#define RCC_AHB1ENR_DMA1	21
#define RCC_AHB1ENR_DMA2	22
/* peripheral for RCC_AHB2*/
#define RCC_AHB1ENR_OTGFSEN	 7
/* peripheral for RCC_APB1*/
#define RCC_APB1ENR_PWR  28
#define RCC_APB1ENR_I2C3 23
#define RCC_APB1ENR_I2C2 22 
#define RCC_APB1ENR_I2C1 21
#define RCC_APB1ENR_USART2 17
#define RCC_APB1ENR_SPI3 15
#define RCC_APB1ENR_SPI2 14
#define RCC_APB1ENR_WWDG 11
#define RCC_APB1ENR_TIM5 3
#define RCC_APB1ENR_TIM4 2 
#define RCC_APB1ENR_TIM3 1
#define RCC_APB1ENR_TIM2 0
/* peripheral for RCC_APB2*/
#define RCC_APB2ENR_TIM11 18
#define RCC_APB2ENR_TIM10 17
#define RCC_APB2ENR_TIM9 16
#define RCC_APB2ENR_SYSCFG 14
#define RCC_APB2ENR_SPI4 13
#define RCC_APB2ENR_SPI1 12
#define RCC_APB2ENR_SDIO 11
#define RCC_APB2ENR_ADC1 8
#define RCC_APB2ENR_USART6  5
#define RCC_APB2ENR_USART1 4
#define RCC_APB2ENR_TIM1 0
/*PLLP values*/
#define	RCC_PLLP_2  0x0000
#define RCC_PLLP_4  0x1000
#define RCC_PLLP_6	0x2000	
#define RCC_PLLP_8	0x3000

#endif 
