/*
 * spi_hw.h
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */

#ifndef E15_ARM_REPO_MCAL_SPI_SPI_HW_H_
#define E15_ARM_REPO_MCAL_SPI_SPI_HW_H_

#define SPI0_BASE_ADDR             ( (volatile SPI_RegType* const )0x40008000)
#define SPI1_BASE_ADDR             ( (volatile SPI_RegType* const )0x40009000)
#define SPI2_BASE_ADDR             ( (volatile SPI_RegType* const )0x4000A000)
#define SPI3_BASE_ADDR             ( (volatile SPI_RegType* const )0x4000B000)


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

#endif /* E15_ARM_REPO_MCAL_SPI_SPI_HW_H_ */
