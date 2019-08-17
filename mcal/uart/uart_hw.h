/*
 * uart_hw.h
 *
 *  Created on: May 21, 2019
 *      Author: Yasmin
 */

#ifndef SRC_DEVICE_DRIVER_UART_UART_HW_H_
#define SRC_DEVICE_DRIVER_UART_UART_HW_H_

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
    UART_INTERRUPT_TAG IM   ;
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


#endif /* SRC_DEVICE_DRIVER_UART_UART_HW_H_ */
