

#include "simulator.h"
#include<math.h>
#define priority(i) 20
#define PROCESS_COUNT 8




static op_t pid0_ops[] = {
    { OP_CPU, 2 },
    { OP_IO, 2 },
    { OP_CPU, 3 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 2 },
    { OP_CPU, 3 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 2 },
    { OP_CPU, 3 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 2 },
    { OP_CPU, 3 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_TERMINATED, 0 }
};

static op_t pid1_ops[] = {
    { OP_CPU, 3 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 6 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 4 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 6 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 4 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 6 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 4 },
    { OP_IO, 3 },
    { OP_CPU, 4 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 6 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 4 },
    { OP_TERMINATED, 0 }
};

static op_t pid2_ops[] = {
    { OP_CPU, 1 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 3 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 3 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 3 },
    { OP_IO, 4 },
    { OP_CPU, 2 },
    { OP_IO, 5 },
    { OP_CPU, 1 },
    { OP_IO, 3 },
    { OP_CPU, 3 },
    { OP_TERMINATED, 0 }
};

static op_t pid3_ops[] = {
    { OP_CPU, 9 },
    { OP_IO, 1 },
    { OP_CPU, 6 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_IO, 1 },
    { OP_CPU, 7 },
    { OP_IO, 1 },
    { OP_CPU, 6 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_IO, 1 },
    { OP_CPU, 7 },
    { OP_IO, 1 },
    { OP_CPU, 6 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_TERMINATED, 0 }
};

static op_t pid4_ops[] = {
    { OP_CPU, 10 }, 
    { OP_IO, 1 },
    { OP_CPU, 14 },
    { OP_IO, 1 },
    { OP_CPU, 7 },
    { OP_IO, 2 },
    { OP_CPU, 11 },
    { OP_IO, 1 },
    { OP_CPU, 14 },
    { OP_IO, 1 },
    { OP_CPU, 7 },
    { OP_IO, 2 },
    { OP_CPU, 11 },
    { OP_IO, 1 },
    { OP_CPU, 14 },
    { OP_IO, 1 },
    { OP_CPU, 7 },
    { OP_IO, 2 },
    { OP_CPU, 11 },
    { OP_TERMINATED, 0 }
};

static op_t pid5_ops[] = {
    { OP_CPU, 9 }, 
    { OP_IO, 1 },
    { OP_CPU, 10 },
    { OP_IO, 2 },
    { OP_CPU, 15 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_IO, 1 },
    { OP_CPU, 10 },
    { OP_IO, 2 },
    { OP_CPU, 15 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_IO, 1 },
    { OP_CPU, 10 },
    { OP_IO, 2 },
    { OP_CPU, 15 },
    { OP_IO, 1 },
    { OP_CPU, 8 },
    { OP_TERMINATED, 0 }
};

static op_t pid6_ops[] = {
    { OP_CPU, 6 }, 
    { OP_IO, 3 },
    { OP_CPU, 9 },
    { OP_IO, 1 },
    { OP_CPU, 14 },
    { OP_IO, 1 },
    { OP_CPU, 11 },
    { OP_IO, 3 },
    { OP_CPU, 9 },
    { OP_IO, 1 },
    { OP_CPU, 14 },
    { OP_IO, 1 },
    { OP_CPU, 11 },
    { OP_IO, 3 },
    { OP_CPU, 9 },
    { OP_IO, 1 },
    { OP_CPU, 14 },
    { OP_IO, 1 },
    { OP_CPU, 11 },
    { OP_TERMINATED, 0 }
};

static op_t pid7_ops[] = {
    { OP_CPU, 6 }, 
    { OP_IO, 3 },
    { OP_CPU, 12 },
    { OP_IO, 3 },
    { OP_CPU, 7 },
    { OP_IO, 1 },
    { OP_CPU, 9 },
    { OP_IO, 3 },
    { OP_CPU, 12 },
    { OP_IO, 3 },
    { OP_CPU, 7 },
    { OP_IO, 1 },
    { OP_CPU, 9 },
    { OP_IO, 3 },
    { OP_CPU, 12 },
    { OP_IO, 3 },
    { OP_CPU, 7 },
    { OP_IO, 1 },
    { OP_CPU, 9 },
    { OP_TERMINATED, 0 }
};

static pcb_t processes[PROCESS_COUNT] = {
    { 0,PROCESS_NEW, priority(1),"Process1",pid0_ops,-1,0},
	{ 1,PROCESS_NEW, priority(1),"Process2",pid1_ops,-1,0},
	{ 2,PROCESS_NEW, priority(1),"Process3",pid2_ops,-1,0},
	{ 3,PROCESS_NEW, priority(1),"Process4",pid3_ops,-1,0},
	{ 4,PROCESS_NEW, priority(1),"Process5",pid4_ops,-1,0},
	{ 5,PROCESS_NEW, priority(1),"Process6",pid5_ops,-1,0},
	{ 6,PROCESS_NEW, priority(1),"Process7",pid6_ops,-1,0},
	{ 7,PROCESS_NEW, priority(1),"Process8",pid7_ops,-1,0}
};


