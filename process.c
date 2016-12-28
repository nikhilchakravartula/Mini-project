  #include "simulator.h"
#include "process.h"
  static op_t pid0_ops[]={
{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid1_ops[]={
{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid2_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid3_ops[]={
{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid4_ops[]={
{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};

pcb_t processes[] = {
{ 0,PROCESS_NEW, 8,"process1",pid0_ops,10000,0},
{ 1,PROCESS_NEW, 18,"process2",pid1_ops,10000,0},
{ 2,PROCESS_NEW, 11,"process3",pid2_ops,10000,0},
{ 3,PROCESS_NEW, 15,"process4",pid3_ops,10000,0},
{ 4,PROCESS_NEW, 17,"process5",pid4_ops,10000,0}};
