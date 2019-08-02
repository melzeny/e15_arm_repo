/*
 * lab_01_dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/dio/dio.h"
void lab_01_dio(void)
{
    SysCtr_init();
    PORT_init();
    Dio_WriteChannel(Dio_Channel_F0, STD_high);

    while(1)
    {
        ;
    }

}


