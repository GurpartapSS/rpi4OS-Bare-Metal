#include "peripherals/irq.h"
#include "peripherals/aux.h"
#include "utils.h"
#include "entry.h"
#include "printf.h"
#include "mini_uart.h"

const char entry_error_messages[16][32] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void show_invalid_entry_message(u32 type, u64 esr, u64 address) {
    printf("Error Caught %s - %d, ESR: %X, Address: %X\n",entry_error_messages[type], type, esr, address);
}

void enable_interrupt_controller() {
    REGS_IRQ->irq0_enable_0 = AUX_IRQ;
}

void handle_irq() {
    u32 irq;
    irq = REGS_IRQ->irq0_pending_0;
    while (irq)
    {
        if(irq & AUX_IRQ) {
            irq &= ~AUX_IRQ;
            while ((REGS_AUX->mu_iir & 4) == 4)
            {
                printf("UART RECV: ");
                uart_send(uart_recv());
                printf("\n");
                
            }
            
        }
    }
    
}