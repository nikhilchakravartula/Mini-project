#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "simulator.h"


typedef enum 
{
    CPU_IDLE=0,
    CPU_RUNNING,
    CPU_YIELD,
    CPU_PREEMPT,
    CPU_TERMINATED
}cpu_state_t;

typedef struct
{
    pcb_t* current_pcb;
    cpu_state_t current_state;
    pthread_cond_t wakeup;
    unsigned int idle_time;
    unsigned int busy_time;
    int preemption_timer;

}cpu_data_t;

typedef struct _io_request_t
{
    pcb_t* pcb;
    unsigned int execution_time;
    _io_request_t* next;
}io_request_t;

static io_request_t * io_queue_head=NULL,*io_queue_tail=NULL;
static cpu_data_t* cpus_data;
static pthread_t* cpu_threads;
static pthread_mutex_t simulator_mutex;
static unsigned ready_count=0,running_count=0,blocked_count=0,context_switches_count=0,cpu_count=0,processes_terminated_count=0;

void start_simulator(unsigned number_of_cpus)
{
    int i;
    cpu_count=number_of_cpus;
    cpus_data=malloc(sizeof(cpus_data)*cpu_count);
    cpu_threads=malloc(sizeof(cpu_threads)*cpu_count);
    for(i=0;i<cpu_count;i++)
    {
        cpus_data[i].current_pcb=NULL;
    cpus_data[i].current_state=CPU_IDLE;
    pthread_cond_init(&cpus_data[i].wakeup,NULL);
    cpus_data[i].idle_time=0;
    cpus_data[i].busy_time=0;
    cpus_data[i].preemption_timer=-1;

    }

    for(i=0;i<cpu_count;i++)
    {
        pthread_create(&cpu_threads[i],NULL,simulator_thread_function,(void*)(long)n);


    }
    simulator_supervisor_thread();




}


