/*
 * uart.h
 *
 *  Created on: May 21, 2019
 *      Author: Yasmin
 */

#ifndef SRC_DEVICE_DRIVER_UART_UART_H_
#define SRC_DEVICE_DRIVER_UART_UART_H_

#include "../../utils/STD_Types.h"
#include "uart_types.h"
void UART_init(UART_ModNumType UartNo);
void UART_enInterrupt(UART_ModNumType UartNo);
void UART_diInterrupt(UART_ModNumType UartNo);
void UART_startSending(UART_ModNumType UartNo);
#endif /* SRC_DEVICE_DRIVER_UART_UART_H_ */

