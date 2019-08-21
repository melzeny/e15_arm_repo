/*
 * spi_lcfg.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#define SPI_PRIVATE_CONFIG


#include "../utils/STD_types.h"
#include "../mcal/spi/spi_types.h"


const Spi_ConfigType Spi_CfgArr[]    = {
/*========================================================================================================================================================================================================================================================================================================================================================================================================================================================*
 *  Spi_ModNUm                BitRate             DataCaptureClockEdge                       IdleCLockState             FrameFormat                           DataSize                          OprMode                      LoopBack             DMA_Tx             DMA_Rx             ClockSource                          FIFO_EN             Interrupt_RxOverRun             Interrupt_RxTimeout             Interrupt_Rxc             Interrupt_Txc  *
 *========================================================================================================================================================================================================================================================================================================================================================================================================================================================*/
 {  Spi_Channel0,             5000000,            Spi_DataCaptureClockEdge_First,            STD_high,                  Spi_FrameFormate_FreeScale,           Spi_NumberOfData_08_Bits,         Spi_OprMode_Master,          ENABLE,              DISABLE,           DISABLE,           Spi_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       ENABLE ,                  DISABLE,       },
 {  Spi_Channel1,             5000000,            Spi_DataCaptureClockEdge_First,            STD_high,                  Spi_FrameFormate_FreeScale,           Spi_NumberOfData_08_Bits,         Spi_OprMode_Master,          ENABLE,              DISABLE,           DISABLE,           Spi_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       DISABLE,                  DISABLE,       },
 {  Spi_Channel2,             5000000,            Spi_DataCaptureClockEdge_First,            STD_high,                  Spi_FrameFormate_FreeScale,           Spi_NumberOfData_08_Bits,         Spi_OprMode_Master,          ENABLE,              DISABLE,           DISABLE,           Spi_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       DISABLE,                  DISABLE,       },
 {  Spi_Channel3,             5000000,            Spi_DataCaptureClockEdge_First,            STD_high,                  Spi_FrameFormate_FreeScale,           Spi_NumberOfData_08_Bits,         Spi_OprMode_Master,          ENABLE,              DISABLE,           DISABLE,           Spi_ClockSource_SysClock,            DISABLE,            DISABLE,                         DISABLE,                       DISABLE,                  DISABLE,       }
};







