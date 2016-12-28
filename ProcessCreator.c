#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "scheduler.h"
#define MAX_OP_COUNT 25
#define MAX_BURST_TIME 10
#define MAX_IO_TIME 10

int *processes1;

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
    processes1 = malloc(sizeof(int)*n);

    for(i=0; i<n; i++){
        processes[i].pid = i;
        processes[i].state = PROCESS_NEW;
        processes[i].priority = rand()%20;
        pname = malloc(15);
        num = malloc(5);
        strcpy(pname,"process");
        sprintf(num,"%d",i+1);
        strcat(pname, num);
        processes[i].name = pname;
        processes[i].prev_cpu_id = 10000;
        processes[i].vruntime = 0;
        num_ops = 1+rand()%MAX_OP_COUNT;
        if(num_ops&1)num_ops+=1;
        processes1[i]=num_ops+2;
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

printf("  #include \"simulator.h\"\n#include \"process.h\"\n  ");


for(i=0;i<n;i++)
{
   printf("static op_t pid%d_ops[]={",i);
    for(j=0;j<processes1[i]-1;j++)
    {

        printf("\n{%s , %d},\n",printEnum(process[i].current_operation[j].type),process[i].current_operation[j].time);

    }
	printf("\n{%s , %d}};\n",printEnum(process[i].current_operation[j].type),process[i].current_operation[j].time);

}

printf("\npcb_t processes[] = {\n");

for(i=0;i<n-1;i++)
{
   
	printf("{ %d,PROCESS_NEW, %d,\"%s\",pid%d_ops,10000,0,0},\n",process[i].pid,process[i].priority,process[i].name,i);

}
printf("{ %d,PROCESS_NEW, %d,\"%s\",pid%d_ops,10000,0,0}};\n",process[i].pid,process[i].priority,process[i].name,i);



}
int main(int argc,char** argv)
{
	if(argc<2){printf("WHAT HAVE U SENT!\n");
	exit(0);}
	int n=atoi(argv[1]);
    pcb_t* processes=create_processes(n);
    printprocesses(processes,n);
  return 0;
}
