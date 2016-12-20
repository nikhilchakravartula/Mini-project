//write the scheduler here
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include "simulator.h"
 
static pthread_mutex_t ready_queue_mutex;
static pthread_cond_t cpu_not_idle;
static void preempt(unsigned cpu_id)
{
pthread_mutex_lock(&ready_queue_mutex);
pcb_t* pcb=//ready queue member of cpuid
pcb->state=PROCESS_READY;
//ADDTOTHEREADYQUEUE(cpu_id);
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);
}


static void idle(unsigned cpu_id)
{
pthread_mutex_lock(&ready_queue_mutex);
while(HEADOFTHEREADYQUEUE ==NULL)
pthread_cond_wait(&cpu_not_idle,&ready_queue_mutex);
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);

}

static void yield(unsigned cpu_id)
{
    pthread_mutex_lock(&ready_queue_mutex);
pcb_t* pcb=//ready queue member of cpuid
pcb->state=PROCESS_BLOCKED;
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);


}

static void terminate(unsigned cpu_id)
{
pthread_mutex_lock(&ready_queue_mutex);
pcb_t* pcb=//ready queue member of cpuid
pcb->state=PROCESS_TERMINATED;
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);


}

static void schedule(unsigned cpu_id)
{


}


int main(int argc,char** argv)
{


    unsigned num_cpus=atoi(argv[1]);
    pthread_mutex_init(&ready_queue_mutex,NULL);
    pthread_cond_init(&cpu_not_idle,NULL);

    start_simulator(num_cpus);

}