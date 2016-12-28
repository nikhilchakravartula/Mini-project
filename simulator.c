#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif /* __STDC_VERSION__ */

#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "simulator.h"
#include "process.h"
#include"scheduler.h"
#include<assert.h>
#include<pthread.h>

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
   unsigned num_cpu_idle;
 unsigned num_cpu_busy;
    int preemption_timer;

}cpu_data_t;

 typedef struct _io_request_t
{
    pcb_t* pcb;
    unsigned int execution_time;
    struct _io_request_t* next;
}io_request_t;

static io_request_t * io_queue_head=NULL,*io_queue_tail=NULL;
static cpu_data_t* cpus_data;
static pthread_t* cpu_threads;
static pthread_mutex_t simulator_mutex;
static unsigned ready_count=0,running_count=0,context_switches_count=0,cpu_count=0,processes_terminated_count=0;
static unsigned int simulator_time=0,waiting_count=0;


typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t no_writers;
    int writers;
} irwl;

#define IRWL_INIT(i) \
    pthread_mutex_init(&(i).mutex, NULL); \
    pthread_cond_init(&(i).no_writers, NULL); \
    (i).writers = 0;

#define IRWL_READER_LOCK(i) \
    pthread_mutex_lock(&(i).mutex); \
    while ((i).writers > 0) \
    { pthread_cond_wait(&(i).no_writers, &(i).mutex); }

#define IRWL_READER_UNLOCK(i) \
    pthread_mutex_unlock(&(i).mutex);

#define IRWL_WRITER_LOCK(i) \
    pthread_mutex_lock(&(i).mutex); \
    (i).writers++; \
    pthread_mutex_unlock(&(i).mutex);

#define IRWL_WRITER_UNLOCK(i) \
    pthread_mutex_lock(&(i).mutex); \
    (i).writers--; \
    if ((i).writers == 0) \
    { pthread_cond_signal(&(i).no_writers); } \
    pthread_mutex_unlock(&(i).mutex);

static irwl student_lock;




static void *simulator_thread_function(void *data);
static void simulator_supervisor_thread();
static void print_gantt_chart_header();
static void print_gantt_chart_line();
static void print_final_statistics(void);
static void simulate_cpus();
static void simulate_process(unsigned int n,pcb_t* pcb);
static void submit_io_request(pcb_t * pcb);
static void simulate_io();
static void cpu_thread_function(unsigned cpu_id);
static void simulate_create(void);

extern void start_simulator(unsigned number_of_cpus)
{
    int i;
    cpu_count=number_of_cpus;
    cpus_data=malloc(sizeof(cpu_data_t)*cpu_count);
    assert(cpus_data!=NULL);
    cpu_threads=malloc(sizeof(pthread_t)*cpu_count);
   assert(cpu_threads!=NULL);
   simulator_time=0;
   pthread_mutex_init(&simulator_mutex,NULL);
    for(i=0;i<cpu_count;i++)
    {
    cpus_data[i].current_pcb=NULL;
    cpus_data[i].current_state=CPU_IDLE;
    pthread_cond_init(&cpus_data[i].wakeup,NULL);
    cpus_data[i].num_cpu_busy=0;
    cpus_data[i].num_cpu_idle=0;
    cpus_data[i].preemption_timer=-1;

    }
    IRWL_INIT(student_lock);

    for(i=0;i<cpu_count;i++)
    {
	
        pthread_create(&cpu_threads[i],NULL,simulator_thread_function,(void*)(long)i);

    }
    simulator_supervisor_thread();
}

static void simulator_supervisor_thread()
{

    print_gantt_chart_header();

    while(1)
    {
        pthread_mutex_lock(&simulator_mutex);
        if(processes_terminated_count>=PROCESS_COUNT)
        {
            print_final_statistics();
            exit(0);
        }
       

            print_gantt_chart_line();
            simulate_cpus();       
            simulate_io();
            simulate_create();
            simulator_time++;
            pthread_mutex_unlock(&simulator_mutex);
            safe_sleep(1);
        
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
                pcb->vruntime++;
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
/*                    // can suggest optimisation here*/
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
        printf("Scheduled a blocked process : \t%d\n",pcb->pid);
        break;
        case OP_TERMINATED:
        printf("Scheduled a terminated process: \t %d\n",pcb->pid);
        break;
    }


}
static void submit_io_request(pcb_t * pcb)
{
    io_request_t* new_io_request=malloc(sizeof(new_io_request));
    assert(new_io_request!=NULL);
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
        io_queue_tail->next=new_io_request;
io_queue_tail=new_io_request;
    }
}
static void simulate_io()
{
	io_request_t * temp;
pcb_t* pcb;
    if(io_queue_head==NULL)
    return;
/*printf("IN IO EXE TIME IS %u",io_queue_head->execution_time);*/
    if(io_queue_head->execution_time<=0)
    {
                temp=io_queue_head;
        
        temp->pcb->current_operation=(op_t*)(io_queue_head->pcb->current_operation)+1;
pcb=temp->pcb;
        io_queue_head=temp->next;
        if(io_queue_head==NULL)
            io_queue_tail=NULL;
        free(temp);
        pthread_mutex_unlock(&simulator_mutex);
        IRWL_WRITER_LOCK(student_lock);
        wake_up(pcb);
        IRWL_WRITER_UNLOCK(student_lock);
        pthread_mutex_lock(&simulator_mutex);
    }
    else    
    {
        io_queue_head->execution_time-=1;
    }


}
static void cpu_thread_function(unsigned cpu_id)
{

        cpu_state_t state;

    while (1)
    {
        pthread_mutex_lock(&simulator_mutex);
        pthread_cond_signal(&cpus_data[cpu_id].wakeup);

        if (cpus_data[cpu_id].current_pcb == NULL)
        {
            cpus_data[cpu_id].current_state = CPU_IDLE;
        }
        else
        {
            cpus_data[cpu_id].current_state = CPU_RUNNING;

            while (cpus_data[cpu_id].current_state == CPU_RUNNING)
                pthread_cond_wait(&cpus_data[cpu_id].wakeup,
                    &simulator_mutex);
        }
        state = cpus_data[cpu_id].current_state;
        pthread_mutex_unlock(&simulator_mutex);

        switch (state)
        {
        case CPU_IDLE:
          
            idle(cpu_id);
            break;

        case CPU_PREEMPT:
            IRWL_WRITER_LOCK(student_lock);
            preempt(cpu_id);
            IRWL_WRITER_UNLOCK(student_lock);
            break;

        case CPU_YIELD:
            IRWL_WRITER_LOCK(student_lock);
            yield(cpu_id);
            IRWL_WRITER_UNLOCK(student_lock);
            break;

        case CPU_TERMINATED:
            pthread_mutex_lock(&simulator_mutex);
            processes_terminated_count++;
            pthread_mutex_unlock(&simulator_mutex);
            IRWL_WRITER_LOCK(student_lock);
            terminate(cpu_id);
            IRWL_WRITER_UNLOCK(student_lock);
            break;

        case CPU_RUNNING:
            break;
        }
    }
}
static void print_gantt_chart_header()
{
    int n;
    printf("Time  Ru Re Wa     ");
    for (n=0; n<cpu_count; n++)
        printf(" CPU %d   ", n);
    printf("     < I/O Queue <\n"
           "===== == == ==     ");
    for (n=0; n<cpu_count; n++)
        printf(" ========");
    printf("     =============\n");
}


static void print_gantt_chart_line()
{
io_request_t *r;
    unsigned int current_ready = 0, current_running = 0, current_waiting = 0;
    int n;
    IRWL_READER_LOCK(student_lock)
    for (n=0; n<PROCESS_COUNT; n++)
    {
        switch(processes[n].state)
        {
        case PROCESS_READY:
            current_ready++;
            ready_count++;
            break;

        case PROCESS_RUNNING:
            current_running++;
            running_count++;
            break;

        case PROCESS_BLOCKED:
            current_waiting++;
            waiting_count++;
            break;

        default:
            break;
        }
    }
    IRWL_READER_UNLOCK(student_lock)
    printf("%-5.1f %-2d %-2d %-2d     ", (float)simulator_time / 10.0,
        current_running, current_ready, current_waiting);
    for (n=0; n<cpu_count; n++)
    {
        if (cpus_data[n].current_pcb != NULL)
        {
            
            printf(" %-8s", cpus_data[n].current_pcb->name);
            pthread_mutex_unlock(&simulator_mutex);
            cpus_data[n].num_cpu_busy++;
            pthread_mutex_lock(&simulator_mutex);
        }
        else{
            printf(" (IDLE)  ");
            pthread_mutex_unlock(&simulator_mutex);
            cpus_data[n].num_cpu_idle++;
            pthread_mutex_lock(&simulator_mutex);
          
        }
	/*printQueues();
	printf("\nover one time***************************\n");*/
    }
    printf("     <");
    r = io_queue_head;
    while (r != NULL)
    {
        printf(" %s", r->pcb->name);
        r = r->next;
    }
    printf(" <\n");
}

static void print_final_statistics(void)
{
    int i;
    printf("\n\n");
    printf("# of Context Switches: %u\n", context_switches_count);
    printf("Total execution time: %.1f s\n", (float)simulator_time / 10.0);
    printf("Total time spent in READY state: %.1f s\n", (float)ready_count / 10.0);
    printf("Processor utilisation details: ");
    for(i=0;i<cpu_count;i++)
    {
        printf("Core %d\t\t",i);

    }
    printf("\n\n======================================================================\n\n");
    for(i=0;i<cpu_count;i++)
    {
        printf("Utilisation: %.2f%%\t", 100*(cpus_data[i].num_cpu_busy)/((float)cpus_data[i].num_cpu_idle+cpus_data[i].num_cpu_busy));
    }
printf("\n");
print_migration_details();

}

extern void context_switch(unsigned int cpu_id, pcb_t *pcb,
                           int preemption_time)
{
      assert(cpu_id < cpu_count);
    assert(pcb == NULL || (pcb >= processes && pcb <= processes +
        PROCESS_COUNT - 1));
	if(pcb!=NULL)
    context_switches_count++;
    IRWL_WRITER_UNLOCK(student_lock);
    pthread_mutex_lock(&simulator_mutex);
	cpus_data[cpu_id].current_pcb = pcb;
    cpus_data[cpu_id].preemption_timer = preemption_time;
    pthread_mutex_unlock(&simulator_mutex);
    IRWL_WRITER_LOCK(student_lock);
}

extern void force_preempt(unsigned int cpu_id)
{
    assert(cpu_id<cpu_count);
    IRWL_WRITER_UNLOCK(student_lock);
    pthread_mutex_lock(&simulator_mutex);
    if (cpus_data[cpu_id].current_state == CPU_RUNNING)
    {
	cpus_data[cpu_id].current_state = CPU_PREEMPT;
        pthread_cond_signal(&cpus_data[cpu_id].wakeup);
        pthread_cond_wait(&cpus_data[cpu_id].wakeup,&simulator_mutex);
    }
    pthread_mutex_unlock(&simulator_mutex);
    IRWL_WRITER_LOCK(student_lock);
}

static void simulate_create(void)
{
    static int processes_created = 0;

    if ((simulator_time % 10) == 0 && processes_created < PROCESS_COUNT)
    {
        pthread_mutex_unlock(&simulator_mutex);
        IRWL_WRITER_LOCK(student_lock);
        wake_up(&processes[processes_created]);
        IRWL_WRITER_UNLOCK(student_lock);
        pthread_mutex_lock(&simulator_mutex);      
processes_created++;
    }
}


static void *simulator_thread_function(void *data)
{
    cpu_thread_function((int)(long)data);
    return NULL;
}


extern void safe_sleep(unsigned long usec)
{
    struct timespec ts;
    ts.tv_sec = usec / 1000000;
    ts.tv_nsec = (usec % 1000000) * 1000;

   while (nanosleep(&ts, &ts) != 0);
}



