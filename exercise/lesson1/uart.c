#include "uart.h"
#include "gpio.h"

#define TXD 14
#define RXD 15
#define FUARTCLK 48000000
#define BAUDRATE 115200

void uart0_init() {
    gpio_pin_set_func(TXD, GFAlt0);
    gpio_pin_set_func(RXD, GFAlt0);

    gpio_pin_enable(TXD);
    gpio_pin_enable(RXD);

    UART_REGS->CR = 0;

    // int IBR = FUARTCLK/(16*BAUDRATE);
    UART_REGS->IntBaudRD = 26;
    UART_REGS->FloatBaudRD = 3;
    // UART_REGS->FloatBaudRD = (int)(((3000000.0f/BAUDRATE) - IBR) * 64.0f);

    // UART_REGS->LCRH |= (1 << 4);
    UART_REGS->LCRH |= (3 << 5);

    UART_REGS->IMSC = 0;

    UART_REGS->CR |= (1 | (1<<8) | (1<<9));

}

void uart0_send_char(char s) {
    while(!(UART_REGS->FlagR & (1<<7)));

    UART_REGS->DataR = s;
}

char uart0_read_char() {
    while(!(UART_REGS->FlagR & (1<<6)));

    return (UART_REGS->DataR & 0xFF);
}

void uart0_send_string(char *s) {
    while(*s) {
        if(*s == '\n') {
            uart0_send_char('\r');
        }
        uart0_send_char(*s);
        s++;
    }
}