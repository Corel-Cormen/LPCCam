/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_i2c.h"
#include "fsl_spi.h"
#include "fsl_gpio.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* BOARD_InitPeripherals defines for FLEXCOMM4 */
/* Definition of peripheral ID */
#define FLEXCOMM4_PERIPHERAL ((I2C_Type *)FLEXCOMM4)
/* Definition of the clock source frequency */
#define FLEXCOMM4_CLOCK_SOURCE 12000000UL
/* BOARD_InitPeripherals defines for FLEXCOMM8 */
/* Definition of peripheral ID */
#define FLEXCOMM8_PERIPHERAL ((SPI_Type *)FLEXCOMM8)
/* Definition of the clock source frequency */
#define FLEXCOMM8_CLOCK_SOURCE 12000000UL
/* Definition of peripheral ID */
#define GPIO_GPIO GPIO

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const i2c_master_config_t FLEXCOMM4_config;
extern const spi_master_config_t FLEXCOMM8_config;

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
