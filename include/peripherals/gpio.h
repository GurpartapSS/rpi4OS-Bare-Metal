#pragma once 

#include "common.h"

#include "peripherals/base.h"

typedef struct _GpioPinData
{
    reg32 reserved;
    reg32 data[2];
}GpioPinData;

struct GpioRegs
{
    reg32 func_select[6];
    GpioPinData output_set;
    GpioPinData output_clear;
    GpioPinData level;
    GpioPinData ev_detect_status;
    GpioPinData re_detect_enable;
    GpioPinData fe_detect_enable;
    GpioPinData hi_detect_enable;
    GpioPinData lo_detect_enable;
    GpioPinData async_re_detect;
    GpioPinData async_fe_detect;
    reg32 reserved;
    reg32 pupd_enable;
    reg32 pupd_enable_clocks[2];
};

#define REGS_GPIO ((struct GpioRegs *)(PBASE + 0x00200000))

