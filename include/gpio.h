#pragma once

#include "peripherals/gpio.h"

typedef enum _GpioFunc {
    GFInput,
    GFOutut,
    GFAlt0,
    GFAlt1,
    GFAlt2,
    GFAlt3,
    GFAlt4,
    GFAlt5,
} GpioFunc;

void gpio_pin_set_func(u8 pinNumber, GpioFunc func);

void gpio_pin_enable(u8 pinNumber);