  #include "simulator.h"
#include "process.h"
  static op_t pid0_ops[]={
{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid1_ops[]={
{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid2_ops[]={
{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid3_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid4_ops[]={
{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid5_ops[]={
{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid6_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid7_ops[]={
{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid8_ops[]={
{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid9_ops[]={
{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_TERMINATED , 0}};

pcb_t processes[] = {
{ 0,PROCESS_NEW, 10,"process1",pid0_ops,10000,0},
{ 1,PROCESS_NEW, 6,"process2",pid1_ops,10000,0},
{ 2,PROCESS_NEW, 12,"process3",pid2_ops,10000,0},
{ 3,PROCESS_NEW, 18,"process4",pid3_ops,10000,0},
{ 4,PROCESS_NEW, 19,"process5",pid4_ops,10000,0},
{ 5,PROCESS_NEW, 19,"process6",pid5_ops,10000,0},
{ 6,PROCESS_NEW, 9,"process7",pid6_ops,10000,0},
{ 7,PROCESS_NEW, 5,"process8",pid7_ops,10000,0},
{ 8,PROCESS_NEW, 10,"process9",pid8_ops,10000,0},
{ 9,PROCESS_NEW, 10,"process10",pid9_ops,10000,0}};
