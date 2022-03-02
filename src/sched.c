#include "../include/sched.h"
#include "irq.h"
#include "printf.h"

static task_struct_t init_task = INIT_TASK;
task_struct_t *current = &(init_task); //will always point to currently running task
task_struct_t *task[NR_TASKS] = {&(init_task)};
int nr_task = 1; //number of currently running tasks 

void preempt_disable(void) {
    current->preempt_count++;
}

void preempt_enable(void) {
    current->preempt_count--;
}

void schedule_tail(void) {
    preempt_enable();
}

void schedule(void) {
    preempt_disable();
    int next, c;
    task_struct_t *p;
    while(1) {
        c = -1;
        next = 0;

    }
}