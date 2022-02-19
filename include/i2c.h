#pragma once

#include "common.h"

typedef enum _i2c_status {
    I2C_SUCCESS,
    I2C_ACK_ERROR,
    I2C_DATA_LOSS,
    I2C_CLOCK_TIMEOUT,
} i2c_status;

void i2c_init();

i2c_status i2c_recv(u8 address, u8* buffer, u32 size);

i2c_status i2c_send(u8 address, u8* buffer, u32 size);