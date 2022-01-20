#include "common.h"
#include "mini_uart.h"
#include "printf.h"
#include "uart.h"
#include "utils.h"

u32 get_el();
int is_uart_init = 0;
void putc(void *p, char c) {
    if(c == '\n') {
        // uart_send('\r');
        uart0_send_char('\r');
    }

    uart0_send_char(c);
}

void kernel_main(int id) {
    // uart_init();
    if (id == 0) {
        uart0_init();
        init_printf(0, putc);
        uart0_send_string("Bare Metal UART Initializing .....\n");
        is_uart_init = 1;
    } else {
        delay(id*100000);
    }
    while(is_uart_init!=1);
    printf("Printing RPI Bare Metal OS Initializing from Processor %d.....\n",id);

    // #if RPI_VERSION == 4
    //     uart0_send_string("\tBoard : Raspberry Pi 4\n");
    // #endif

    printf("\nDone with exception level: %d \n",get_el());

    if(id == 0) {
        while (1) {
            uart0_send_char(uart0_read_char());
        }
    } else {
        while(1);
    }
}