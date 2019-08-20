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

/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"
#include "spi_types.h"
#include "spi.h"

/*================================================*
 * EXTERNS
 * ==============================================*/
extern const uint8 SPI_NumOfActivatedSpi;
extern  SPI_cfgType SPI_CfgArr[];

/*================================================*
 * LOCAL VARIABLES
 * ==============================================*/
static const uint32 SPI_BaseAddrArr[] = {SPI0_BASE_ADDR, SPI1_BASE_ADDR, SPI2_BASE_ADDR, SPI3_BASE_ADDR};

/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/

void SPI_init(void)
{
    uint8 i;
    for (i = 0; i < SPI_NumOfActivatedSpi; ++i)
    {

    }

}
void SPI_enInterrupt(SPI_ModNumType SpiNo)
{


}
void SPI_diInterrupt(SPI_ModNumType SpiNo)
{


}
void SPI_sendMsg(SPI_ModNumType SpiNo, uint8 Msg[], uint8 MsgLength)
{


}
void SPI_getReceivedMsg(SPI_ModNumType SpiNo, uint8 Msg[], uint8* MsgLengthPtr)
{


}

static inline void SPI_IntRoutine(SPI_ModNumType SpiNum)
{



}

void SPI0_IntHandler(void)
{
    SPI_IntRoutine(SPI_Num_0);
}
void SPI1_IntHandler(void)
{
    SPI_IntRoutine(SPI_Num_1);
}
void SPI2_IntHandler(void)
{
    SPI_IntRoutine(SPI_Num_2);
}
void SPI3_IntHandler(void)
{
    SPI_IntRoutine(SPI_Num_3);
}
