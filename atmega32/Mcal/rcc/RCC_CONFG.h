/********************************************/
/* Description : RCC 						*/
/* Author      : sara hossny         		*/
/* Date        : 9/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef  RCC_CONFG_H 
#define  RCC_CONFG_H
#include "RCC_PRIV.h"
/* select type of RCC 
options : 1- RCC_HSI 
          2- RCC_HSE
		  3- RCC_PLL */
#define  RCC_SYS  RCC_HSI
/* select the type of HSE if used 
options : 1- HSE_BYPASS
		  2- HSE_NOTBYPASS */
#define RCC_HSE_TYPE HSE_NOTBYPASS
/* select the source of PLL if used 
options : 1- RCC_HSI
		  2- RCC_HSE */
#define   RCC_PLL_SCR  RCC_HSI  
/* PLLM must be between 2 and 63*/
#define   RCC_PLLM	5
/* PLLN must be 192 ≤ PLLN ≤ 432*/
#define RCC_PLLN 	192
/* PLLP must be one of the options 
1- RCC_PLLP_2 
2- RCC_PLLP_4 
3- RCC_PLLP_6 
4- RCC_PLLP_8 */
#define RCC_PLLP  RCC_PLLP_2
/*available bus 1-RCC_AHB1
				2-RCC_AHB2
				3-RCC_APB1
				4-RCC_APB2*/
/*available peripheral for RCC_AHB1
	1-RCC_AHB1ENR_GPIOA
	2-RCC_AHB1ENR_GPIOB
	3-RCC_AHB1ENR_GPIOC
	4-RCC_AHB1ENR_GPIOD
	5-RCC_AHB1ENR_GPIOH
	6-RCC_AHB1ENR_CRC
	7-RCC_AHB1ENR_DMA1
	8-RCC_AHB1ENR_DMA2
	*/
/*available peripheral for RCC_APB1
	1-RCC_APB1ENR_PWR
	2-RCC_APB1ENR_I2C1
	3-RCC_APB1ENR_I2C2
	4-RCC_APB1ENR_I2C3
	5-RCC_APB1ENR_USART2
	6-RCC_APB1ENR_SPI3
	7-RCC_APB1ENR_SPI2
	8-RCC_APB1ENR_WWDG
	9-RCC_APB1ENR_TIM2
	10-RCC_APB1ENR_TIM3
	11-RCC_APB1ENR_TIM4
	12-RCC_APB1ENR_TIM5
	*/
/*available peripheral for RCC_APB2
	1-RCC_APB2ENR_TIM1
	2-RCC_APB2ENR_TIM9
	3-RCC_APB2ENR_TIM10
	4-RCC_APB2ENR_TIM11
	5-RCC_APB2ENR_SPI1
	6-RCC_APB2ENR_SPI4
	7-RCC_APB2ENR_SDIO
	8-RCC_APB2ENR_ADC1
	9-RCC_APB2ENR_USART1
	10-RCC_APB2ENR_USART6
	11-RCC_APB2ENR_SYSCFG

	*/
#endif 
