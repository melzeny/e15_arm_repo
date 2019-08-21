/*
 * spi.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */
/*================================================*
 * DEFINES
 * ==============================================*/
#define SPI_PRIVATE_CONFIG
#define Spi_TX_BUFFER_SIZE                   50
#define Spi_RX_BUFFER_SIZE                   50
/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"

#include "../../config/spi_cfg.h"
#include "spi_types.h"
#include "spi.h"

typedef struct
{
    uint32 TxMsgSize;
    uint16 TxBuffer[Spi_TX_BUFFER_SIZE];
    uint32 TxBufferIndex;
    uint16 RxBuffer[Spi_RX_BUFFER_SIZE];
    uint32 RxBufferIndex;
    Spi_StatusType Status;
}Spi_ChannelParamType;
/*================================================*
 * LOCAL FUNCTIONS
 * ==============================================*/
static inline void Spi_SetBitRate(Spi_ChannelType SpiNum ,uint32 BitRate);
static inline void Spi_IntRoutine(Spi_ChannelType channel);
/*================================================*
 * EXTERNS
 * ==============================================*/
extern const Spi_ConfigType Spi_CfgArr[];

/*================================================*
 * LOCAL VARIABLES
 * ==============================================*/
static const uint32 Spi_BaseAddrArr[] = {SPI0_BASE_ADDR, SPI1_BASE_ADDR, SPI2_BASE_ADDR, SPI3_BASE_ADDR};
static Spi_ChannelParamType Spi_ChannelParam[Spi_NUM_OF_ACTIVATED_UINTS];
/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/

void Spi_init(void)
{
    uint8 SpiNo;
    for (SpiNo = 0; SpiNo < Spi_NUM_OF_ACTIVATED_UINTS; ++SpiNo)
    {
        /* (1) Disable Spi to init configuration */
        SSICR1(Spi_BaseAddrArr[SpiNo]).B.SSE = STD_low;

        /* (2) Select whether the SSI is a master or slave  */
        SSICR1(Spi_BaseAddrArr[SpiNo]).B.MS = Spi_CfgArr[SpiNo].CFG_OprMode;

        /* configure loop back test */
        SSICR1(Spi_BaseAddrArr[SpiNo]).B.LBM = Spi_CfgArr[SpiNo].CFG_LoopBack;

        /* (3) Configure the SSI clock source by writing to the SSICC register. */
        SSICC(Spi_BaseAddrArr[SpiNo]) = Spi_CfgArr[SpiNo].CFG_ClockSource;

        /* (4) Set Bit Rate with clock rate and clock prescaler */
        Spi_SetBitRate((Spi_ChannelType)SpiNo, Spi_CfgArr[SpiNo].CFG_BitRate);

        /* (5) Configure Clock phase */
        SSICR0(Spi_BaseAddrArr[SpiNo]).B.SPH = Spi_CfgArr[SpiNo].CFG_DataCaptureClockEdge;

        /* Configure Clock  polarity */
        SSICR0(Spi_BaseAddrArr[SpiNo]).B.SPO = Spi_CfgArr[SpiNo].CFG_IdleCLockState;

        /* Configure Protocol mode  */
        SSICR0(Spi_BaseAddrArr[SpiNo]).B.FRF = Spi_CfgArr[SpiNo].CFG_FrameFormat;

        /* Configure Data Size */
        SSICR0(Spi_BaseAddrArr[SpiNo]).B.DDS = Spi_CfgArr[SpiNo].CFG_DataSize;

        /* (7) Enable Spi to init configuration */
        SSICR1(Spi_BaseAddrArr[SpiNo]).B.SSE = STD_high;

        /*change SPi Unit status */
        Spi_ChannelParam[SpiNo].Status = SPI_IDLE;
    }
}
void Spi_enInterrupt(Spi_ChannelType SpiNo)
{
    SSIIM(Spi_BaseAddrArr[SpiNo]).B.RORIM = Spi_CfgArr[SpiNo].CFG_Interrupt_RxOverRun;
    SSIIM(Spi_BaseAddrArr[SpiNo]).B.RORIM = Spi_CfgArr[SpiNo].CFG_Interrupt_RxTimeout;
    SSIIM(Spi_BaseAddrArr[SpiNo]).B.RORIM = Spi_CfgArr[SpiNo].CFG_Interrupt_Rxc;
    SSIIM(Spi_BaseAddrArr[SpiNo]).B.RORIM = Spi_CfgArr[SpiNo].CFG_Interrupt_Txc;
}
void Spi_diInterrupt(Spi_ChannelType SpiNo)
{
    SSIIM(Spi_BaseAddrArr[SpiNo]).R = STD_low;
}

Spi_StatusType Spi_GetStatus(Spi_ChannelType Channel)
{
    return Spi_ChannelParam[Channel].Status;

}

/*=================================================================================
 * NAME:        Spi_WriteIB
 * DESCRIBTION: The Function shall save the pointed data to
 *  the internal buffer defined with the function
 * =================================================================================*/
Std_ReturnType Spi_WriteIB( Spi_ChannelType Channel, const uint16* DataBufferPtr,uint8 DataBufferSize)
{
    uint8 i;
    uint8 max = (DataBufferSize> Spi_TX_BUFFER_SIZE) ? Spi_TX_BUFFER_SIZE : DataBufferSize ;
    Std_ReturnType ret = E_OK;
    if(Spi_ChannelParam[Channel].Status == SPI_IDLE)
    {
        Spi_ChannelParam[Channel].Status = SPI_BUSY;
        for (i = 0; i < max ; ++i)
        {
            Spi_ChannelParam[Channel].TxBuffer[i] = DataBufferPtr[i];
        }
        Spi_ChannelParam[Channel].TxMsgSize = DataBufferSize;
        Spi_ChannelParam[Channel].Status = SPI_IDLE;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

/* =================================================================================
 * NAME:          Spi_ReadIB
 * DESCRIBTION:   The function Spi_ReadIB provides the service
 * for reading synchronously one or more data from an IB
 * =================================================================================*/
Std_ReturnType Spi_ReadIB( Spi_ChannelType Channel, uint16* DataBufferPtr, uint8* DataBufferSizePtr )
{
    uint8 i;
    Std_ReturnType ret = E_OK;
    if(Spi_ChannelParam[Channel].RxBufferIndex != 0)
    {
        for (i = 0; i < Spi_ChannelParam[Channel].RxBufferIndex ; ++i)
        {
            DataBufferPtr[i] = Spi_ChannelParam[Channel].RxBuffer[i] ;
        }
        * DataBufferSizePtr = Spi_ChannelParam[Channel].RxBufferIndex;
        Spi_ChannelParam[Channel].RxBufferIndex = 0;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}


Std_ReturnType Spi_AsyncTransmit(Spi_ChannelType Channel)
{
    Std_ReturnType ret = E_OK;
    if(Spi_ChannelParam[Channel].Status == SPI_IDLE)
    {
        Spi_ChannelParam[Channel].Status = SPI_BUSY;

        for (Spi_ChannelParam[Channel].TxBufferIndex = 0;
                Spi_ChannelParam[Channel].TxBufferIndex < Spi_ChannelParam[Channel].TxMsgSize ;
                Spi_ChannelParam[Channel].TxBufferIndex++)
        {
            SSIDR(Spi_BaseAddrArr[Channel]) = Spi_ChannelParam[Channel].TxBuffer[Spi_ChannelParam[Channel].TxBufferIndex];

            /* No need to wait as every Frame loaded in FIFO.
             * If FIFO is Full Interrupt will fire and continue to transmit the message */
        }
        /*clear Tx flag*/

        /*Reset Channel Param */
        Spi_ChannelParam[Channel].TxBufferIndex = 0;
        Spi_ChannelParam[Channel].TxMsgSize = 0;
        /* set channel status to be IDLE*/
        Spi_ChannelParam[Channel].Status = SPI_IDLE;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

Std_ReturnType Spi_SyncTransmit(Spi_ChannelType Channel)
{
    Std_ReturnType ret = E_OK;
    if(Spi_ChannelParam[Channel].Status == SPI_IDLE)
    {
        Spi_ChannelParam[Channel].Status = SPI_BUSY;

        for (Spi_ChannelParam[Channel].TxBufferIndex = 0;
                Spi_ChannelParam[Channel].TxBufferIndex < Spi_ChannelParam[Channel].TxMsgSize ;
                Spi_ChannelParam[Channel].TxBufferIndex++)
        {
            SSIDR(Spi_BaseAddrArr[Channel]) = Spi_ChannelParam[Channel].TxBuffer[Spi_ChannelParam[Channel].TxBufferIndex];
            /* wait for Data to be transmitted */
            while(SSISR(Spi_BaseAddrArr[Channel]).B.BSY == STD_high)
            {
                ;
            }
        }
        /*clear Tx flag*/

        /*Reset Channel Param */
        Spi_ChannelParam[Channel].TxBufferIndex = 0;
        Spi_ChannelParam[Channel].TxMsgSize = 0;
        /* set channel status to be IDLE*/
        Spi_ChannelParam[Channel].Status = SPI_IDLE;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

static inline void Spi_SetBitRate(Spi_ChannelType SpiNo ,uint32 u32SSInClk)
{
    /*
     *
     * SSInClk = SysClk / (CPSDVSR * (1 + SCR))
     * CPSDVSR is an even value from 2-254 programmed in the
     * SSICPSR register, and SCR is a value from 0-255.
     *
     * */
    uint8 u8CPSDVSR=0;
    uint32 u32SCR=0;

    uint32 TempRatio = u32SYS_CLOCK_Hz / u32SSInClk;  /*  TempRatio = (CPSDVSR * (1 + SCR)) */
    do
    {
        u8CPSDVSR +=2;
        u32SCR = (TempRatio / u8CPSDVSR ) - 1;
    }while(u32SCR > 255);

    SSICPSR(Spi_BaseAddrArr[SpiNo]) = u8CPSDVSR;
    SSICR0(Spi_BaseAddrArr[SpiNo]).B.SCR = u32SCR;
}

static inline void Spi_IntRoutine(Spi_ChannelType Channel)
{
    if(SSIMIS(Channel).B.TXMIS == STD_high)
    {
        if(Spi_ChannelParam[Channel].TxBufferIndex < Spi_ChannelParam[Channel].TxMsgSize)
        {
            SSIDR(Spi_BaseAddrArr[Channel]) = Spi_ChannelParam[Channel].TxBuffer[Spi_ChannelParam[Channel].TxBufferIndex++];
        }
        else
        {
            /*clear Tx flag*/
        }
    }

    if(SSIMIS(Channel).B.RXMIS == STD_high)
    {
        if(Spi_ChannelParam[Channel].RxBufferIndex <Spi_RX_BUFFER_SIZE)
        {
            Spi_ChannelParam[Channel].RxBuffer[Spi_ChannelParam[Channel].RxBufferIndex++] = SSIDR(Spi_BaseAddrArr[Channel]);
        }
    }

    if(SSIMIS(Channel).B.RTMIS == STD_high)
    {


    }

    if(SSIMIS(Channel).B.RORMIS == STD_high)
    {


    }

}

void SPI0_IntHandler(void)
{
    Spi_IntRoutine(Spi_Channel0);
}
void SPI1_IntHandler(void)
{
    Spi_IntRoutine(Spi_Channel1);
}
void SPI2_IntHandler(void)
{
    Spi_IntRoutine(Spi_Channel2);
}
void SPI3_IntHandler(void)
{
    Spi_IntRoutine(Spi_Channel3);
}
