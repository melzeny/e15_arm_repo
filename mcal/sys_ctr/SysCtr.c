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
    RCGCGPIO_REG.R0  = SYSCTR_RCC_GPIO_PORTA;
    RCGCGPIO_REG.R1  = SYSCTR_RCC_GPIO_PORTB;
    RCGCGPIO_REG.R2  = SYSCTR_RCC_GPIO_PORTC;
    RCGCGPIO_REG.R3  = SYSCTR_RCC_GPIO_PORTD;
    RCGCGPIO_REG.R4  = SYSCTR_RCC_GPIO_PORTE;
    RCGCGPIO_REG.R5  = SYSCTR_RCC_GPIO_PORTF;

}


