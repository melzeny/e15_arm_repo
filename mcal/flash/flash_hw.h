/*
 * flash_hw.h
 *
 *  Created on: Jun 8, 2019
 *      Author: zeiny
 */

#ifndef SRC_DEVICE_DRIVER_FLASH_FLASH_HW_H_
#define SRC_DEVICE_DRIVER_FLASH_FLASH_HW_H_

typedef union
{
    uint32 R;
    struct
    {
        uint32 Access               :1;
        uint32 Prog                 :1;
        uint32 EEPROM               :1;
        uint32                      :6;
        uint32 VoltErr              :1;
        uint32 InvalidData          :1;
        uint32 EraseVerErr          :1;
        uint32                      :1;
        uint32 ProgVerErr           :1;
        uint32                      :18;
    }B;
}FLASH_INT_TAG;
//*****************************************************************************
//
// FLASH registers (FLASH CTRL)
//
//*****************************************************************************
#define FLASH_FMA_R             (*((volatile uint32 *)0x400FD000))
#define FLASH_FMD_R             (*((volatile uint32 *)0x400FD004))
#define FLASH_FMC_R             (*((volatile uint32 *)0x400FD008))
#define FLASH_FCRIS          (*((volatile FLASH_INT_TAG *)0x400FD00C))
#define FLASH_FCIM_R            (*((volatile uint32 *)0x400FD010))
#define FLASH_FCMISC          (*((volatile FLASH_INT_TAG *)0x400FD014))
#define FLASH_FMC2_R            (*((volatile uint32 *)0x400FD020))
#define FLASH_FWBVAL_R          (*((volatile uint32 *)0x400FD030))
#define FLASH_FWBN_R            (*((volatile uint32 *)0x400FD100))
#define FLASH_FSIZE_R           (*((volatile uint32 *)0x400FDFC0))
#define FLASH_SSIZE_R           (*((volatile uint32 *)0x400FDFC4))
#define FLASH_ROMSWMAP_R        (*((volatile uint32 *)0x400FDFCC))
#define FLASH_RMCTL_R           (*((volatile uint32 *)0x400FE0F0))
#define FLASH_BOOTCFG_R         (*((volatile uint32 *)0x400FE1D0))
#define FLASH_USERREG0_R        (*((volatile uint32 *)0x400FE1E0))
#define FLASH_USERREG1_R        (*((volatile uint32 *)0x400FE1E4))
#define FLASH_USERREG2_R        (*((volatile uint32 *)0x400FE1E8))
#define FLASH_USERREG3_R        (*((volatile uint32 *)0x400FE1EC))
#define FLASH_FMPRE0_R          (*((volatile uint32 *)0x400FE200))
#define FLASH_FMPRE1_R          (*((volatile uint32 *)0x400FE204))
#define FLASH_FMPRE2_R          (*((volatile uint32 *)0x400FE208))
#define FLASH_FMPRE3_R          (*((volatile uint32 *)0x400FE20C))
#define FLASH_FMPPE0_R          (*((volatile uint32 *)0x400FE400))
#define FLASH_FMPPE1_R          (*((volatile uint32 *)0x400FE404))
#define FLASH_FMPPE2_R          (*((volatile uint32 *)0x400FE408))
#define FLASH_FMPPE3_R          (*((volatile uint32 *)0x400FE40C))



#endif /* SRC_DEVICE_DRIVER_FLASH_FLASH_HW_H_ */
