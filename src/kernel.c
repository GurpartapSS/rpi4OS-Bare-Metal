#include "common.h"
#include "mini_uart.h"
#include "printf.h"
#include "irq.h"
#include "timer.h"

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
    uart_send_string("RPI Bare Metal OS Initializing .....\n");

    irq_init_vectors();
    enable_interrupt_controller();
    irq_enable();
    timer_init();
    

    #if RPI_VERSION == 4
        uart_send_string("\tBoard : Raspberry Pi 4\n");
    #endif

    printf("\nDone with exception level: %d \n",get_el());

    //testing sleep function
    printf("sleeping for 2 Sec ...\n");
    timer_sleep(2000); 
    printf("sleeping for 5 Sec ...\n");
    timer_sleep(5000);


    while (1) {
        // uart_send(uart_recv());
    }
}