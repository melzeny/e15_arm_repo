/*
 * Port_hw.h
 *
 *  Created on: Jul 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_
#define E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_

#include "../utils/STD_Types.h"

/*===========================================================*
 * NVIC REGISTERS                                            *
 *========================================================== */

#define NVIC_REG    (*((volatile NVIC_TagType*)0xE000E100))

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
    bit_field_Type EN0 ;
    bit_field_Type EN1 ;
    bit_field_Type EN2 ;
    bit_field_Type EN3 ;
    bit_field_Type EN4 ;
}  NVIC_TagType;

/*===========================================================*
 * FLASH REGISTERS                                           *
 *========================================================== */
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


#define FLASH_FMA_R             (*((volatile uint32 *)0x400FD000))
#define FLASH_FMD_R             (*((volatile uint32 *)0x400FD004))
#define FLASH_FMC_R             (*((volatile uint32 *)0x400FD008))
#define FLASH_FCRIS             (*((volatile FLASH_INT_TAG *)0x400FD00C))
#define FLASH_FCIM_R            (*((volatile uint32 *)0x400FD010))
#define FLASH_FCMISC            (*((volatile FLASH_INT_TAG *)0x400FD014))
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

/*===========================================================*
 * GPIO REGISTERS                                            *
 *========================================================== */
typedef struct
{
    uint32 GPIODATA    ;
    uint32 GPIODIR     ;
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

#define PORTA_REG     (*((volatile PORT_RegType*)0x400043FC))
#define PORTB_REG     (*((volatile PORT_RegType*)0x400053FC))
#define PORTC_REG     (*((volatile PORT_RegType*)0x400063FC))
#define PORTD_REG     (*((volatile PORT_RegType*)0x400073FC))
#define PORTE_REG     (*((volatile PORT_RegType*)0x400243FC))
#define PORTF_REG     (*((volatile PORT_RegType*)0x400253FC))

/*===========================================================*
 * RCC REGISTERS                                             *
 *========================================================== */
typedef struct
{
    uint32 R0:1;
    uint32 R1:1;
    uint32 R2:1;
    uint32 R3:1;
    uint32 R4:1;
    uint32 R5:1;
    uint32 R6:1;
    uint32 R7:1;
}RCGC_TagType;

#define RCGCGPIO_REG    (*((volatile RCGC_TagType*)0x400FE608))
#define RCGCUART_REG    (*((volatile RCGC_TagType*)0x400FE618))


/*===========================================================*
 * UART REGISTERS                                            *
 *========================================================== */

typedef union
{
    uint32 R;
    struct
    {
        uint32 UARTEN       :1;
        uint32 SIREN        :1;
        uint32 SIRLP        :1;
        uint32 SMART        :1;
        uint32 EOT          :1;
        uint32 HSE          :1;
        uint32              :1;
        uint32 LBE          :1;
        uint32 TXE          :1;
        uint32 RXE          :1;
        uint32              :1;
        uint32 RTS          :1;
        uint32              :2;
        uint32 RTSEN        :1;
        uint32 CTSEN        :1;
        uint32              :16;
    }B;
}UART_CTL_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 BRK        :1;
        uint32 PEN        :1;
        uint32 EPS        :1;
        uint32 STP2       :1;
        uint32 FEN        :1;
        uint32 WLEN       :2;
        uint32 SPS        :1;
        uint32            :24;
    }B;
}UART_LCRH_TAG;
typedef union
{
    uint32 R;
    struct
    {
        uint32 RXDMAE        :1;
        uint32 TXDMAE        :1;
        uint32 DMAERR        :1;
        uint32               :29;
    }B;
}UART_DMACTL_TAG;


typedef union
{
    uint32 R;
    struct
    {
        uint32            :1;
        uint32 CTS        :1;
        uint32            :2;
        uint32 RX         :1;
        uint32 TX         :1;
        uint32 RT         :1;
        uint32 FE         :1;
        uint32 PE         :1;
        uint32 BE         :1;
        uint32 OE         :1;
        uint32            :1;
        uint32 _9BIT      :1;
        uint32            :19;
    }B;
}UART_INTERRUPT_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 CTS        :1;
        uint32            :2;
        uint32 BUSY       :1;
        uint32 RXFE       :1;
        uint32 TXFF       :1;
        uint32 RXFF       :1;
        uint32 TXFE       :1;
        uint32            :24;
    }B;
}UART_FR_TAG;


typedef struct
{
    uint32 DR               ;
    uint32 ECR              ;
    UART_FR_TAG FR          ;
    uint8 reserved[0x4]     ;
    uint32 ILPR             ;
    uint32 IBRD             ;
    uint32 FBRD             ;
    UART_LCRH_TAG LCRH      ;
    UART_CTL_TAG CTL        ;
    uint32 IFLS             ;
    UART_INTERRUPT_TAG IM  ;
    UART_INTERRUPT_TAG RIS  ;
    UART_INTERRUPT_TAG MIS  ;
    UART_INTERRUPT_TAG ICR  ;
    UART_DMACTL_TAG DMACTL  ;
    uint8 reserved_2[0x58]  ;
    uint32 U9BITADDR        ;
    uint32 U9BITAMASK       ;
    uint8 reserved_3[0xF14] ;
    uint32 PP               ;
    uint8 reserved_4[0x4]   ;
    uint32 CC               ;
}UART_RegType;

#define UART1_DR_R              (*((volatile uint32 *)0x4000D000))
#define UART1_RSR_R             (*((volatile uint32 *)0x4000D004))
#define UART1_ECR_R             (*((volatile uint32 *)0x4000D004))
#define UART1_FR                (*((volatile UART_FR_TAG *)0x4000D018))
#define UART1_ILPR_R            (*((volatile uint32 *)0x4000D020))
#define UART1_IBRD_R            (*((volatile uint32 *)0x4000D024))
#define UART1_FBRD_R            (*((volatile uint32 *)0x4000D028))
#define UART1_LCRH              (*((volatile UART_LCRH_TAG *)0x4000D02C))
#define UART1_CTL               (*((volatile UART_CTL_TAG *)0x4000D030))
#define UART1_IFLS_R            (*((volatile uint32 *)0x4000D034))
#define UART1_IM                (*((volatile UART_INTERRUPT_TAG *)0x4000D038))
#define UART1_RIS               (*((volatile UART_INTERRUPT_TAG *)0x4000D03C))
#define UART1_MIS               (*((volatile UART_INTERRUPT_TAG *)0x4000D040))
#define UART1_ICR               (*((volatile UART_INTERRUPT_TAG *)0x4000D044))
#define UART1_DMACTL            (*((volatile UART_DMACTL_TAG *)0x4000D048))
#define UART1_9BITADDR_R        (*((volatile uint32 *)0x4000D0A4))
#define UART1_9BITAMASK_R       (*((volatile uint32 *)0x4000D0A8))
#define UART1_PP_R              (*((volatile uint32 *)0x4000DFC0))
#define UART1_CC_R              (*((volatile uint32 *)0x4000DFC8))

/*===========================================================*
 * SPI REGISTERS                                            *
 *========================================================== */
#define SPI0_BASE_ADDR             ( (volatile SPI_RegType* const )0x40008000)
#define SPI1_BASE_ADDR             ( (volatile SPI_RegType* const )0x40009000)
#define SPI2_BASE_ADDR             ( (volatile SPI_RegType* const )0x4000A000)
#define SPI3_BASE_ADDR             ( (volatile SPI_RegType* const )0x4000B000)

typedef union
{
    uint32 R;
    struct
    {
        uint32 DDS        :4        ;
        uint32 FRF        :2        ;
        uint32 SPO        :1        ;
        uint32 SPH        :1        ;
        uint32 SCR        :8        ;
        uint32            :16       ;

    }B;
}SPI_SSICR0_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 LBM        :1        ;
        uint32 SSE        :1        ;
        uint32 MS         :1        ;
        uint32            :1        ;
        uint32 EOT        :1        ;
        uint32            :27       ;

    }B;
}SPI_SSICR1_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 TFE        :1        ;
        uint32 TNF        :1        ;
        uint32 RNE        :1        ;
        uint32 RFF        :1        ;
        uint32 BSY        :1        ;
        uint32            :27       ;

    }B;
}SPI_SSISR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORIM        :1      ;
        uint32 RTIM         :1      ;
        uint32 RXIM         :1      ;
        uint32 TXIM         :1      ;
        uint32              :28     ;

    }B;
}SPI_SSIIM_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORRIS      :1       ;
        uint32 RTRIS       :1       ;
        uint32 RXRIS       :1       ;
        uint32 TXRIS       :1       ;
        uint32             :28      ;

    }B;
}SPI_SSIRIS_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORMIS       :1      ;
        uint32 RTMIS        :1      ;
        uint32 RXMIS        :1      ;
        uint32 TXMIS        :1      ;
        uint32              :28     ;

    }B;
}SPI_SSIMIS_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RORIC        :1      ;
        uint32 RTIC         :1      ;
        uint32              :30     ;

    }B;
}SPI_SSIICR_TAG;

typedef union
{
    uint32 R;
    struct
    {
        uint32 RXDMAE      :1       ;
        uint32 TXDMAE      :1       ;
        uint32             :30      ;

    }B;
}SPI_SSIDMACTL_TAG;

typedef struct
{
    SPI_SSICR0_TAG SSICR0           ;
    SPI_SSICR1_TAG SSICR1           ;
    uint32 SSIDR                    ;
    SPI_SSISR_TAG SSISR             ;
    uint32 SSICPSR                  ;
    SPI_SSIIM_TAG SSIIM             ;
    SPI_SSIRIS_TAG SSIRIS           ;
    SPI_SSIMIS_TAG SSIMIS           ;
    SPI_SSIICR_TAG SSIICR           ;
    SPI_SSIDMACTL_TAG SSIDMACTL     ;
    uint8  reserved[0xFA0]            ;
    uint32 SSICC                    ;
    uint32 SSIPeriphID4             ;
    uint32 SSIPeriphID5             ;
    uint32 SSIPeriphID6             ;
    uint32 SSIPeriphID7             ;
    uint32 SSIPeriphID0             ;
    uint32 SSIPeriphID1             ;
    uint32 SSIPeriphID2             ;
    uint32 SSIPeriphID3             ;
    uint32 SSIPCellID0              ;
    uint32 SSIPCellID1              ;
    uint32 SSIPCellID2              ;
    uint32 SSIPCellID3              ;

}SPI_RegType ;

#endif /* E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_ */
