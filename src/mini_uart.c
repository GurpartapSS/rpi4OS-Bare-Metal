#include "gpio.h"
#include "utils.h"
#include "mini_uart.h"
#include "peripherals/aux.h"

#define TXD 14
#define RXD 15

void uart_init() {
    gpio_pin_set_func(TXD, GFAlt5);
    gpio_pin_set_func(RXD, GFAlt5);

    gpio_pin_enable(TXD);
    gpio_pin_enable(RXD);

    REGS_AUX->enables = 1;
    REGS_AUX->mu_control = 0;
    REGS_AUX->mu_ier = 0;
    REGS_AUX->mu_lcr = 3;
    REGS_AUX->mu_mcr = 0;

    //for rpi4 115200 @ 500 Mhz
    REGS_AUX->mu_baud = 541;

    REGS_AUX->mu_control = 3;

    uart_send('\r');
    uart_send('\r');
    uart_send('\n');
}

void uart_send(char c) {
    while(!(REGS_AUX->mu_lsr & 0x20));

    REGS_AUX->mu_io = c;
}

char uart_recv() {
    while(!(REGS_AUX->mu_lsr & 0x01));

    return REGS_AUX->mu_io & 0xFF;
}

void uart_send_string (char * s) {
    while(*s) {
        if(*s == '\n') {
            uart_send('\r');
        }
        uart_send(*s);
        s++;
    }
}