/*
 * lab_01_dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Bit_Math.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/dio/dio.h"
void lab_01_dio(void)
{
    uint8 RandomNum;
    SysCtr_init();
    PORT_init();


    while(1)
    {
        RandomNum++;
        Dio_WriteChannel(Dio_Channel_F0, GET_BIT(RandomNum,0));
        Dio_WriteChannel(Dio_Channel_F1, GET_BIT(RandomNum,3));
        Dio_WriteChannel(Dio_Channel_F2, GET_BIT(RandomNum,5));
    }

}


