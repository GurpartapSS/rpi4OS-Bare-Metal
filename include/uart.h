#pragma once

#include "common.h"
#include "peripherals/base.h"

struct UartRegs {
    reg32 DataR;
    reg32 RSRECR;
    reg32 reserved[4];
    reg32 FlagR;
    reg32 reserved1;
    reg32 ILPR;
    reg32 IntBaudRD;
    reg32 FloatBaudRD;
    reg32 LCRH;
    reg32 CR;
    reg32 IFLS;
    reg32 IMSC;
    reg32 RIS;
    reg32 MIS;
    reg32 ICR;
    reg32 DMACR;
    reg32 ITCR;
    reg32 ITIP;
    reg32 ITOP;
    reg32 TDR;
};

#define UART0_OFFSET 0x00201000

#define UART_REGS ((struct UartRegs *)(PBASE + UART0_OFFSET))

void uart0_init();
void uart0_send_char(char s);
void uart0_send_string(char *s);
char uart0_read_char();