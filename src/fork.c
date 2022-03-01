#include "fork.h"
#include "mm.h"
#include "../include/sched.h"

int copy_process(unsigned long fn, unsigned long arg) {
    preempt_disable();
    task_struct_t *p;

    p = (task_struct_t *)get_free_page();
    
    return 0;
}