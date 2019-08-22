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
#define Spi_NUMBER_OF_HW_UINTS                    4
/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"

#include "../../config/spi_cfg.h"
#include "spi_types.h"
#include "spi.h"

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
static Spi_ChannelParamType Spi_ChannelParam[Spi_NUMBER_OF_HW_UINTS];
/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/

void Spi_init(void)
{
    uint8 i;
    Spi_ChannelType Channel;
    for (i = 0; i < Spi_NUM_OF_ACTIVATED_UNITS; ++i)
    {
        Channel = Spi_CfgArr[i].Spi_Channel;
        /* (1) Disable Spi to init configuration */
        SSICR1(Spi_BaseAddrArr[Channel]).B.SSE = STD_low;

        /* (2) Select whether the SSI is a master or slave  */
        SSICR1(Spi_BaseAddrArr[Channel]).B.MS = Spi_CfgArr[i].CFG_OprMode;

        /*TODO  configure loop back test */


        /*TODO configure Tx Interrupt Mode  */


        /*TODO  (3) Configure the SSI clock source by writing to the SSICC register. */


        /*TODO  (4) Set Bit Rate with clock rate and clock prescaler */


        /*TODO  (5) Configure Clock phase */


        /*TODO  Configure Clock  polarity */


        /*TODO  Configure Protocol mode  */


        /*TODO  Configure Data Size */


        /* TODO (7) Enable Spi to init configuration */


        /*change SPi Unit status */
        Spi_ChannelParam[Channel].Status = SPI_IDLE;
    }
}
void Spi_enInterrupt(Spi_ChannelType Channel)
{

    uint8 ChConfigIndex;
    /*search for Channel config index with ChannelId*/
    for(ChConfigIndex=0; ChConfigIndex < Spi_NUM_OF_ACTIVATED_UNITS; ChConfigIndex++)
    {
        if(Channel == Spi_CfgArr[ChConfigIndex].Spi_Channel)
        {
            break;
        }
    }
    /*TODO  enable Interrupts as configured in Spi_CfgArr*/


}
void Spi_diInterrupt(Spi_ChannelType Channel)
{
    /*TODO disable all interrupt from this Channel*/

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
    /* Check if Channel in Idle status */
    if(Spi_ChannelParam[Channel].Status == SPI_IDLE)
    {
        /*TODO Set Channel Status to be in Busy State */

        /*TODO Copy Data from DataBufferPtr To Tx Buffer */


        /*TODO reset TxBufferIndex */

        /*TODO  Set TxMsgSize to DataBufferSize value */

        /*set Channel status to be Idle*/
        Spi_ChannelParam[Channel].Status = SPI_IDLE;
    }
    else
    {
        /* Return Not_Ok if Channel Status not Idle */
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
    /*Check if there is any Rx Data*/
    if(Spi_ChannelParam[Channel].RxBufferIndex != 0)
    {
        /*TODO Copy Data From RXBuffer to DataBufferPtr Location */


        /*TODO Write into DataBufferSizePtr location the last RxBufferIndex*/

        /*TODO Reset RxBufferIndex */

    }
    else
    {
        /*TODO Return Not Ok if There is no Received Data */

    }
    return ret;
}


Std_ReturnType Spi_AsyncTransmit(Spi_ChannelType Channel)
{
    Std_ReturnType ret = E_OK;
    if(Spi_ChannelParam[Channel].Status == SPI_IDLE)
    {
        /* set channel status to be Busy*/
        Spi_ChannelParam[Channel].Status = SPI_BUSY;

        /*loop for TxBuffer */
        for (Spi_ChannelParam[Channel].TxBufferIndex = 0;
                Spi_ChannelParam[Channel].TxBufferIndex < Spi_ChannelParam[Channel].TxMsgSize ;
                Spi_ChannelParam[Channel].TxBufferIndex++)
        {
            /* TODO send TxBuffer Frame By Frame */


            /* No need to wait as every Frame loaded in FIFO.
             * If FIFO is Full Interrupt will fire and continue to transmit the message */
        }
        /*TODO ResetTxBufferIndex */

        /*TODO  set channel status to be IDLE*/

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
        /*TODO  set channel status to be Busy*/


        /*TODO loop for TxBuffer */

            /* TODO send TxBuffer Frame By Frame */

            /* TODO wait for Data to be transmitted */


        /*end of loop */

        /*TODO Reset Channel TxBufferIndex */

        /* TODO set channel status to be IDLE*/

    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

static inline void Spi_SetBitRate(Spi_ChannelType Channel ,uint32 u32SSInClk)
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
    /* Calculate CPSDVSR and SCR */
    do
    {
        u8CPSDVSR +=2;
        u32SCR = (TempRatio / u8CPSDVSR ) - 1;
    }while(u32SCR > 255);
    /*TODO write calculated value to SSICPSR and SSICR0 registers */
    SSICPSR(Spi_BaseAddrArr[Channel]) = u8CPSDVSR;

}

static inline void Spi_IntRoutine(Spi_ChannelType Channel)
{
    if(SSIMIS(Spi_BaseAddrArr[Channel]).B.TXMIS == STD_high)
    {
        /*TODO ONLY IN Master: Transmit new Frame if Transmission is Asynchronous*/

    }

    if(SSIMIS(Spi_BaseAddrArr[Channel]).B.RXMIS == STD_high)
    {
        uint8 ChConfigIndex;
        /* Check if RxIndex exceed Max Buffer Size */
        if(Spi_ChannelParam[Channel].RxBufferIndex <Spi_RX_BUFFER_SIZE)
        {
            /*TODO read data in SSIDR and copy value into RxBuffer */

        }

        /*TODO search for Channel config index with ChannelId*/


        /*ONLY IN SLAVE MODE :  transmit TxBuffer to master*/
        if(Spi_CfgArr[ChConfigIndex].CFG_OprMode == Spi_OprMode_Slave)
        {

                /*TODO send Frame from Slave TxBuffer*/



                /*TODO Reset TxBufferIndex if it exceed the Buffer size */


        }
    }

    if(SSIMIS(Spi_BaseAddrArr[Channel]).B.RTMIS == STD_high)
    {


    }

    if(SSIMIS(Spi_BaseAddrArr[Channel]).B.RORMIS == STD_high)
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
