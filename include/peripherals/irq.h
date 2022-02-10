#pragma once

#include "base.h"
#include "common.h"

enum vc_irqs {
    SYS_TIMER_IRQ_0 = 1,
    SYS_TIMER_IRQ_1 = (1 << 1),
    SYS_TIMER_IRQ_2 = (1 << 2),
    SYS_TIMER_IRQ_3 = (1 << 3),
    AUX_IRQ = (1 << 29)
};

typedef struct arm_irq_regs {
    reg32 irq0_pending_0;
    reg32 irq0_pending_1;
    reg32 irq0_pending_2;
    reg32 res0;
    reg32 irq0_enable_0;
    reg32 irq0_enable_1;
    reg32 irq0_enable_2;
    reg32 res1;
    reg32 irq0_disable_0;
    reg32 irq0_disable_1;
    reg32 irq0_disable_2;
} arm_irq_regs;

#define REGS_IRQ ((arm_irq_regs *)(PBASE + 0x0000B200))