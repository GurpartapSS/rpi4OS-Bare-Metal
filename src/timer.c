#include "peripherals/timer.h"
#include "peripherals/irq.h"
#include "printf.h"
#include "timer.h"

const u32 interval_1 = CLOCKHZ; //interrupt every 1 second
u32 curr_val_1 = 0;

void timer_init() {
    curr_val_1 = REGS_TIMER->counter_lo;
    curr_val_1 += interval_1; //interval after which we want interrupt based on curent timer value
    REGS_TIMER->compare[1] = curr_val_1;
}

void handle_timer_1() {
    curr_val_1 += interval_1;
    REGS_TIMER->compare[1] = curr_val_1;
    REGS_TIMER->control_status |= SYS_TIMER_IRQ_1;

    printf("Timer 1 received");
}