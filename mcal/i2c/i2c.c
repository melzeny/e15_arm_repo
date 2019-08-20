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
extern const I2C_Master_cfgType I2C_Master_CfgArr[];
extern const I2C_Slave_cfgType I2C_Slave_CfgArr[];
/*================================================*
 * LOCAL VARIABLES
 * ==============================================*/
static const uint32 I2C_BaseAddrArr[] = {I2C_0_BASE_ADDRESS, I2C_1_BASE_ADDRESS, I2C_2_BASE_ADDRESS, I2C_3_BASE_ADDRESS};
/*================================================*
 * FUNCTIONS DEFINTIONS
 * ==============================================*/
void I2C_init(void)
{

}
void I2C_enInterrupt(I2C_ModNumType I2cNo)
{

}
void I2C_diInterrupt(I2C_ModNumType I2cNo)
{

}
void I2C_sendMsg(I2C_ModNumType I2cNo, uint8 Msg[], uint8 MsgLength)
{


}
void I2C_getReceivedMsg(I2C_ModNumType I2cNo, uint8 Msg[], uint8* MsgLengthPtr)
{


}

static inline void I2C_IntRoutine(I2C_ModNumType I2cNo)
{


}

void I2C0_IntHandler(void)
{
    I2C_IntRoutine(I2C_0);
}
void I2C1_IntHandler(void)
{
    I2C_IntRoutine(I2C_1);
}
void I2C2_IntHandler(void)
{
    I2C_IntRoutine(I2C_2);
}
void I2C3_IntHandler(void)
{
    I2C_IntRoutine(I2C_3);
}


