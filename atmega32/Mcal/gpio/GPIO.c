/********************************************/
/* Description : GPIO 						*/
/* Author      : sara hossny         		*/
/* Date        : 10/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "GPIO_PRIV.h"
#include "GPIO_CONFG.h"
#include "GPIO.h"

tenuErrorStatus MGPIO_vSetPinMode(uint8 u8_PortId, uint8 u8_PinNo , enum_GPIO_Mode enum_gpio_PinMode){
	switch(u8_PortId){
	case GPIO_PORTA :
		GPIOA->GPIO_MODER&=~(0b11 <<(u8_PinNo*2));
		GPIOA->GPIO_MODER|=(enum_gpio_PinMode <<(u8_PinNo*2));
		return E_OK;

	case GPIO_PORTB:
		GPIOB->GPIO_MODER&=~(0b11 <<(u8_PinNo*2));
		GPIOB->GPIO_MODER|=(enum_gpio_PinMode <<(u8_PinNo*2));
		return E_OK ;

	case GPIO_PORTC :
		GPIOC->GPIO_MODER&=~(0b11 <<(u8_PinNo*2));
		GPIOC->GPIO_MODER|=(enum_gpio_PinMode <<(u8_PinNo*2));
		return E_OK;

	default :
	return E_NOK_CONFIG_PARM_ERROR;

	}
}
tenuErrorStatus MGPIO_vSetPinOutputType(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PinOutputType){
		if((u8_PinOutputType==GPIO_OPENDRAIN)||(u8_PinOutputType==GPIO_PUSHPULL)){
		switch(u8_PortId){
		case GPIO_PORTA :
			GPIOA->GPIO_OTYPER&=~(0b1 <<(u8_PinNo));
			GPIOA->GPIO_OTYPER|=(u8_PinOutputType <<(u8_PinNo));
			return E_OK;

		case GPIO_PORTB:
			GPIOB->GPIO_OTYPER&=~(0b1 <<(u8_PinNo));
			GPIOB->GPIO_OTYPER|=(u8_PinOutputType <<(u8_PinNo));

			return E_OK ;

		case GPIO_PORTC :
			GPIOC->GPIO_OTYPER&=~(0b1 <<(u8_PinNo));
			GPIOC->GPIO_OTYPER|=(u8_PinOutputType <<(u8_PinNo));
			return E_OK;

		default :
		return E_NOK_CONFIG_PARM_ERROR;
	}}
		else {
			return E_NOK_CONFIG_PARM_ERROR;
		}
}

	tenuErrorStatus MGPIO_vSetPinOutputSpeed(uint8 u8_PortId, uint8 u8_PinNo , enum_GPIO_SPEED enum_GPIO_PinSpeed){
		switch(u8_PortId){
			case GPIO_PORTA :
				GPIOA->GPIO_OSPEEDR&=~(0b11 <<(u8_PinNo*2));
				GPIOA->GPIO_OSPEEDR|=(enum_GPIO_PinSpeed <<(u8_PinNo*2));
				return E_OK;

			case GPIO_PORTB:
				GPIOB->GPIO_OSPEEDR&=~(0b11 <<(u8_PinNo*2));
				GPIOB->GPIO_OSPEEDR|=(enum_GPIO_PinSpeed <<(u8_PinNo*2));
				return E_OK ;

			case GPIO_PORTC :
				GPIOC->GPIO_OSPEEDR&=~(0b11 <<(u8_PinNo*2));
				GPIOC->GPIO_OSPEEDR|=(enum_GPIO_PinSpeed <<(u8_PinNo*2));
				return E_OK;

			default :
			return E_NOK_CONFIG_PARM_ERROR;

			}
	}

tenuErrorStatus MGPIO_vSetPinInputPull(uint8 u8_PortId, uint8 u8_PinNo , uint8 u8_PullType){
	if((u8_PullType>=0)&&(u8_PullType<4)){
			switch(u8_PortId){
			case GPIO_PORTA :
				GPIOA->GPIO_PUPDR&=~(0b11 <<(u8_PinNo *2 ));
				GPIOA->GPIO_PUPDR|=(u8_PullType <<(u8_PinNo *2));
				return E_OK;

			case GPIO_PORTB:
				GPIOB->GPIO_PUPDR&=~(0b11 <<(u8_PinNo *2));
				GPIOB->GPIO_PUPDR|=(u8_PullType <<(u8_PinNo *2));

				return E_OK ;

			case GPIO_PORTC :
				GPIOC->GPIO_PUPDR&=~(0b11 <<(u8_PinNo *2));
				GPIOC->GPIO_PUPDR|=(u8_PullType <<(u8_PinNo *2));
				return E_OK;

			default :
			return E_NOK_CONFIG_PARM_ERROR;
		}}
			else {
				return E_NOK_CONFIG_PARM_ERROR;
			}
}
tenuErrorStatus MGPIO_u8GetPinVal(uint8 u8_PortId,uint8 u8_PinNo ,uint8* u8_Pinvalue ){
	switch(u8_PortId){
	case GPIO_PORTA :
		*u8_Pinvalue=(GPIOA->GPIO_IDR&(1 << u8_PinNo));
		return E_OK;

	case GPIO_PORTB:
		*u8_Pinvalue=(GPIOB->GPIO_IDR&(1 << u8_PinNo));
		return E_OK ;

	case GPIO_PORTC :
		*u8_Pinvalue=(GPIOC->GPIO_IDR&(1 << u8_PinNo));
		return E_OK;

	default :
	return E_NOK_CONFIG_PARM_ERROR;

	}
}
tenuErrorStatus MGPIO_u8SetPinVal(uint8 u8_PortId,uint8 u8_PinNo, uint8 u8_Pin_Value ){
	switch(u8_PortId){
	case GPIO_PORTA :
		GPIOA->GPIO_ODR&=~(0b1 <<(u8_PinNo));
		GPIOA->GPIO_ODR|=(u8_Pin_Value <<(u8_PinNo));
		return E_OK;

	case GPIO_PORTB:
		GPIOB->GPIO_ODR&=~(0b1 <<(u8_PinNo));
		GPIOB->GPIO_ODR|=(u8_Pin_Value <<(u8_PinNo));
		return E_OK ;

	case GPIO_PORTC :
		GPIOC->GPIO_ODR&=~(0b1 <<(u8_PinNo));
		GPIOC->GPIO_ODR|=(u8_Pin_Value <<(u8_PinNo));
		return E_OK;

	default :
	return E_NOK_CONFIG_PARM_ERROR;

	}
}
tenuErrorStatus MGPIO_u8ToglePinVal(uint8 u8_PortId,uint8 u8_PinNo ){
	switch(u8_PortId){
	case GPIO_PORTA :
		GPIOA->GPIO_ODR^=(0b1 <<(u8_PinNo));

		return E_OK;

	case GPIO_PORTB:
		GPIOB->GPIO_ODR^=(0b1 <<(u8_PinNo));

		return E_OK ;

	case GPIO_PORTC :
		GPIOC->GPIO_ODR^=(0b1 <<(u8_PinNo));

		return E_OK;

	default :
	return E_NOK_CONFIG_PARM_ERROR;

	}
}
tenuErrorStatus MGPIO_vSetAlternativeFunction(uint8 u8_PortId,uint8 u8_PinNo,enum_Alter_func u8_Alternative_Function){
	if(u8_PinNo>=0 && u8_PinNo <32){
	switch(u8_PortId){
	case GPIO_PORTA :
		if(u8_PinNo <16){
			GPIOA->GPIO_AFRL&=~(0b1111 <<(u8_PinNo *4));
			GPIOA->GPIO_AFRL|=(u8_Alternative_Function <<(u8_PinNo *4));}
		else{
			GPIOA->GPIO_AFRH&=~(0b1111 <<((u8_PinNo-15) *4));
			GPIOA->GPIO_AFRH|=(u8_Alternative_Function <<((u8_PinNo-15) *4));
		}
		return E_OK;

	case GPIO_PORTB:
		if(u8_PinNo <16){
			GPIOB->GPIO_AFRL&=~(0b1111 <<(u8_PinNo *4));
			GPIOB->GPIO_AFRL|=(u8_Alternative_Function <<(u8_PinNo *4));}
		else{
			GPIOB->GPIO_AFRH&=~(0b1111 <<((u8_PinNo-15) *4));
			GPIOB->GPIO_AFRH|=(u8_Alternative_Function <<((u8_PinNo-15) *4));
			}
		return E_OK ;

	case GPIO_PORTC :
		if(u8_PinNo <16){
			GPIOC->GPIO_AFRL&=~(0b1111 <<(u8_PinNo *4));
			GPIOC->GPIO_AFRL|=(u8_Alternative_Function <<(u8_PinNo *4));}
		else{
			GPIOC->GPIO_AFRH&=~(0b1111 <<((u8_PinNo-15) *4));
			GPIOC->GPIO_AFRH|=(u8_Alternative_Function <<((u8_PinNo-15) *4));}
		return E_OK;

	 default:
	return E_NOK_CONFIG_PARM_ERROR;
	}
	}

	else{
		return E_NOK_CONFIG_PARM_ERROR;
	}
}
tenuErrorStatus MGPIO_u8SetPinValFast(uint8 u8_PortId,uint8 u8_PinNo, uint8 u8_Pin_Value ){
    if(u8_Pin_Value==GPIO_HIGH){
        switch(u8_PortId){
            case GPIO_PORTA :
                GPIOA->GPIO_BSRR |= 1<<u8_PinNo  ;
                return E_OK;
            case GPIO_PORTB:
                GPIOB->GPIO_BSRR |= 1<<u8_PinNo  ;
                return E_OK;
            case GPIO_PORTC:
                GPIOC->GPIO_BSRR |= 1<<u8_PinNo  ;
                return E_OK;
            default :
            	return E_NOK_CONFIG_PARM_ERROR;
        }

    }
    else if(u8_Pin_Value==GPIO_LOW){
        switch(u8_PortId){
            case GPIO_PORTA :
                GPIOA->GPIO_BSRR |= 1<<(u8_PinNo+16)  ;
                return E_OK;

            case GPIO_PORTB:
                 GPIOB->GPIO_BSRR |= 1<<(u8_PinNo+16)  ;
                 return E_OK;

            case GPIO_PORTC:
                 GPIOC->GPIO_BSRR |= 1<<(u8_PinNo+16)  ;
                 return E_OK;
            default :
                 return E_NOK_CONFIG_PARM_ERROR;

        }

    }
    return E_NOK_CONFIG_PARM_ERROR;

}


