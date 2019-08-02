/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcu_hw.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/SysCtr_cfg.h"

void SysCtr_init(void)
{

    RCGCGPIO_REG = SYSCTR_RCC_GPIO_PORTA        |
            SYSCTR_RCC_GPIO_PORTB<<1            |
            SYSCTR_RCC_GPIO_PORTC<<2            |
            SYSCTR_RCC_GPIO_PORTD<<3            |
            SYSCTR_RCC_GPIO_PORTE<<4            |
            SYSCTR_RCC_GPIO_PORTF<<5            ;
}


