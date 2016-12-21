#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#define N 20

int main()
{
  pcb_t proc[N];
  int i;
  srand(time(NULL));
  for(i=0;i<N;i++){
     proc[i].pid = i+1;
     proc[i].priority = (unsigned int)rand()%20;
     proc[i].cpu_id = -1;
     proc[i].state = PROCESS_NEW;
     proc[i].current_operation = (op_t*)malloc(sizeof(op_t));
     proc[i].current_operation->time = 1+rand()% 15;
     proc[i].current_operation->type = OP_CPU;
     }

  struct Queue* queue[NOQ];
  for(i=0;i<NOQ;i++)
        queue[i] = createQueue();

  for(i=0;i<N;i++)
    printf("%d\t%d\n",proc[i].pid,proc[i].priority);

  printf("\n\n\n");

  initialise_queue(queue);

  for(i=0;i<N;i++)
    wake_up(&proc[i]);

  schedule_next_process();

 /* for(i=0;i<NOQ;i++){
    printQueue(queue[i]);
    printf("\n\n");
    }*/



  return 0;
}
