#include "common.h"
#include "mini_uart.h"
#include "printf.h"

u32 get_el();

void putc(void *p, char c) {
    if(c == '\n') {
        uart_send('\r');
    }

    uart_send(c);
}

void kernel_main() {
    uart_init();
    init_printf(0, putc);
    printf("Printing RPI Bare Metal OS Initializing .....\n");

    #if RPI_VERSION == 4
        // uart_send_string("\tBoard : Raspberry Pi 4\n");
        uart_send_string("\tBoard : Raspberry Pi 4\n");
    #endif

    printf("\nDone with exception level: %d \n",get_el());

    while (1) {
        uart_send(uart_recv());
    }
}