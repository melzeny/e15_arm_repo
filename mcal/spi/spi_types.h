/*
 * spi_types.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_SPI_SPI_TYPES_H_
#define E15_ARM_REPO_MCAL_SPI_SPI_TYPES_H_

typedef enum
{
    SPI_Num_0,
    SPI_Num_1,
    SPI_Num_2,
    SPI_Num_3
}SPI_ModNumType;


/*========================================================*
 *      PRIVATE TYPES                                     *
 * =======================================================*/

#ifdef SPI_PRIVATE_CONFIG

typedef enum
{
    SPI_FrameFormate_FreeScale,
    SPI_FrameFormate_Ti,
    SPI_FrameFormate_Microwire

}SPI_FrameFormateType;


typedef enum
{

    SPI_DataSize_04_Bits,
    SPI_DataSize_05_Bits,
    SPI_DataSize_06_Bits,
    SPI_DataSize_07_Bits,
    SPI_DataSize_08_Bits,
    SPI_DataSize_09_Bits,
    SPI_DataSize_10_Bits,
    SPI_DataSize_11_Bits,
    SPI_DataSize_12_Bits,
    SPI_DataSize_13_Bits,
    SPI_DataSize_14_Bits,
    SPI_DataSize_15_Bits,
    SPI_DataSize_16_Bits

}SPI_DataSizeType;

typedef enum
{
    SPI_OprMode_Master,
    SPI_OprMode_Slave

}SPI_OprModeType;


typedef enum
{
    SPI_ClockSource_SysClock,
    SPI_ClockSource_PIOSC

}SPI_ClockSourceType;

typedef struct
{
    SPI_ModNumType              SPI_ModNum;
    uint32                      CFG_BitRate;
    STD_EnType                  CFG_DataCapturedOnFirstEdge;
    STD_levelType               CFG_IdleCLockState;
    SPI_FrameFormateType        CFG_FrameFormat;
    SPI_DataSizeType            CFG_DataSize;
    SPI_OprModeType             CFG_OprMode;
    STD_EnType                  CFG_LoopBack;
    STD_EnType                  CFG_DMA_Tx;
    STD_EnType                  CFG_DMA_Rx;
    SPI_ClockSourceType         CFG_ClockSource;
    STD_EnType                  CFG_Fifo;
    STD_EnType                  CFG_Interrupt_RxOverRun;
    STD_EnType                  CFG_Interrupt_RxTimeout;
    STD_EnType                  CFG_Interrupt_Rxc;
    STD_EnType                  CFG_Interrupt_Txc;
}SPI_cfgType;

#endif /* ifdef SPI_DRIVER */

#endif /* E15_ARM_REPO_MCAL_SPI_SPI_TYPES_H_ */
