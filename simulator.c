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

static void start_simulator(unsigned number_of_cpus)
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
        pthread_create(&cpu_threads[i],NULL,simulator_thread_function,(void*)(long)i);
    }
    simulator_supervisor_thread();
}

static void simulator_supervisor_thread()
{

    while(1)
    {
        pthread_mutex_lock(&simulator_mutex);
        if(processes_terminated_count>PROCESS_COUNT)
        {
            print_final_statistics();
            exit(0);
        }
        else
        {

            simulate_cpus();
            simulate_io();
            simulate_create();
            simulator_time++;
            pthread_mutex_unlock(&simulator_mutex);
            safe_sleep(1);
        }
    }

}
static void simulate_cpus()
{
    int i;
    for(i=0;i<cpu_count;i++)
    {
        if(cpus_data[i].current_pcb!=NULL)
        simulate_process(i,cpus_data[i].current_pcb);
    }
}
static void simulate_process(unsigned int n,pcb_t* pcb)
{
    op_t* pc=(op_t*)pcb->current_operation;
    switch(pc->type)
    {
        case OP_CPU:
            if(pc->time>0)
            {
                pc->time--;
                cpus_data[n].preemption_timer--;
                if(cpus_data[n].preemption_timer==0)
                {
                    cpus_data[n].current_state=CPU_PREEMPT;
                    pthread_cond_signal(&cpus_data[n].wakeup);
                    pthread_cond_wait(&cpus_data[n].wakeup,&simulator_mutex);
                }
            }
            else
            {
                pcb->current_operation=(op_t*)(pcb->current_operation)+1;
                pc++;
                switch(pc->type)
                {
                    case OP_CPU:
                    break;

                    case OP_IO:
                    // can suggest optimisation here
                    submit_io_request(pcb);
                    cpus_data[n].current_state=CPU_YIELD;
                    pthread_cond_signal(&cpus_data[n].wakeup);
                    pthread_cond_wait(&cpus_data[n].wakeup,&simulator_mutex);

                    break;
                    case OP_TERMINATED:
                    cpus_data[n].current_state=CPU_TERMINATED;
                    pthread_cond_signal(&cpus_data[n].wakeup);
                    pthread_cond_wait(&cpus_data[n].wakeup,&simulator_mutex);

                    break;

                }


            }

        break;
        case OP_IO:
        printf("Scheduled a blocked process : \t%d",pcb->pid);
        break;
        case OP_TERMINATED:
        printf("Scheduled a terminated process: \t %d",pcb->pid);
        break;
    }


}
void submit_io_request(pcb_t * pcb)
{
    io_request_t* new_io_request=malloc(sizeof(new_io_request));
    new_io_request->execution_time=pcb->current_operation->time;
    new_io_request->pcb=pcb;
    new_io_request->next=NULL;
    if(io_queue_tail==NULL)
    {
        io_queue_tail=new_io_request;
        io_queue_head=new_io_request;
    }
    else
    {
        new_io_request->next=io_queue_head;
        io_queue_head=new_io_request;
    }
}
void simulate_io()
{
    if(io_queue_head==NULL)
    return;

    if(io_queue_head->execution_time<=0)
    {
        pcb_t* pcb;
        pcb=io_queue_head->pcb;
        io_queue_head->pcb->current_operation=(op_t*)(io_queue_head->pcb->current_operation)+1;
        io_request_t * temp=io_queue_head;
        io_queue_head=io_queue_head->next;
        if(io_queue_head==NULL)
            io_queue_tail=NULL;
        free(temp);
        pthread_mutex_unlock(&simulator_mutex);
        wake_up(pcb);
        pthread_mutex_lock(&simulator_mutex);
    }
    else
    {
        io_queue_head->execution_time-=1;
    }


}


