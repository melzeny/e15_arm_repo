/*
 * spi_lcfg.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#define SPI_PRIVATE_CONFIG


#include "../utils/STD_types.h"
#include "../mcal/spi/spi_types.h"

const uint8 SPI_NumOfActivatedSpi = 4;
const SPI_cfgType SPI_CfgArr[]    = {
/*==============================================================================================================================================================================================================================================================================================================================================================================================================================*
 *  SPI_ModNUm             BitRate             DataCapturedOnFirstEdge             IdleCLockState             FrameFormat                    DataSize                          OprMode             LoopBack             DMA_Tx             DMA_Rx             ClockSource                          FIFO_EN             Interrupt_RxOverRun             Interrupt_RxTimeout             Interrupt_Rxc             Interrupt_Txc  *
 *==============================================================================================================================================================================================================================================================================================================================================================================================================================*/
 {  SPI_Num_0,             5000000,            ENABLE,                             STD_high,                  SPI_FrameFormate_FreeScale,    SPI_DataSize_08_Bits,             SPI_OprMode_Master, ENABLE,              DISABLE,           DISABLE,           SPI_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       ENABLE ,                  DISABLE,       },
 {  SPI_Num_1,             5000000,            ENABLE,                             STD_high,                  SPI_FrameFormate_FreeScale,    SPI_DataSize_08_Bits,             SPI_OprMode_Master, ENABLE,              DISABLE,           DISABLE,           SPI_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       DISABLE,                  DISABLE,       },
 {  SPI_Num_2,             5000000,            ENABLE,                             STD_high,                  SPI_FrameFormate_FreeScale,    SPI_DataSize_08_Bits,             SPI_OprMode_Master, ENABLE,              DISABLE,           DISABLE,           SPI_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       DISABLE,                  DISABLE,       },
 {  SPI_Num_3,             5000000,            ENABLE,                             STD_high,                  SPI_FrameFormate_FreeScale,    SPI_DataSize_08_Bits,             SPI_OprMode_Master, ENABLE,              DISABLE,           DISABLE,           SPI_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       DISABLE,                  DISABLE,       }
};



