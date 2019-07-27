/*
 * port.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8

#include "../../utils/STD_types.h"
#include "../../config/port_cfg.h"
#include "Port_hw.h"
#include "port_types.h"
#include "port.h"

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{
    uint8 i;
    Port_IdType PortId;
    Port_ChIdType ChId;
    for (i = 0; i < PORT_NUM_OF_ACTIVATED_CH; ++i)
    {
        PortId = i/ MAX_NUM_OF_CH_IN_PORT;
        ChId = i % MAX_NUM_OF_CH_IN_PORT;

        switch (PortId) {
            case Port_Id_A:
                /* set channel direction */

                /* set channel mode */

                /* set Interrupt configuration */

                /* set Internal Attachment configuration */

                /*set current strength configuration */

                /* enable digital */

                /*disable ADC */

                /*set lock configuration */

                break;
            default:
                break;
        }
    }


}
