/*
 * i2c.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_I2C_I2C_H_
#define E15_ARM_REPO_MCAL_I2C_I2C_H_

#include "../../utils/STD_Types.h"
#include "i2c_types.h"

void I2C_init(void);
void I2C_enInterrupt(I2C_ModNumType I2cNo);
void I2C_diInterrupt(I2C_ModNumType I2cNo);
void I2C_sendMsg(I2C_ModNumType I2cNo, uint8 Msg[], uint8 MsgLength);
void I2C_getReceivedMsg(I2C_ModNumType I2cNo, uint8 Msg[], uint8* MsgLengthPtr);


#endif /* E15_ARM_REPO_MCAL_I2C_I2C_H_ */
