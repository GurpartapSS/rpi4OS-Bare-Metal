#include "../include/sched.h"
#include "irq.h"
#include "printf.h"

static task_struct_t init_task = INIT_TASK;
task_struct_t *current = &(init_task); //will always point to currently running task
task_struct_t *task[NR_TASKS] = {&(init_task)};
int nr_tasks = 1; //number of currently running tasks 

void preempt_disable(void) {
    current->preempt_count++;
}

void preempt_enable(void) {
    current->preempt_count--;
}

void schedule_tail(void) {
    preempt_enable();
}

void _schedule(void) {
    preempt_disable();
    int next, c;
    task_struct_t *p;
    while(1) {
        c = -1;
        next = 0;
        for (int i = 0; i < NR_TASKS; i++) {
            p = task[i];
            if(p && p->state == TASK_RUNNING && p->counter > c) {
                c = p->counter;
                next = i;
            }
        }
        if(c) {
            break;
        }
        for (int i = 0; i < NR_TASKS; i++) {
            p = task[i];
            if(p) {
                p->counter = (p->counter >> 1) + p->priority;
            }
        }
    }

    switch_to(task[next]);
    preempt_enable();
}

void schedule(void) {       
    current->counter = 0;
    _schedule();
}

void switch_to(task_struct_t *next) {
    if(current == next) {
        return;
    }
    task_struct_t *prev = current;
    current = next;
    cpu_switch_to(prev, next);

}