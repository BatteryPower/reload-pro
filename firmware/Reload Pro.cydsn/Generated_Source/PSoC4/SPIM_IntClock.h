/*******************************************************************************
* File Name: SPIM_IntClock.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SPIM_IntClock_H)
#define CY_CLOCK_SPIM_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void SPIM_IntClock_Start(void);
void SPIM_IntClock_Stop(void);

void SPIM_IntClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 SPIM_IntClock_GetDividerRegister(void);
uint8  SPIM_IntClock_GetFractionalDividerRegister(void);

#define SPIM_IntClock_Enable()                         SPIM_IntClock_Start()
#define SPIM_IntClock_Disable()                        SPIM_IntClock_Stop()
#define SPIM_IntClock_SetDividerRegister(clkDivider, reset)  \
                        SPIM_IntClock_SetFractionalDividerRegister((clkDivider), 0)
#define SPIM_IntClock_SetDivider(clkDivider)           SPIM_IntClock_SetDividerRegister((clkDivider), 1)
#define SPIM_IntClock_SetDividerValue(clkDivider)      SPIM_IntClock_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define SPIM_IntClock_DIV_REG    (*(reg32 *)SPIM_IntClock__REGISTER)
#define SPIM_IntClock_ENABLE_REG SPIM_IntClock_DIV_REG

#endif /* !defined(CY_CLOCK_SPIM_IntClock_H) */

/* [] END OF FILE */
