/*
 * i2c.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */
/*================================================*
 * DEFINES
 * ==============================================*/
#define I2C_PRIVATE_CONFIG
/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../mcu_hw.h"

#include "i2c_types.h"
#include "../../config/i2c_cfg.h"
#include "i2c.h"

/*================================================*
 * EXTERNS
 * ==============================================*/
extern const uint8 I2C_NumOfActivatedSpi;
extern const I2c_MasterConfigType I2C_Master_CfgArr[];
extern const I2c_SlaveConfigType I2C_Slave_CfgArr[];
/*================================================*
 * LOCAL VARIABLES
 * ==============================================*/
static const uint32 I2c_BaseAddrArr[] = {I2C_0_BASE_ADDRESS, I2C_1_BASE_ADDRESS, I2C_2_BASE_ADDRESS, I2C_3_BASE_ADDRESS};

/*================================================*
 * LOCAL FUNCTIONS
 * ==============================================*/
static inline void I2c_GenerateStartCond(I2c_ChannelType Channel);
static inline void I2c_GenerateStopCond(I2c_ChannelType Channel);
static inline void I2c_SetSlaveAddr(I2c_ChannelType Channel , uint8 SlaveAddress);

/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/
void I2c_Init(void)
{
    /* Initialize the I2C Mode Master\slave */

    /* FOR MASTER: Set the desired SCL clock speed */

    /*FOR MASTER:  Enable Master TxRx */
}
void I2c_enInterrupt(I2c_ChannelType Channel)
{

}
void I2c_diInterrupt(I2c_ChannelType Channel)
{

}


/*=================================================================================
 * NAME:        I2c_WriteIB
 * DESCRIBTION: The Function shall take over the given parame-ters,
 * and save the pointed data to the internal buffer defined with the function
 * =================================================================================*/
Std_ReturnType I2c_WriteIB( I2c_ChannelType Channel, const uint8* DataBufferPtr,uint8 DataBufferSize)
{


}

/* =================================================================================
 * NAME:          I2c_ReadIB
 * DESCRIBTION:   The function I2c_ReadIB provides the service
 * for reading synchronously one or more data from an IB
 * =================================================================================*/
Std_ReturnType I2c_ReadIB( I2c_ChannelType Channel, uint8* DataBufferPointer, uint8* DataBufferSizePtr )
{
    Std_ReturnType  ret = E_OK;

    return ret;
}

Std_ReturnType I2c_AsyncTransmit(I2c_ChannelType Channel)
{
    Std_ReturnType  ret = E_OK;


    return ret;
}
Std_ReturnType I2c_SyncTransmit(I2c_ChannelType Channel)
{
    Std_ReturnType  ret = E_OK;


    return ret;
}

static inline void I2c_GenerateStartCond(I2c_ChannelType Channel)
{

}
static inline void I2c_GenerateStopCond(I2c_ChannelType Channel)
{

}
static inline void I2c_SetSlaveAddr(I2c_ChannelType Channel , uint8 SlaveAddress)
{


}
static inline void I2c_SetClockSpeed(I2c_ChannelType Channel ,uint32 SclPeriod)
{


}
/*==================================================================
 * INTERRUPT HANDLERS
 * ================================================================*/
static inline void I2c_IntRoutine(I2c_ChannelType Channel)
{


}

void I2c0_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel0);
}
void I2c1_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel1);
}
void I2c2_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel2);
}
void I2c3_IntHandler(void)
{
    I2c_IntRoutine(I2c_Channel3);
}
