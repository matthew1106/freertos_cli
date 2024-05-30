#include "spi_flash.h"

#include "string.h"
#include "stdio.h"

extern SPI_HandleTypeDef hspi2;

/*Command 0x90*/
uint8_t spi_flash_get_man_id(uint16_t *id)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData = 0x90;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	txData = 0xff;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id |= rxData << 8;

	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id |= rxData;

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0x9f*/
uint8_t spi_flash_get_dev_id(uint8_t *man_id, uint16_t *dev_id)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData = 0x9f;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*man_id = rxData;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*dev_id |= rxData >> 8;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*dev_id |= rxData;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);

	return 0;
}


/*Command 0x4b, return id length 8 bytes*/
uint8_t spi_flash_get_unique_id(uint8_t *id)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData = 0x4b;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	rxData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	id ++;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	*id = rxData;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0x66*/
uint8_t spi_flash_enable_reset()
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x66;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x99*/
uint8_t spi_flash_reset()
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x99;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x06*/
uint8_t spi_flash_enable_write()
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x06;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x04*/
uint8_t spi_flash_disable_write()
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x04;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x44*/
/* three 1024-byte Security Registers*/
uint8_t spi_flash_erase_security_reg(uint8_t reg)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x04;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0x42*/
/*3-reg address*/
uint8_t spi_flash_prog_security_reg(uint8_t reg, uint8_t *data, uint32_t len)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	uint32_t i = 0;
	if(len > 1024)
	{
		return 1;
	}
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	//Command 0x42
	txData  = 0x42;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	//Address 3 bytes
	//0-> 0x001000
	//1-> 0x002000
	//2-> 0x003000
	txData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = (reg + 1) << 4;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	for(i = 0; i<len; i++)
	{
		HAL_SPI_TransmitReceive(&hspi2, &data[i], &rxData, 1, 1000);
	}
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0x48*/
uint8_t spi_flash_read_security_reg(uint8_t reg, uint8_t *data, uint32_t len)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	uint32_t i = 0;
	if(len > 1024)
	{
		len = 1024;
	}


	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	//Command 0x42
	txData  = 0x48;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	//Address 3 bytes
	//0-> 0x001000
	//1-> 0x002000
	//2-> 0x003000
	txData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = (reg + 1) << 4;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = 0x00;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	//Add dummy byte
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	for(i = 0; i<len; i++)
	{
		HAL_SPI_TransmitReceive(&hspi2, &txData, &data[i], 1, 1000);
	}
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0xb7*/
uint8_t spi_flash_enable_4b()
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0xb7;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0xe9*/
uint8_t spi_flash_disable_4b()
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0xe9;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0x05*/
uint8_t spi_flash_read_status_reg1(uint8_t *reg)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x05;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, reg, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x35*/
uint8_t spi_flash_read_status_reg2(uint8_t *reg)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x35;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, reg, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}



/*Command 0x15*/
uint8_t spi_flash_read_config_reg(uint8_t *reg)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x15;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	HAL_SPI_TransmitReceive(&hspi2, &txData, reg, 1, 1000);
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x01*/
uint8_t spi_flash_write_status_reg1(uint8_t data)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x01;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = data;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


/*Command 0x31*/
uint8_t spi_flash_write_status_reg2(uint8_t data)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x31;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = data;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}

/*Command 0x11*/
uint8_t spi_flash_write_config_reg(uint8_t data)
{
	uint8_t txData = 0x00;
	uint8_t rxData = 0x00;
	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 0);
	txData  = 0x11;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);
	txData = data;
	HAL_SPI_TransmitReceive(&hspi2, &txData, &rxData, 1, 1000);

	HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, 1);
	return 0;
}


