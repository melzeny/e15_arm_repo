/*
 * Port_hw.h
 *
 *  Created on: Jul 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_
#define E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_

#include "../../utils/STD_types.h"

typedef struct
{
    uint32 GPIODATA    ; /*offset : 0x000 - > 0x004 */

    uint8 Reserved_1[0x3FC];
    uint32 GPIODIR     ; /*offset : 0x400*/
    uint32 GPIOIS      ;
    uint32 GPIOIBE     ;
    uint32 GPIOIEV     ;
    uint32 GPIOIM      ;
    uint32 GPIORIS     ;
    uint32 GPIOMIS     ;
    uint32 GPIOICR     ;
    uint32 GPIOAFSEL   ; /*offset : 0x420 -> 424 */

    uint8 Reserved_2[0xDC];
    uint32 GPIODR2R    ; /*offset : 0x500 */
    uint32 GPIODR4R    ;
    uint32 GPIODR8R    ;
    uint32 GPIOODR     ;
    uint32 GPIOPUR     ;
    uint32 GPIOPDR     ;
    uint32 GPIOSLR     ;
    uint32 GPIODEN     ;
    uint32 GPIOLOCK    ;
    uint32 GPIOCR      ;
    uint32 GPIOAMSEL   ;
    uint32 GPIOPCTL    ;
    uint32 GPIOADCCTL  ;
    uint32 GPIODMACTL  ;
}PORT_RegType;

#define PORT_REG_A      *((PORT_RegType*)0x40058000)
#define PORT_REG_B      *((PORT_RegType*)0x40059000)
#define PORT_REG_C      *((PORT_RegType*)0x4005A000)
#define PORT_REG_D      *((PORT_RegType*)0x4005B000)
#define PORT_REG_E      *((PORT_RegType*)0x4005C000)
#define PORT_REG_F      *((PORT_RegType*)0x4005D000)


#endif /* E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_ */
