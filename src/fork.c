#include "fork.h"
#include "mm.h"
#include "entry.h"
#include "../include/sched.h"

int copy_process(unsigned long fn, unsigned long arg) {
    preempt_disable();
    task_struct_t *p;

    p = (task_struct_t *)get_free_page();
    if(!p) {
        return 1;
    }
    p->priority = current->priority;
    p->state = current->state;
    p->counter = current->counter;
    p->preempt_count = 1;

    p->cpu_context.x19 =fn;
    p->cpu_context.x20 = arg;
    p->cpu_context.pc = (unsigned long)ret_from_fork;
    p->cpu_context.sp = (unsigned long)p + THREAD_SIZE;
    int pid = nr_tasks++;
    task[pid] = p;
    preempt_enable();
    return 0;
}