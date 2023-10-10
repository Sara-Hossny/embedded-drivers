/********************************************/
/* Description : GPIO */
/* Author      : sara hossny        		*/
/* Date        : 10/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef   GPIO_PRIV_H
#define   GPIO_PRIV_H
#include "../../LIB/STD_Types.h"

typedef struct
{
    uint32 GPIO_MODER;
    uint32 GPIO_OTYPER;
    uint32 GPIO_OSPEEDR;
    uint32 GPIO_PUPDR;
    uint32 GPIO_IDR;
    uint32 GPIO_ODR;
    uint32 GPIO_BSRR;
    uint32 GPIO_LCKR;
    uint32 GPIO_AFRL;
    uint32 GPIO_AFRH;

}gpio_t;




#define GPIOA_Base_Address  0x40020000
#define GPIOB_Base_Address  0x40020400
#define GPIOC_Base_Address  0x40020000

#define GPIOA ((volatile gpio_t *) GPIOA_Base_Address)
#define GPIOB ((volatile gpio_t *) GPIOB_Base_Address)
#define GPIOC ((volatile gpio_t *) GPIOC_Base_Address)




#define   GPIO_PORTA    0
#define   GPIO_PORTB    1
#define   GPIO_PORTC    2

#define GPIO_OPENDRAIN 1
#define GPIO_PUSHPULL  0



#define GPIO_NO_PULL 0x00
#define GPIO_PULL_UP 0x01
#define GPIO_PULL_DOWN 0x10

#define GPIO_HIGH 1
#define GPIO_LOW 0


#endif
