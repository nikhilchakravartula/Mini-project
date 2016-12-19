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
    print_gantt_chart_header();

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
            print_gantt_chart_line();
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
void cpu_thread_function(unsigned cpu_id)
{

        cpu_state_t state;

    while (1)
    {
        pthread_mutex_lock(&simulator_mutex);
        pthread_cond_signal(&simulator_cpu_data[cpu_id].wakeup);

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
            preempt(cpu_id);
            break;

        case CPU_YIELD:
            yield(cpu_id);
            break;

        case CPU_TERMINATE:
            pthread_mutex_lock(&simulator_mutex);
            processes_terminated++;
            pthread_mutex_unlock(&simulator_mutex);
            terminate(cpu_id);
            break;

        case CPU_RUNNING:
            break;
        }
    }
}
void print_gantt_chart_header()
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


void print_gantt_chart_line()
{
io_request *r;
    unsigned int current_ready = 0, current_running = 0, current_waiting = 0;
    int n;
    IRWL_READER_LOCK(student_lock)
    for (n=0; n<PROCESS_COUNT; n++)
    {
        switch(processes[n].current_state)
        {
        case PROCESS_READY:
            current_ready++;
            ready_counter++;
            break;

        case PROCESS_RUNNING:
            current_running++;
            running_counter++;
            break;

        case PROCESS_WAITING:
            current_waiting++;
            waiting_counter++;
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
            printf(" %-8s", cpus_data[n].current->name);
        else
            printf(" (IDLE)  ");
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

static void print_final_stats(void)
{
    printf("\n\n");
    printf("# of Context Switches: %u\n", context_switches);
    printf("Total execution time: %.1f s\n", (float)simulator_time / 10.0);
    printf("Total time spent in READY state: %.1f s\n", (float)ready_counter / 10.0);
}

extern void context_switch(unsigned int cpu_id, pcb_t *pcb,
                           int preemption_time)
{
    context_switches_count++;
    IRWL_WRITER_UNLOCK(student_lock);
    pthread_mutex_lock(&simulator_mutex);
    simulator_cpu_data[cpu_id].current_pcb = pcb;
    simulator_cpu_data[cpu_id].preemption_timer = preemption_time;
    pthread_mutex_unlock(&simulator_mutex);
    IRWL_WRITER_LOCK(student_lock);
}

extern void force_preempt(unsigned int cpu_id)
{
    IRWL_WRITER_UNLOCK(student_lock);
    pthread_mutex_lock(&simulator_mutex);
    if (simulator_cpu_data[cpu_id].current_state == CPU_RUNNING)
    {
        simulator_cpu_data[cpu_id].current_state = CPU_PREEMPT;
        pthread_cond_signal(&simulator_cpu_data[cpu_id].wakeup);
        pthread_cond_wait(&simulator_cpu_data[cpu_id].wakeup,&simulator_mutex);
    }
    pthread_mutex_unlock(&simulator_mutex);
    IRWL_WRITER_LOCK(student_lock);
}

static void simulate_creat(void)
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



