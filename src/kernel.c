#include "common.h"
#include "mini_uart.h"
#include "printf.h"
#include "irq.h"
#include "timer.h"
#include "i2c.h"

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
    timer_sleep(500); 

    printf("Initializing I2c ..");
    i2c_init();

    for (int i = 0; i< 10;i++) {
        char buffer[10];
        i2c_recv(,buffer,9);
        buffer[9] = 0;

        printf("Received: %s\n",buffer);

        timer_sleep(250);
    }

    while (1) {
        // uart_send(uart_recv());
    }
}