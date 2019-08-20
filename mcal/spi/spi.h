/*
 * spi.h
 *
 *  Created on: Aug 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_SPI_SPI_H_
#define E15_ARM_REPO_MCAL_SPI_SPI_H_

#include "../../utils/STD_Types.h"
#include "spi_types.h"


void SPI_init(void);
void SPI_enInterrupt(SPI_ModNumType SpiNo);
void SPI_diInterrupt(SPI_ModNumType SpiNo);
void SPI_sendMsg(SPI_ModNumType SpiNo, uint8 Msg[], uint8 MsgLength);
void SPI_getReceivedMsg(SPI_ModNumType SpiNo, uint8 Msg[], uint8* MsgLengthPtr);


#endif /* E15_ARM_REPO_MCAL_SPI_SPI_H_ */
