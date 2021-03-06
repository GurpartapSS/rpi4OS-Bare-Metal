#include "peripherals/timer.h"
#include "peripherals/irq.h"
#include "printf.h"
#include "timer.h"

const u32 interval_1 = CLOCKHZ; //interrupt every 1 second

const u32 interval_3 = CLOCKHZ / 4; //interrupt every 1 second

u32 curr_val_1 = 0;
u32 curr_val_3 = 0;

void timer_init() {
    curr_val_1 = REGS_TIMER->counter_lo;
    curr_val_1 += interval_1; //interval after which we want interrupt based on curent timer value
    REGS_TIMER->compare[1] = curr_val_1;

    curr_val_3 = REGS_TIMER->counter_lo;
    curr_val_3 += interval_3; //interval after which we want interrupt based on curent timer value
    REGS_TIMER->compare[3] = curr_val_3;
}

void handle_timer_1() {
    curr_val_1 += interval_1;
    REGS_TIMER->compare[1] = curr_val_1;
    REGS_TIMER->control_status |= SYS_TIMER_IRQ_1;

    printf("Timer 1 received\n");
}

void handle_timer_3() {
    curr_val_3 += interval_3;
    REGS_TIMER->compare[3] = curr_val_3;
    REGS_TIMER->control_status |= SYS_TIMER_IRQ_3;

    printf("Timer 3 received\n");
}

u64 timer_get_ticks() {
    u32 timer_hi = REGS_TIMER->counter_hi;
    u32 timer_lo = REGS_TIMER->counter_lo;

    if (timer_hi != REGS_TIMER->counter_hi) {
        timer_hi = REGS_TIMER->counter_hi;
        timer_lo = REGS_TIMER->counter_lo;
    }

    return ((u64)timer_hi << 32) | timer_lo ;
}

void timer_sleep(u32 ms) {
    u64 start_time = timer_get_ticks();

    while((start_time + (ms *1000)) > timer_get_ticks());
}