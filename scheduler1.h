#define NOQ 3
#include <stdbool.h>
#include "process.h"

void initialise_queue(struct Queue** queue);
bool placeInQueue(pcb_t *p);
schedule_next_process();
void print_disks();
void dispatch_process(pcb_t *p);
int find_idlest_core(int flag);
int get_group_id(int cpu_id);
int find_idlest_core_group(int group_id);
extern void wake_up(pcb_t *process);
static void schedule(unsigned int cpu_id);




