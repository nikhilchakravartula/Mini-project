#ifndef __SIMULATOR_H__

#define __SIMULATOR_H__

typedef enum {
PROCESS_NEW=0,
PROCESS_READY,
PROCESS_RUNNING,
PROCESS_BLOCKED,
PROCESS_TERMINATED

} process_state_t;

typedef enum{
OP_CPU=0,
OP_IO,
OP_TERMINATED

} operation_type_t;

typedef struct 
{
    operation_type_t type;
    int time;
    
}op_t;

typedef struct
{
   
    unsigned int pid;
    process_state_t state;  
     int priority;
    const char* name;
    op_t* current_operation;
    unsigned prev_cpu_id;
    unsigned vruntime;

}pcb_t;

extern void start_simulator(unsigned int number_of_cpus);

extern void context_switch(unsigned int cpu_id,pcb_t* pcb,int preemption_time);

extern void force_preemption(unsigned int cpu_id);

extern void safe_sleep(unsigned long seconds );


#endif 
