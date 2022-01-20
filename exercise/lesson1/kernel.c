#include "common.h"
#include "mini_uart.h"
#include "printf.h"
// #include "uart.h"
#include"utils.h"

static int is_uart_init = 0;

void putc(void *p, char c) {
    if(c == '\n') {
        uart_send('\r');
    }

    uart_send(c);
}

void kernel_main(int id) {
    if(id == 0) {
        uart0_init();
        init_printf(0, putc);
        printf("Printing RPI Bare Metal OS Initializing .....\n");
        is_uart_init = 1;
    }
    while(is_uart_init == 0);
    delay(id * 10000000);

    #if RPI_VERSION == 4
        uart0_send_string("\tBoard : Raspberry Pi 4\n");
    #endif

    printf("\nDone with from processor: %d \n",id);

    if(id == 0)
    {
        while (1) {
        uart0_send_char(uart0_read_char());
        }
    }
    else {
        while(1);
    }
}