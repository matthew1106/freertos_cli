/*
 * spi_flash.h
 *
 *  Created on: May 28, 2024
 *      Author: DELL
 */

#ifndef INC_SPI_FLASH_H_
#define INC_SPI_FLASH_H_

#include "stdint.h"
#include "main.h"
#include "stm32f4xx_hal.h"



uint8_t spi_flash_get_man_id(uint16_t *id);
uint8_t spi_flash_get_dev_id(uint8_t *man_id, uint16_t *dev_id);
uint8_t spi_flash_disable_4b();
uint8_t spi_flash_enable_4b();
uint8_t spi_flash_disable_write();
uint8_t spi_flash_enable_write();
uint8_t spi_flash_erase_security_reg(uint8_t reg);
uint8_t spi_flash_prog_security_reg(uint8_t reg, uint8_t *data, uint32_t len);
uint8_t spi_flash_read_security_reg(uint8_t reg, uint8_t *data, uint32_t len);
uint8_t spi_flash_enable_reset();
uint8_t spi_flash_reset();
uint8_t spi_flash_get_unique_id(uint8_t *id);
uint8_t spi_flash_read_status_reg1(uint8_t *reg);
uint8_t spi_flash_read_status_reg2(uint8_t *reg);
uint8_t spi_flash_read_config_reg(uint8_t *reg);

uint8_t spi_flash_write_status_reg1(uint8_t reg);
uint8_t spi_flash_write_status_reg2(uint8_t reg);
uint8_t spi_flash_write_config_reg(uint8_t reg);

#endif /* INC_SPI_FLASH_H_ */
