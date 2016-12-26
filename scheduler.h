#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include"simulator.h"

extern void idle(unsigned int cpu_id);
extern void preempt(unsigned int cpu_id);
extern void yield(unsigned int cpu_id);
extern void terminate(unsigned int cpu_id);
extern void wake_up(pcb_t *process);
extern void printQueues();
#endif
