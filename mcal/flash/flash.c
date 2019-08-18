/*
 * flash.c
 *
 *  Created on: Jun 8, 2019
 *      Author: Yasmin
 */
/*========================================================
     INCLUDES
*========================================================*/
#include "../mcu_hw.h"
#include "flash_cfg.h"
#include "flash.h"
/*========================================================
     FUNCTION IMPLEMENTATION
*========================================================*/
void FLASH_init(void)
{

}
void FLASH_writeData(uint32 u32Addr,uint32* u32Data,uint32 u32DataLength)
{
    uint32 i;
    /*TODO: Check if Address is valid */
    FLASH_FMA_R = u32Addr;
    for(i=0;i<u32DataLength;i++)
    {
        FLASH_FMD_R = u32Data[i];

        /*start writing from FMD to Flash*/
        FLASH_FMC_R = 0xA4420001;

        while(FLASH_FCRIS.B.Prog == STD_low);
        /*clear program cycle interrupt flag*/
        FLASH_FCMISC.B.Prog == STD_high;
        FLASH_FMA_R+=4;
    }

}
