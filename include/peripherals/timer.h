#pragma once

#include "peripherals/base.h"
#include "common.h"

#define CLOCKHZ 1000000

struct timer_regs
{
    reg32 control_status;
    reg32 counter_lo; //system counter lower 32 bits 
    reg32 counter_hi; //system counter higher 32 bits
    reg32 compare[4];
};

#define REGS_TIMER ((struct timer_regs *)(PBASE + 0x00030000))