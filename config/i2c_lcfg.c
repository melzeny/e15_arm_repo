/*
 * i2c_lcfg.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
/*================================================*
 * DEFINES
 * ==============================================*/
#define I2C_PRIVATE_CONFIG

/*================================================*
 * INCLUDES
 * ==============================================*/
#include "../utils/STD_types.h"
#include "../mcal/i2c/i2c_types.h"
#include "i2c_cfg.h"


/*================================================*
 * CONFIGURATIONS
 * ==============================================*/



const uint8 I2C_NumOfActivatedSpi = 4;

#if I2C_OPR_MODE_SELECTOR  == I2C_OPR_MODE_MASTER
const I2C_Master_cfgType I2C_Master_CfgArr[]    = {
/*============================================================================================================================================================================================================================================================================*
 *  I2C_ModNUm             CLockRate             Master_HighSpeed             CLock_HighSpeed           AutoDataAck       GlitchFilter                 GlitchFilter_PulseWidth             LoopBack       FIFO_EN             Interrupt_Master           Interrupt_ClkTimeout *
 *============================================================================================================================================================================================================================================================================*/
 {  I2C_0,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            },
 {  I2C_1,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            },
 {  I2C_2,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            },
 {  I2C_3,                 5000000,              ENABLE,                      ENABLE,                   ENABLE,             ENABLE,                    GlitchFilter_PW_Bypass,             ENABLE,        DISABLE,            DISABLE,                    DISABLE,            }
};

/*else*/

const I2C_Slave_cfgType I2C_Slave_CfgArr[]    = {
/*=========================================================================================================================================================================================================*
 *  I2C_ModNUm             SlaveAddr             ALtSlaveAdrr_EN             ALtSlaveAdrr             HighSpeed             Interrupt_STO             Interrupt_STA                        Interrupt_Rxc   *
 *=========================================================================================================================================================================================================*/
 {  I2C_0,                 0x12345678,            DISABLE,                   0x12345678,               DISABLE,              DISABLE,                 ENABLE ,                             DISABLE,        },
 {  I2C_1,                 0x12312325,            DISABLE,                   0x12312325,               DISABLE,              DISABLE,                 DISABLE,                             DISABLE,        },
 {  I2C_2,                 0x45645678,            DISABLE,                   0x45645678,               DISABLE,              DISABLE,                 DISABLE,                             DISABLE,        },
 {  I2C_3,                 0x20245678,            DISABLE,                   0x20245678,               DISABLE,              DISABLE,                 DISABLE,                             DISABLE,        }
};

#endif
