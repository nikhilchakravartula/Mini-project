typedef enum
{
    PROCESS_NEW=0,
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_BLOCKED,
    PROCESS_TERMINATED
} process_state_t;

typedef enum
{
    OP_CPU=0,
    OP_IO,
    OP_TERMINATED
} operation_type_t;

typedef struct
{
    operation_type_t type;
    int time;
}op_t;

typedef struct _pcb_t{
   unsigned int pid;
   int priority;
   process_state_t state;
   const char* name;
   //struct _pcb_t* next;
   op_t* current_operation;
   int cpu_id;
}pcb_t;
