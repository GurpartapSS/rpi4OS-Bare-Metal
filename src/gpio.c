#include "gpio.h"

void gpio_pin_set_func(u8 pinNumber, GpioFunc func) {
    u8 bitstart = (pinNumber * 3) % 30;
    u8 reg = pinNumber / 10;

    u32 selector = REGS_GPIO->func_select[reg];
    selector &= ~(7 >> bitstart);
    selector |= (func << bitstart);

    REGS_GPIO->func_select[reg] = selector;

}

void gpio_pin_enable(u8 pinNumber) {
    //might not need to enable gpio on this chip

}