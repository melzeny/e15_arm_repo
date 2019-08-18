/*
 * uart.c
 *
 *  Created on: May 21, 2019
 *      Author: Muhammad.Elzeiny
 */
/*========================================================
     INCLUDES
 *========================================================*/
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../mcu_hw.h"
#include "../../config/uart_cfg.h"
#include "uart_types.h"
#include "uart.h"


/*========================================================
     DEFINES
 *========================================================*/
#define UART_PARITY_MODE_EVEN       0x1
#define UART_PARITY_MODE_ODD        0x0

#define UART_WORD_LENGTH_5          0x0
#define UART_WORD_LENGTH_6          0x1
#define UART_WORD_LENGTH_7          0x2
#define UART_WORD_LENGTH_8          0x3

#define UART_STOP_BITS_ONE          0x0
#define UART_STOP_BITS_TWO          0x1

#define UART_CLOCK_SOURCE_PIOSC     0x5
#define UART_CLOCK_SOURCE_SYS       0x0

#define UART_CLOCK_SYS_DIV_8        0x1
#define UART_CLOCK_SYS_DIV_16       0x0

#define UART_INTERRUPT_MSK          (uint32)0x17F2

#define UART_NUMBER_OF_MODULES      8



/*========================================================
     LOCAL Variables Definition
 *========================================================*/
static uint16 RxBuffIndex=0;
static uint8 RxBuffer[RX_BUFFER_MAX_SIZE];

static uint32 UART_BaseAddrArr[8] = {UART0_BASE_ADDR , UART1_BASE_ADDR ,UART2_BASE_ADDR ,
                                     UART3_BASE_ADDR ,UART4_BASE_ADDR, UART5_BASE_ADDR ,
                                     UART6_BASE_ADDR ,UART7_BASE_ADDR };

/*========================================================
     LOCAL FUNCTIONS PROTOTYPES
 *========================================================*/
static inline void UART_setBaudRate(UART_ModNumType UartNo);

/*========================================================
     FUNCTIONS DEFINITIONS
 *========================================================*/
void UART_init(UART_ModNumType UartNo)
{
    /*  Disable the UART by clearing the UARTEN bit in the UARTCTL register. */

    UARTCTL(UART_BaseAddrArr[UartNo]).B.UARTEN = STD_low;

    /* configure baud rate */
    UART_setBaudRate(UartNo);

    /* Write the desired serial parameters to the UARTLCRH register  */
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.BRK = STD_low; /*UART does not send break*/
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.PEN = UART_PARITY_ENABLE;
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.EPS = UART_PARITY_MODE;
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.STP2 = UART_STOP_BITS;
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.FEN = UART_FIFO_ENABLE;
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.WLEN = UART_WORD_LENGTH;
    UARTLCRH(UART_BaseAddrArr[UartNo]).B.SPS = UART_PARITY_STICK;

    /* Configure the UART clock source by writing to the UARTCC register. */
    UARTCC(UART_BaseAddrArr[UartNo]) = UART_CLOCK_SOURCE;

    /* Optionally, configure the uDMA channel (see Micro Direct Memory Access (uDMA)� on page 585) and enable the DMA option(s) in the UARTDMACTL register. */
    UARTDMACTL(UART_BaseAddrArr[UartNo]).B.RXDMAE = UART_DMA_RX_ENABLE;
    UARTDMACTL(UART_BaseAddrArr[UartNo]).B.TXDMAE = UART_DMA_TX_ENABLE;
    UARTDMACTL(UART_BaseAddrArr[UartNo]).B.DMAERR = UART_DMA_DISABLE_ON_ERROR;

    /*configure loop back: The UnTx path is connected through the UnRx path*/
    UARTCTL(UART_BaseAddrArr[UartNo]).B.LBE = UART_LOOP_BACK_ENABLE;

    /* Enable the UART by setting the UARTEN bit in the UARTCTL register. */
    UARTCTL(UART_BaseAddrArr[UartNo]).B.UARTEN = STD_high;
    UARTCTL(UART_BaseAddrArr[UartNo]).B.UARTEN = STD_high;
    /*Enable Interrupt */
    UART_enInterrupt(UartNo);
}

void UART_enInterrupt(UART_ModNumType UartNo)
{
    UARTIM(UART_BaseAddrArr[UartNo]).B.BE   =UART_INTERRUPT_BREAKERROR;
    UARTIM(UART_BaseAddrArr[UartNo]).B.CTS  =UART_INTERRUPT_CLEARTOSEND;
    UARTIM(UART_BaseAddrArr[UartNo]).B.FE   =UART_INTERRUPT_FRAMMINGERROR;
    UARTIM(UART_BaseAddrArr[UartNo]).B.OE   =UART_INTERRUPT_OVERRUN;
    UARTIM(UART_BaseAddrArr[UartNo]).B.PE   =UART_INTERRUPT_PARITYERROR;
    UARTIM(UART_BaseAddrArr[UartNo]).B.RT   =UART_INTERRUPT_RXTIMEOUT;
    UARTIM(UART_BaseAddrArr[UartNo]).B.RX   =UART_INTERRUPT_RX;
    UARTIM(UART_BaseAddrArr[UartNo]).B.TX   =UART_INTERRUPT_TX;
    UARTIM(UART_BaseAddrArr[UartNo]).B._9BIT=UART_INTERRUPT_9BIT;
}

void UART_diInterrupt(UART_ModNumType UartNo)
{
    /* disable all UART interrupts*/
    UARTIM(UART_BaseAddrArr[UartNo]).R &= ~UART_INTERRUPT_MSK;
}


void UART_sendMsg(UART_ModNumType UartNo, uint8 Msg[], uint8 MsgLength)
{
    uint8 i;
    for (i = 0; i < MsgLength; ++i)
    {
        UARTDR(UART_BaseAddrArr[UartNo]) = Msg[i];
        /*wait for Transmission to b completed*/
        while( UARTFR(UART_BaseAddrArr[UartNo]).B.BUSY  ==  STD_high )
        {
            ;
        }
    }
}

void UART_getReceivedMsg(UART_ModNumType UartNo, uint8 Msg[], uint8* MsgLengthPtr)
{
    uint8 i;
    for (i = 0; i < RxBuffIndex; ++i)
    {
        Msg[i] = RxBuffer[i];
    }
    * MsgLengthPtr = RxBuffIndex;
    RxBuffIndex = 0;
}
void UART1_InterruptHandler(void)
{
    uint8 UartNo = UART1;
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.RX     == STD_high)
    {
        if(RxBuffIndex < RX_BUFFER_MAX_SIZE)
        {
            RxBuffer[RxBuffIndex++] = UARTDR(UART_BaseAddrArr[UartNo]);
        }

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.TX     == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.BE     == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.CTS    == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.FE     == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.OE     == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.PE     == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B.RT     == STD_high)
    {

    }
    if(UARTMIS(UART_BaseAddrArr[UartNo]).B._9BIT  == STD_high)
    {

    }
    /*TODO : clear flags*/

}



static inline void UART_setBaudRate(UART_ModNumType UartNo)
{
    uint32 ui32Div,ui32BaudRate = UART_BAUD_RATE;
    uint32 ui32UARTClk = SYSCTR_CLOCK_Hz;
    if((ui32BaudRate * 16) > ui32UARTClk)
    {
        /* Enable high speed mode */
        UARTCTL(UART_BaseAddrArr[UartNo]).B.HSE = STD_high;

        /*
        * Half the supplied baud rate to compensate for enabling high speed
        * mode.  This allows the following code to be common to both cases.
        */
        ui32BaudRate /= 2;
    }
    else
    {
        /*
        * Disable high speed mode.
        */
        UARTCTL(UART_BaseAddrArr[UartNo]).B.HSE = STD_low;
    }

    /*
    * Compute the fractional baud rate divider.
    */
    ui32Div = (((ui32UARTClk * 8) / ui32BaudRate) + 1) / 2;

    /*
    * Set the baud rate.
    */
    UARTIBRD(UART_BaseAddrArr[UartNo]) = ui32Div / 64;
    UARTFBRD(UART_BaseAddrArr[UartNo]) = ui32Div % 64;
}

