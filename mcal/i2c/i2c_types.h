/*
 * i2c_types.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_
#define E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_



typedef enum
{
    I2C_0,
    I2C_1,
    I2C_2,
    I2C_3,
}I2C_ModNumType;

#ifdef I2C_PRIVATE_CONFIG

typedef enum
{
    GlitchFilter_PW_Bypass,
    GlitchFilter_PW_01_Clock,
    GlitchFilter_PW_02_Clocks,
    GlitchFilter_PW_03_Clocks,
    GlitchFilter_PW_04_Clocks,
    GlitchFilter_PW_08_Clocks,
    GlitchFilter_PW_16_Clocks,
    GlitchFilter_PW_31_Clocks,

}I2C_GlitchFilterPwType;

typedef struct
{
    I2C_ModNumType                  I2cNum;
    uint32                          ClockRate;
    STD_EnType                      MasterHighSpeed;
    STD_EnType                      ClockHighSpeed;
    STD_EnType                      AutoDataAck;
    STD_EnType                      GlitchFilter;
    I2C_GlitchFilterPwType          GlitchFilter_PulseWidth;
    STD_EnType                      LoopbackTest;
    STD_EnType                      FIfo;
    STD_EnType                      Interrupt_Master;
    STD_EnType                      Interrupt_ClkTimeout;
}I2C_Master_cfgType;

typedef struct
{
    I2C_ModNumType                  I2cNum;
    uint32                          SlaveAddr;
    STD_EnType                      ALtSlaveAdrr_EN;
    uint32                          ALtSlaveAdrr;
    STD_EnType                      Slave_HighSpeed;
    STD_EnType                      Interrupt_STO;
    I2C_GlitchFilterPwType          Interrupt_STA;
    STD_EnType                      Interrupt_Rxc;
}I2C_Slave_cfgType;

#endif


#endif /* E15_ARM_REPO_MCAL_I2C_I2C_TYPES_H_ */
