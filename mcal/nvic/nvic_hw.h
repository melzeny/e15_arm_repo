/*
 * nvic_hw.h
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */

#ifndef E15_ARM_REPO_MCAL_NVIC_NVIC_HW_H_
#define E15_ARM_REPO_MCAL_NVIC_NVIC_HW_H_


#define NVIC_REG    (*((volatile NVIC_TagType*)0xE000E000))

typedef struct
{
    uint32 B0:1;
    uint32 B1:1;
    uint32 B2:1;
    uint32 B3:1;
    uint32 B4:1;
    uint32 B5:1;
    uint32 B6:1;
    uint32 B7:1;
    uint32 B8:1;
    uint32 B9:1;
    uint32 B10:1;
    uint32 B11:1;
    uint32 B12:1;
    uint32 B13:1;
    uint32 B14:1;
    uint32 B15:1;
    uint32 B16:1;
    uint32 B17:1;
    uint32 B18:1;
    uint32 B19:1;
    uint32 B20:1;
    uint32 B21:1;
    uint32 B22:1;
    uint32 B23:1;
    uint32 B24:1;
    uint32 B25:1;
    uint32 B26:1;
    uint32 B27:1;
    uint32 B28:1;
    uint32 B29:1;
    uint32 B30:1;
    uint32 B31:1;
    uint32 B32:1;
}bit_field_Type;


typedef struct
{
    uint8 reserved [0x10];
    bit_field_Type STCTRL ;
    bit_field_Type STRELOAD ;
    bit_field_Type STCURRENT ;
    uint8 reserved1 [0xE4] ;
    bit_field_Type EN0 ;
    bit_field_Type EN1 ;
    bit_field_Type EN2 ;
    bit_field_Type EN3 ;
    bit_field_Type EN4 ;
}  NVIC_TagType;






#endif /* E15_ARM_REPO_MCAL_NVIC_NVIC_HW_H_ */
