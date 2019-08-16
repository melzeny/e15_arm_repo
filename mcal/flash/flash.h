/*
 * flash.h
 *
 *  Created on: Jun 8, 2019
 *      Author: Yasmin
 */

#ifndef SRC_DEVICE_DRIVER_FLASH_FLASH_H_
#define SRC_DEVICE_DRIVER_FLASH_FLASH_H_

void FLASH_writeData(uint32 u32Addr,uint32* u32Data,uint32 u32DataLength);
void FLASH_init(void);



#endif /* SRC_DEVICE_DRIVER_FLASH_FLASH_H_ */
