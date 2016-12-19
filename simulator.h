#ifdef __SIMULATOR_H__

#define __SIMULATOR_H__

typedef enum {
NEW=0,
READY,
RUNNING,
BLOCKED,
TERMINATED

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

typedef struct _pcb_t
{
     
    unsigned int pid;
    process_state_t state;
    const int priority;
    const char* name;
    struct _pcb_t* next;
    op_t current_operation;
    long int prev_cpu_id;
    long int prev_cpu_group;
    unsigned long v_runtime;

}pcb_t;

extern void start_simulator(unsigned int number_of_cpus);

extern void context_switch(unsigned int cpu_id,pcb_t* pcb,int preemption_time);

extern void force_preemption(unsigned int cpu_id);

extern void safe_sleep(unsigned long seconds );


#endif // 