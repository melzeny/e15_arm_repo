/*
 * port_lcfg.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../mcal/port_driver/port_types.h"
#include "port_cfg.h"

Port_CfgType PortCfgArr[PORT_NUM_OF_ACTIVATED_CH] = {

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*    Channel                   Direction                Mode                    External Interrupt      Attached_Resistor                      Current_Drive_Strength      Lock_Status    */
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
{     Port_Channel_A0,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A1,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A2,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A3,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A4,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A5,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A6,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_A7,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },

{     Port_Channel_B0,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B1,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B2,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B3,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B4,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B5,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B6,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_B7,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },

{     Port_Channel_C0,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C1,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C2,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C3,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C4,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C5,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C6,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_C7,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },

{     Port_Channel_D0,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D1,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D2,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D3,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D4,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D5,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D6,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_D7,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },

{     Port_Channel_E0,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_E1,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_E2,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_E3,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_E4,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_E5,          port_Dir_Input,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },

{     Port_Channel_F0,          port_Dir_Output,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_F1,          port_Dir_Output,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_F2,          port_Dir_Output,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_F3,          port_Dir_Output,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     },
{     Port_Channel_F4,          port_Dir_Output,          Port_Mode_DIO,          Port_IntDisable,        Port_InternalAttach_OpenDrain,         Port_CurrDrive_2mA,         Port_locked     }

};
