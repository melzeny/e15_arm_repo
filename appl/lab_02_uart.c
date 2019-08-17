/*
 * lab_02_uart.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/uart/uart.h"


void lab_02_uart(void)
{
    SysCtr_init();
    PORT_init();
    UART_init(UART1);

    /*enable global Interrupt */

    /*enable NVIC UART Interrupt */

    /*enable UART interrupt*/

    while(1)
    {
        UART_sendMsg(UART1, "Hello...", 5);
    }
}
