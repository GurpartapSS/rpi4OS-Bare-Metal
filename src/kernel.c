#include "common.h"
#include "mini_uart.h"
#include "printf.h"
#include "uart.h"

// u32 get_el();

// void putc(void *p, char c) {
//     if(c == '\n') {
//         uart_send('\r');
//     }

//     uart_send(c);
// }

void kernel_main() {
    uart0_init();
    // uart_init();
    // init_printf(0, putc);
    // printf("Printing RPI Bare Metal OS Initializing .....\n");
    uart("RPI Bare Metal OS Initializing UART.....\n");

    #if RPI_VERSION == 4
        // uart_send_string("\tBoard : Raspberry Pi 4\n");
        uart0_send_string("\tBoard : Raspberry Pi 4\n");
    #endif

    // printf("\nDone with exception level: %d \n",get_el());

    while (1) {
        // uart_send(uart_recv());
        uart0_send_char(uart0_read_char());
    }
}