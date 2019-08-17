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
#include "uart_types.h"
#include "uart_hw.h"
#include "uart_cfg.h"
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

#define UART0_BASE_ADDR             ( (volatile UART_RegType* const )0x4000C000)
#define UART1_BASE_ADDR             ( (volatile UART_RegType* const )0x4000D000)
#define UART2_BASE_ADDR             ( (volatile UART_RegType* const )0x4000E000)
#define UART3_BASE_ADDR             ( (volatile UART_RegType* const )0x4000F000)
#define UART4_BASE_ADDR             ( (volatile UART_RegType* const )0x40010000)
#define UART5_BASE_ADDR             ( (volatile UART_RegType* const )0x40011000)
#define UART6_BASE_ADDR             ( (volatile UART_RegType* const )0x40012000)
#define UART7_BASE_ADDR             ( (volatile UART_RegType* const )0x40013000)

/*========================================================
     LOCAL Variables Definition
 *========================================================*/
static uint16 RxBuffIndex=0;
static uint8 RxBuffer[RX_BUFFER_MAX_SIZE];

static volatile UART_RegType* const UART_BaseAddrArr[8] = {UART0_BASE_ADDR , UART1_BASE_ADDR ,UART2_BASE_ADDR ,
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

    UART1_CTL.B.UARTEN = STD_low;

    /* configure baud rate */
    UART_setBaudRate(UartNo);

    /* Write the desired serial parameters to the UARTLCRH register  */
    UART1_LCRH.B.BRK = STD_low; /*UART does not send break*/
    UART1_LCRH.B.PEN = UART_PARITY_ENABLE;
    UART1_LCRH.B.EPS = UART_PARITY_MODE;
    UART1_LCRH.B.STP2 = UART_STOP_BITS;
    UART1_LCRH.B.FEN = UART_FIFO_ENABLE;
    UART1_LCRH.B.WLEN = UART_WORD_LENGTH;
    UART1_LCRH.B.SPS = UART_PARITY_STICK;

    /* Configure the UART clock source by writing to the UARTCC register. */
    UART1_CC_R = UART_CLOCK_SOURCE;

    /* Optionally, configure the uDMA channel (see Micro Direct Memory Access (uDMA)� on page 585) and enable the DMA option(s) in the UARTDMACTL register. */
    UART1_DMACTL.B.RXDMAE = UART_DMA_RX_ENABLE;
    UART1_DMACTL.B.TXDMAE = UART_DMA_TX_ENABLE;
    UART1_DMACTL.B.DMAERR = UART_DMA_DISABLE_ON_ERROR;

    /*configure loop back: The UnTx path is connected through the UnRx path*/
    UART1_CTL.B.LBE = UART_LOOP_BACK_ENABLE;

    /* Enable the UART by setting the UARTEN bit in the UARTCTL register. */
    UART1_CTL.B.UARTEN = STD_high;
    UART1_CTL.B.UARTEN = STD_high;
    /*Enable Interrupt */
    UART_enInterrupt(UartNo);
}

void UART_enInterrupt(UART_ModNumType UartNo)
{
    UART1_IM.B.BE   =UART_INTERRUPT_BREAKERROR;
    UART1_IM.B.CTS  =UART_INTERRUPT_CLEARTOSEND;
    UART1_IM.B.FE   =UART_INTERRUPT_FRAMMINGERROR;
    UART1_IM.B.OE   =UART_INTERRUPT_OVERRUN;
    UART1_IM.B.PE   =UART_INTERRUPT_PARITYERROR;
    UART1_IM.B.RT   =UART_INTERRUPT_RXTIMEOUT;
    UART1_IM.B.RX   =UART_INTERRUPT_RX;
    UART1_IM.B.TX   =UART_INTERRUPT_TX;
    UART1_IM.B._9BIT=UART_INTERRUPT_9BIT;
}

void UART_diInterrupt(UART_ModNumType UartNo)
{
    /* disable all UART interrupts*/
    UART1_IM.R &= ~UART_INTERRUPT_MSK;
}


void UART_sendMsg(UART_ModNumType UartNo, uint8 Msg[], uint8 MsgLength)
{
    uint8 i;
    for (i = 0; i < MsgLength; ++i)
    {
        UART1_DR_R = 'a';
        /*wait for Transmission to b completed*/
        while(UART1_FR.B.BUSY == STD_high)
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
    if(UART1_MIS.B.RX     == STD_high)
    {
        if(RxBuffIndex < RX_BUFFER_MAX_SIZE)
        {
            RxBuffer[RxBuffIndex++] = UART1_DR_R;
        }

    }
    if(UART1_MIS.B.TX     == STD_high)
    {

    }
    if(UART1_MIS.B.BE     == STD_high)
    {

    }
    if(UART1_MIS.B.CTS    == STD_high)
    {

    }
    if(UART1_MIS.B.FE     == STD_high)
    {

    }
    if(UART1_MIS.B.OE     == STD_high)
    {

    }
    if(UART1_MIS.B.PE     == STD_high)
    {

    }
    if(UART1_MIS.B.RT     == STD_high)
    {

    }
    if(UART1_MIS.B._9BIT  == STD_high)
    {

    }
    /*clear all flags*/
   // UART1_ICR.R |= UART_INTERRUPT_MSK;
}



static inline void UART_setBaudRate(UART_ModNumType UartNo)
{
    uint32 ui32Div,ui32BaudRate = UART_BAUD_RATE;
    uint32 ui32UARTClk = SYSCTR_CLOCK_Hz;
    if((ui32BaudRate * 16) > ui32UARTClk)
    {
        //
        // Enable high speed mode.
        //
        UART1_CTL.B.HSE = STD_high;

        //
        // Half the supplied baud rate to compensate for enabling high speed
        // mode.  This allows the following code to be common to both cases.
        //
        ui32BaudRate /= 2;
    }
    else
    {
        //
        // Disable high speed mode.
        //
        UART1_CTL.B.HSE = STD_low;
    }

    //
    // Compute the fractional baud rate divider.
    //
    ui32Div = (((ui32UARTClk * 8) / ui32BaudRate) + 1) / 2;

    //
    // Set the baud rate.
    //
    UART1_IBRD_R = ui32Div / 64;
    UART1_FBRD_R = ui32Div % 64;
}

