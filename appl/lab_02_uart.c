/*
 * lab_02_uart.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/nvic/nvic.h"
#include "../mcal/global_interrupt.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/uart/uart.h"

static uint8 TestReceivedBuff[100]={0}, TestMsgLength=0;

void lab_02_uart(void)
{

    SysCtr_init();
    PORT_init();
    UART_init(UART1);

    /*enable global Interrupt */
    GI_ENABLE();
    /*enable NVIC UART Interrupt */
    NVIC_init();
    /*enable UART interrupt*/
    UART_enInterrupt(UART1);
    while(1)
    {
        UART_sendMsg(UART1, "Hello...", 5);
        UART_getReceivedMsg(UART1, TestReceivedBuff, &TestMsgLength);

    }
}
