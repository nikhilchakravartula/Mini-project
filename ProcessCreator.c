#include <stdio.h>
#include <stdlib.h>
#include "scheduler1.h"
#define MAX_OP_COUNT 25
#define MAX_BURST_TIME 10
#define MAX_IO_TIME 10

operation_type_t get_operation(int flag){
    if(flag == 0)
        return OP_CPU;
    else
        return OP_IO;
}

extern op_t* new_operation(int n){
    int i, flag;
    op_t* operations;
    operations = malloc(sizeof(op_t)*(n+2));


    flag = 0;
    for(i=0; i<n; i++){
        operations[i].type = get_operation(flag);
        operations[i].time = 1+rand()%MAX_BURST_TIME;
        if(flag == 0)
            flag = 1;
        else
            flag = 0;
    }
    operations[i].type=OP_CPU;
    operations[i].time=1+rand()%MAX_BURST_TIME;
    operations[i+1].type = OP_TERMINATED;
    operations[i+1].time = 0;
    return operations;
}

extern pcb_t* create_processes(int n){
    int i;
    char *pname;
    char *num;
    int num_ops;
    pcb_t *processes;
    srand(time(NULL));
    processes = malloc(sizeof(pcb_t)*n);
    for(i=0; i<n; i++){
        processes[i].pid = i;
        processes[i].state = PROCESS_NEW;
        processes[i].priority = 1+rand()%20;
        pname = malloc(15);
        num = malloc(5);
        strcpy(pname,"process");
        itoa(i+1,num,10);
        strcat(pname, num);
        processes[i].name = pname;
        processes[i].prev_cpu_id = 10000;
        processes[i].vruntime = 0;
        num_ops = 1+rand()%MAX_OP_COUNT;
        if(num_ops&1)num_ops+=1;
        processes[i].num_ops=num_ops+2;
        processes[i].current_operation = new_operation(num_ops);
    }
    return processes;
}
char* printEnum(int v)
{

    switch(v)
    {
        case 0:return "OP_CPU";
        case 1:return "OP_IO";
        case 2:return "OP_TERMINATED";
        default: return "INVALID_OP";
    }
}
void printprocesses(pcb_t * process,int n)
{
int i;
int j;
for(i=0;i<n;i++)
{
    printf("\n%s %d prio:%d state:%d\n",process[i].name,process[i].pid,process[i].priority,process[i].state);
    for(j=0;j<process[i].num_ops;j++)
    {

        printf("\n{%s %d}\n",printEnum(process[i].current_operation[j].type),process[i].current_operation[j].time);

    }

}


}
int main()
{/*
  pcb_t proc[N];
  int i;
  srand(time(NULL));
  struct Queue *que = createQueue();
  for(i=0;i<5;i++){
     proc[i].pid = i+1;
     proc[i].priority = (unsigned int)rand()%20;
     proc[i].cpu_id = -1;
     proc[i].state = PROCESS_NEW;
     proc[i].current_operation = (op_t*)malloc(sizeof(op_t));
     proc[i].current_operation->time = 1+rand()% 15;
     proc[i].current_operation->type = OP_CPU;
     proc[i].vruntime = rand()%20;
     sorted_enqueue(que,&proc[i]);
     printQueue(que);
     }
     deQueueAtFront(que);
     printQueue(que);
     deQueueAtFront(que);
     printQueue(que);
     deQueueAtRear(que);
     printQueue(que);
     deQueueAtRear(que);
     printQueue(que);

/*
  struct Queue* queue[NOQ];
  for(i=0;i<NOQ;i++)
        queue[i] = createQueue();


  for(i=0;i<N;i++)
    printf("%d\t%d\n",proc[i].pid,proc[i].priority);

  printf("\n\n\n");

  initialise_disks_queue();

  for(i=0;i<N;i++)
    wake_up(&proc[i]);

  schedule_next_process();

 /* for(i=0;i<NOQ;i++){
    printQueue(queue[i]);
    printf("\n\n");
    }*/

int n;
scanf("%d",&n);
    pcb_t* processes=create_processes(n);
    printprocesses(processes,n);
  return 0;
}
