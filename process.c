  #include "simulator.h"
#include "process.h"
  static op_t pid0_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid1_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid2_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid3_ops[]={
{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid4_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid5_ops[]={
{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid6_ops[]={
{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid7_ops[]={
{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid8_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid9_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid10_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid11_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid12_ops[]={
{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid13_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid14_ops[]={
{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid15_ops[]={
{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid16_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid17_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid18_ops[]={
{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid19_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid20_ops[]={
{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid21_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid22_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid23_ops[]={
{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid24_ops[]={
{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid25_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid26_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid27_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid28_ops[]={
{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid29_ops[]={
{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid30_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid31_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid32_ops[]={
{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid33_ops[]={
{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid34_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid35_ops[]={
{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid36_ops[]={
{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid37_ops[]={
{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid38_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid39_ops[]={
{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid40_ops[]={
{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid41_ops[]={
{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid42_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid43_ops[]={
{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid44_ops[]={
{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid45_ops[]={
{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid46_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid47_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid48_ops[]={
{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid49_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid50_ops[]={
{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid51_ops[]={
{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid52_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid53_ops[]={
{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid54_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid55_ops[]={
{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid56_ops[]={
{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid57_ops[]={
{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid58_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid59_ops[]={
{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid60_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid61_ops[]={
{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid62_ops[]={
{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid63_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid64_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid65_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid66_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid67_ops[]={
{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid68_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid69_ops[]={
{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid70_ops[]={
{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid71_ops[]={
{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid72_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid73_ops[]={
{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid74_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid75_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid76_ops[]={
{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid77_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid78_ops[]={
{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid79_ops[]={
{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid80_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid81_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid82_ops[]={
{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid83_ops[]={
{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid84_ops[]={
{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid85_ops[]={
{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid86_ops[]={
{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid87_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid88_ops[]={
{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid89_ops[]={
{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid90_ops[]={
{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid91_ops[]={
{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid92_ops[]={
{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid93_ops[]={
{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid94_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid95_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid96_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid97_ops[]={
{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid98_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid99_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid100_ops[]={
{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid101_ops[]={
{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid102_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid103_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid104_ops[]={
{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid105_ops[]={
{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid106_ops[]={
{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid107_ops[]={
{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid108_ops[]={
{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid109_ops[]={
{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid110_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid111_ops[]={
{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid112_ops[]={
{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid113_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid114_ops[]={
{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid115_ops[]={
{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid116_ops[]={
{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid117_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid118_ops[]={
{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid119_ops[]={
{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid120_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid121_ops[]={
{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid122_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid123_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid124_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid125_ops[]={
{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid126_ops[]={
{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid127_ops[]={
{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid128_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid129_ops[]={
{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid130_ops[]={
{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid131_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid132_ops[]={
{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid133_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid134_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid135_ops[]={
{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid136_ops[]={
{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid137_ops[]={
{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid138_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid139_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid140_ops[]={
{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid141_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid142_ops[]={
{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid143_ops[]={
{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid144_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid145_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid146_ops[]={
{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid147_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid148_ops[]={
{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid149_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid150_ops[]={
{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid151_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid152_ops[]={
{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid153_ops[]={
{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid154_ops[]={
{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid155_ops[]={
{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid156_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid157_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid158_ops[]={
{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid159_ops[]={
{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid160_ops[]={
{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid161_ops[]={
{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid162_ops[]={
{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid163_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid164_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid165_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid166_ops[]={
{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid167_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid168_ops[]={
{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid169_ops[]={
{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid170_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid171_ops[]={
{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid172_ops[]={
{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid173_ops[]={
{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid174_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid175_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid176_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid177_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid178_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid179_ops[]={
{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid180_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid181_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid182_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid183_ops[]={
{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid184_ops[]={
{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid185_ops[]={
{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid186_ops[]={
{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid187_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid188_ops[]={
{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid189_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid190_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid191_ops[]={
{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid192_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid193_ops[]={
{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid194_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid195_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid196_ops[]={
{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid197_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid198_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid199_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid200_ops[]={
{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid201_ops[]={
{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid202_ops[]={
{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid203_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid204_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid205_ops[]={
{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid206_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid207_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid208_ops[]={
{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid209_ops[]={
{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid210_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid211_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid212_ops[]={
{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid213_ops[]={
{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid214_ops[]={
{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid215_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid216_ops[]={
{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid217_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid218_ops[]={
{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid219_ops[]={
{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid220_ops[]={
{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid221_ops[]={
{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid222_ops[]={
{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid223_ops[]={
{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid224_ops[]={
{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid225_ops[]={
{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid226_ops[]={
{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid227_ops[]={
{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid228_ops[]={
{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid229_ops[]={
{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid230_ops[]={
{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid231_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid232_ops[]={
{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid233_ops[]={
{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid234_ops[]={
{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid235_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid236_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid237_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid238_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid239_ops[]={
{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid240_ops[]={
{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid241_ops[]={
{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid242_ops[]={
{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid243_ops[]={
{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid244_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid245_ops[]={
{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid246_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid247_ops[]={
{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid248_ops[]={
{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid249_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid250_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid251_ops[]={
{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid252_ops[]={
{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid253_ops[]={
{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid254_ops[]={
{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid255_ops[]={
{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid256_ops[]={
{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid257_ops[]={
{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid258_ops[]={
{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid259_ops[]={
{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid260_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid261_ops[]={
{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid262_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid263_ops[]={
{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid264_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid265_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid266_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid267_ops[]={
{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid268_ops[]={
{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid269_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid270_ops[]={
{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid271_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid272_ops[]={
{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid273_ops[]={
{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid274_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid275_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid276_ops[]={
{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid277_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid278_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid279_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid280_ops[]={
{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid281_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid282_ops[]={
{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid283_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid284_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid285_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid286_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid287_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid288_ops[]={
{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid289_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid290_ops[]={
{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid291_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid292_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid293_ops[]={
{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid294_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid295_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid296_ops[]={
{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid297_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid298_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid299_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid300_ops[]={
{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid301_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid302_ops[]={
{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid303_ops[]={
{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid304_ops[]={
{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid305_ops[]={
{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid306_ops[]={
{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid307_ops[]={
{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid308_ops[]={
{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid309_ops[]={
{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid310_ops[]={
{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid311_ops[]={
{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid312_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid313_ops[]={
{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid314_ops[]={
{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid315_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid316_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid317_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid318_ops[]={
{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid319_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid320_ops[]={
{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid321_ops[]={
{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid322_ops[]={
{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid323_ops[]={
{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid324_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid325_ops[]={
{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid326_ops[]={
{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid327_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid328_ops[]={
{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid329_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid330_ops[]={
{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid331_ops[]={
{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid332_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid333_ops[]={
{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid334_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid335_ops[]={
{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid336_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid337_ops[]={
{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid338_ops[]={
{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid339_ops[]={
{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid340_ops[]={
{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid341_ops[]={
{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid342_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid343_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid344_ops[]={
{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid345_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid346_ops[]={
{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid347_ops[]={
{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid348_ops[]={
{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid349_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid350_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid351_ops[]={
{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid352_ops[]={
{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid353_ops[]={
{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid354_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid355_ops[]={
{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid356_ops[]={
{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid357_ops[]={
{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid358_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid359_ops[]={
{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid360_ops[]={
{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid361_ops[]={
{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid362_ops[]={
{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid363_ops[]={
{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid364_ops[]={
{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid365_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid366_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid367_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid368_ops[]={
{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid369_ops[]={
{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid370_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid371_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid372_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid373_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid374_ops[]={
{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid375_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid376_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid377_ops[]={
{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid378_ops[]={
{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid379_ops[]={
{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid380_ops[]={
{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid381_ops[]={
{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid382_ops[]={
{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid383_ops[]={
{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid384_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid385_ops[]={
{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid386_ops[]={
{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid387_ops[]={
{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid388_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid389_ops[]={
{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid390_ops[]={
{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid391_ops[]={
{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid392_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid393_ops[]={
{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid394_ops[]={
{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid395_ops[]={
{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid396_ops[]={
{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid397_ops[]={
{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid398_ops[]={
{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid399_ops[]={
{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid400_ops[]={
{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid401_ops[]={
{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid402_ops[]={
{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid403_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid404_ops[]={
{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid405_ops[]={
{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid406_ops[]={
{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid407_ops[]={
{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid408_ops[]={
{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid409_ops[]={
{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid410_ops[]={
{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid411_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid412_ops[]={
{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid413_ops[]={
{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid414_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid415_ops[]={
{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid416_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid417_ops[]={
{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid418_ops[]={
{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid419_ops[]={
{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid420_ops[]={
{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid421_ops[]={
{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid422_ops[]={
{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid423_ops[]={
{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid424_ops[]={
{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid425_ops[]={
{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid426_ops[]={
{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid427_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid428_ops[]={
{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid429_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid430_ops[]={
{OP_CPU , 5},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid431_ops[]={
{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid432_ops[]={
{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid433_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid434_ops[]={
{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid435_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid436_ops[]={
{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid437_ops[]={
{OP_CPU , 8},

{OP_IO , 10},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid438_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid439_ops[]={
{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid440_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid441_ops[]={
{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid442_ops[]={
{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid443_ops[]={
{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid444_ops[]={
{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid445_ops[]={
{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid446_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid447_ops[]={
{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid448_ops[]={
{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid449_ops[]={
{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid450_ops[]={
{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid451_ops[]={
{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid452_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid453_ops[]={
{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid454_ops[]={
{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid455_ops[]={
{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid456_ops[]={
{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid457_ops[]={
{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid458_ops[]={
{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid459_ops[]={
{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid460_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid461_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid462_ops[]={
{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid463_ops[]={
{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid464_ops[]={
{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid465_ops[]={
{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid466_ops[]={
{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid467_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 2},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid468_ops[]={
{OP_CPU , 3},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid469_ops[]={
{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid470_ops[]={
{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 9},

{OP_TERMINATED , 0}};
static op_t pid471_ops[]={
{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid472_ops[]={
{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 5},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid473_ops[]={
{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 1},

{OP_CPU , 6},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid474_ops[]={
{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 2},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid475_ops[]={
{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 2},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 7},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid476_ops[]={
{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 4},

{OP_TERMINATED , 0}};
static op_t pid477_ops[]={
{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 7},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid478_ops[]={
{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid479_ops[]={
{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 7},

{OP_IO , 9},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid480_ops[]={
{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 4},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid481_ops[]={
{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid482_ops[]={
{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 5},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid483_ops[]={
{OP_CPU , 7},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 5},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 10},

{OP_CPU , 6},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 6},

{OP_IO , 4},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid484_ops[]={
{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 3},

{OP_TERMINATED , 0}};
static op_t pid485_ops[]={
{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid486_ops[]={
{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 10},

{OP_IO , 10},

{OP_CPU , 2},

{OP_IO , 9},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid487_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 7},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid488_ops[]={
{OP_CPU , 8},

{OP_IO , 1},

{OP_CPU , 1},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid489_ops[]={
{OP_CPU , 6},

{OP_IO , 2},

{OP_CPU , 10},

{OP_IO , 7},

{OP_CPU , 1},

{OP_IO , 1},

{OP_CPU , 7},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 2},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 4},

{OP_CPU , 8},

{OP_IO , 5},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid490_ops[]={
{OP_CPU , 9},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 3},

{OP_IO , 1},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid491_ops[]={
{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 9},

{OP_IO , 4},

{OP_CPU , 9},

{OP_IO , 1},

{OP_CPU , 9},

{OP_IO , 7},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 6},

{OP_CPU , 6},

{OP_TERMINATED , 0}};
static op_t pid492_ops[]={
{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 8},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 2},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 5},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 3},

{OP_CPU , 5},

{OP_TERMINATED , 0}};
static op_t pid493_ops[]={
{OP_CPU , 9},

{OP_IO , 8},

{OP_CPU , 4},

{OP_IO , 7},

{OP_CPU , 9},

{OP_IO , 9},

{OP_CPU , 8},

{OP_TERMINATED , 0}};
static op_t pid494_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 8},

{OP_IO , 3},

{OP_CPU , 1},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 3},

{OP_IO , 3},

{OP_CPU , 9},

{OP_IO , 5},

{OP_CPU , 10},

{OP_IO , 2},

{OP_CPU , 9},

{OP_IO , 6},

{OP_CPU , 1},

{OP_TERMINATED , 0}};
static op_t pid495_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 2},

{OP_IO , 10},

{OP_CPU , 2},

{OP_TERMINATED , 0}};
static op_t pid496_ops[]={
{OP_CPU , 10},

{OP_IO , 5},

{OP_CPU , 8},

{OP_IO , 9},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 4},

{OP_IO , 5},

{OP_CPU , 5},

{OP_IO , 6},

{OP_CPU , 4},

{OP_IO , 10},

{OP_CPU , 10},

{OP_IO , 4},

{OP_CPU , 4},

{OP_IO , 1},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid497_ops[]={
{OP_CPU , 7},

{OP_IO , 8},

{OP_CPU , 1},

{OP_IO , 9},

{OP_CPU , 5},

{OP_IO , 7},

{OP_CPU , 8},

{OP_IO , 2},

{OP_CPU , 6},

{OP_IO , 8},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 1},

{OP_IO , 4},

{OP_CPU , 2},

{OP_IO , 8},

{OP_CPU , 10},

{OP_TERMINATED , 0}};
static op_t pid498_ops[]={
{OP_CPU , 3},

{OP_IO , 6},

{OP_CPU , 9},

{OP_IO , 10},

{OP_CPU , 7},

{OP_TERMINATED , 0}};
static op_t pid499_ops[]={
{OP_CPU , 8},

{OP_IO , 4},

{OP_CPU , 6},

{OP_IO , 3},

{OP_CPU , 5},

{OP_IO , 4},

{OP_CPU , 10},

{OP_IO , 6},

{OP_CPU , 2},

{OP_IO , 5},

{OP_CPU , 4},

{OP_TERMINATED , 0}};

pcb_t processes[] = {
{ 0,PROCESS_NEW, 17,"process1",pid0_ops,10000,0},
{ 1,PROCESS_NEW, 8,"process2",pid1_ops,10000,0},
{ 2,PROCESS_NEW, 16,"process3",pid2_ops,10000,0},
{ 3,PROCESS_NEW, 10,"process4",pid3_ops,10000,0},
{ 4,PROCESS_NEW, 7,"process5",pid4_ops,10000,0},
{ 5,PROCESS_NEW, 11,"process6",pid5_ops,10000,0},
{ 6,PROCESS_NEW, 9,"process7",pid6_ops,10000,0},
{ 7,PROCESS_NEW, 9,"process8",pid7_ops,10000,0},
{ 8,PROCESS_NEW, 0,"process9",pid8_ops,10000,0},
{ 9,PROCESS_NEW, 2,"process10",pid9_ops,10000,0},
{ 10,PROCESS_NEW, 4,"process11",pid10_ops,10000,0},
{ 11,PROCESS_NEW, 13,"process12",pid11_ops,10000,0},
{ 12,PROCESS_NEW, 8,"process13",pid12_ops,10000,0},
{ 13,PROCESS_NEW, 19,"process14",pid13_ops,10000,0},
{ 14,PROCESS_NEW, 15,"process15",pid14_ops,10000,0},
{ 15,PROCESS_NEW, 11,"process16",pid15_ops,10000,0},
{ 16,PROCESS_NEW, 2,"process17",pid16_ops,10000,0},
{ 17,PROCESS_NEW, 0,"process18",pid17_ops,10000,0},
{ 18,PROCESS_NEW, 6,"process19",pid18_ops,10000,0},
{ 19,PROCESS_NEW, 3,"process20",pid19_ops,10000,0},
{ 20,PROCESS_NEW, 9,"process21",pid20_ops,10000,0},
{ 21,PROCESS_NEW, 4,"process22",pid21_ops,10000,0},
{ 22,PROCESS_NEW, 2,"process23",pid22_ops,10000,0},
{ 23,PROCESS_NEW, 6,"process24",pid23_ops,10000,0},
{ 24,PROCESS_NEW, 15,"process25",pid24_ops,10000,0},
{ 25,PROCESS_NEW, 14,"process26",pid25_ops,10000,0},
{ 26,PROCESS_NEW, 8,"process27",pid26_ops,10000,0},
{ 27,PROCESS_NEW, 3,"process28",pid27_ops,10000,0},
{ 28,PROCESS_NEW, 3,"process29",pid28_ops,10000,0},
{ 29,PROCESS_NEW, 18,"process30",pid29_ops,10000,0},
{ 30,PROCESS_NEW, 14,"process31",pid30_ops,10000,0},
{ 31,PROCESS_NEW, 6,"process32",pid31_ops,10000,0},
{ 32,PROCESS_NEW, 13,"process33",pid32_ops,10000,0},
{ 33,PROCESS_NEW, 3,"process34",pid33_ops,10000,0},
{ 34,PROCESS_NEW, 2,"process35",pid34_ops,10000,0},
{ 35,PROCESS_NEW, 13,"process36",pid35_ops,10000,0},
{ 36,PROCESS_NEW, 17,"process37",pid36_ops,10000,0},
{ 37,PROCESS_NEW, 8,"process38",pid37_ops,10000,0},
{ 38,PROCESS_NEW, 3,"process39",pid38_ops,10000,0},
{ 39,PROCESS_NEW, 14,"process40",pid39_ops,10000,0},
{ 40,PROCESS_NEW, 13,"process41",pid40_ops,10000,0},
{ 41,PROCESS_NEW, 19,"process42",pid41_ops,10000,0},
{ 42,PROCESS_NEW, 8,"process43",pid42_ops,10000,0},
{ 43,PROCESS_NEW, 7,"process44",pid43_ops,10000,0},
{ 44,PROCESS_NEW, 10,"process45",pid44_ops,10000,0},
{ 45,PROCESS_NEW, 4,"process46",pid45_ops,10000,0},
{ 46,PROCESS_NEW, 13,"process47",pid46_ops,10000,0},
{ 47,PROCESS_NEW, 18,"process48",pid47_ops,10000,0},
{ 48,PROCESS_NEW, 1,"process49",pid48_ops,10000,0},
{ 49,PROCESS_NEW, 13,"process50",pid49_ops,10000,0},
{ 50,PROCESS_NEW, 2,"process51",pid50_ops,10000,0},
{ 51,PROCESS_NEW, 15,"process52",pid51_ops,10000,0},
{ 52,PROCESS_NEW, 8,"process53",pid52_ops,10000,0},
{ 53,PROCESS_NEW, 14,"process54",pid53_ops,10000,0},
{ 54,PROCESS_NEW, 6,"process55",pid54_ops,10000,0},
{ 55,PROCESS_NEW, 1,"process56",pid55_ops,10000,0},
{ 56,PROCESS_NEW, 1,"process57",pid56_ops,10000,0},
{ 57,PROCESS_NEW, 5,"process58",pid57_ops,10000,0},
{ 58,PROCESS_NEW, 7,"process59",pid58_ops,10000,0},
{ 59,PROCESS_NEW, 12,"process60",pid59_ops,10000,0},
{ 60,PROCESS_NEW, 16,"process61",pid60_ops,10000,0},
{ 61,PROCESS_NEW, 12,"process62",pid61_ops,10000,0},
{ 62,PROCESS_NEW, 17,"process63",pid62_ops,10000,0},
{ 63,PROCESS_NEW, 5,"process64",pid63_ops,10000,0},
{ 64,PROCESS_NEW, 13,"process65",pid64_ops,10000,0},
{ 65,PROCESS_NEW, 2,"process66",pid65_ops,10000,0},
{ 66,PROCESS_NEW, 16,"process67",pid66_ops,10000,0},
{ 67,PROCESS_NEW, 5,"process68",pid67_ops,10000,0},
{ 68,PROCESS_NEW, 8,"process69",pid68_ops,10000,0},
{ 69,PROCESS_NEW, 13,"process70",pid69_ops,10000,0},
{ 70,PROCESS_NEW, 13,"process71",pid70_ops,10000,0},
{ 71,PROCESS_NEW, 19,"process72",pid71_ops,10000,0},
{ 72,PROCESS_NEW, 2,"process73",pid72_ops,10000,0},
{ 73,PROCESS_NEW, 17,"process74",pid73_ops,10000,0},
{ 74,PROCESS_NEW, 10,"process75",pid74_ops,10000,0},
{ 75,PROCESS_NEW, 15,"process76",pid75_ops,10000,0},
{ 76,PROCESS_NEW, 18,"process77",pid76_ops,10000,0},
{ 77,PROCESS_NEW, 7,"process78",pid77_ops,10000,0},
{ 78,PROCESS_NEW, 18,"process79",pid78_ops,10000,0},
{ 79,PROCESS_NEW, 16,"process80",pid79_ops,10000,0},
{ 80,PROCESS_NEW, 10,"process81",pid80_ops,10000,0},
{ 81,PROCESS_NEW, 7,"process82",pid81_ops,10000,0},
{ 82,PROCESS_NEW, 19,"process83",pid82_ops,10000,0},
{ 83,PROCESS_NEW, 10,"process84",pid83_ops,10000,0},
{ 84,PROCESS_NEW, 10,"process85",pid84_ops,10000,0},
{ 85,PROCESS_NEW, 11,"process86",pid85_ops,10000,0},
{ 86,PROCESS_NEW, 9,"process87",pid86_ops,10000,0},
{ 87,PROCESS_NEW, 18,"process88",pid87_ops,10000,0},
{ 88,PROCESS_NEW, 7,"process89",pid88_ops,10000,0},
{ 89,PROCESS_NEW, 8,"process90",pid89_ops,10000,0},
{ 90,PROCESS_NEW, 6,"process91",pid90_ops,10000,0},
{ 91,PROCESS_NEW, 12,"process92",pid91_ops,10000,0},
{ 92,PROCESS_NEW, 10,"process93",pid92_ops,10000,0},
{ 93,PROCESS_NEW, 12,"process94",pid93_ops,10000,0},
{ 94,PROCESS_NEW, 3,"process95",pid94_ops,10000,0},
{ 95,PROCESS_NEW, 13,"process96",pid95_ops,10000,0},
{ 96,PROCESS_NEW, 1,"process97",pid96_ops,10000,0},
{ 97,PROCESS_NEW, 7,"process98",pid97_ops,10000,0},
{ 98,PROCESS_NEW, 0,"process99",pid98_ops,10000,0},
{ 99,PROCESS_NEW, 3,"process100",pid99_ops,10000,0},
{ 100,PROCESS_NEW, 9,"process101",pid100_ops,10000,0},
{ 101,PROCESS_NEW, 15,"process102",pid101_ops,10000,0},
{ 102,PROCESS_NEW, 7,"process103",pid102_ops,10000,0},
{ 103,PROCESS_NEW, 14,"process104",pid103_ops,10000,0},
{ 104,PROCESS_NEW, 9,"process105",pid104_ops,10000,0},
{ 105,PROCESS_NEW, 0,"process106",pid105_ops,10000,0},
{ 106,PROCESS_NEW, 18,"process107",pid106_ops,10000,0},
{ 107,PROCESS_NEW, 8,"process108",pid107_ops,10000,0},
{ 108,PROCESS_NEW, 12,"process109",pid108_ops,10000,0},
{ 109,PROCESS_NEW, 3,"process110",pid109_ops,10000,0},
{ 110,PROCESS_NEW, 6,"process111",pid110_ops,10000,0},
{ 111,PROCESS_NEW, 4,"process112",pid111_ops,10000,0},
{ 112,PROCESS_NEW, 4,"process113",pid112_ops,10000,0},
{ 113,PROCESS_NEW, 19,"process114",pid113_ops,10000,0},
{ 114,PROCESS_NEW, 2,"process115",pid114_ops,10000,0},
{ 115,PROCESS_NEW, 19,"process116",pid115_ops,10000,0},
{ 116,PROCESS_NEW, 4,"process117",pid116_ops,10000,0},
{ 117,PROCESS_NEW, 8,"process118",pid117_ops,10000,0},
{ 118,PROCESS_NEW, 19,"process119",pid118_ops,10000,0},
{ 119,PROCESS_NEW, 17,"process120",pid119_ops,10000,0},
{ 120,PROCESS_NEW, 16,"process121",pid120_ops,10000,0},
{ 121,PROCESS_NEW, 9,"process122",pid121_ops,10000,0},
{ 122,PROCESS_NEW, 15,"process123",pid122_ops,10000,0},
{ 123,PROCESS_NEW, 4,"process124",pid123_ops,10000,0},
{ 124,PROCESS_NEW, 17,"process125",pid124_ops,10000,0},
{ 125,PROCESS_NEW, 7,"process126",pid125_ops,10000,0},
{ 126,PROCESS_NEW, 2,"process127",pid126_ops,10000,0},
{ 127,PROCESS_NEW, 19,"process128",pid127_ops,10000,0},
{ 128,PROCESS_NEW, 10,"process129",pid128_ops,10000,0},
{ 129,PROCESS_NEW, 0,"process130",pid129_ops,10000,0},
{ 130,PROCESS_NEW, 15,"process131",pid130_ops,10000,0},
{ 131,PROCESS_NEW, 1,"process132",pid131_ops,10000,0},
{ 132,PROCESS_NEW, 3,"process133",pid132_ops,10000,0},
{ 133,PROCESS_NEW, 2,"process134",pid133_ops,10000,0},
{ 134,PROCESS_NEW, 18,"process135",pid134_ops,10000,0},
{ 135,PROCESS_NEW, 5,"process136",pid135_ops,10000,0},
{ 136,PROCESS_NEW, 13,"process137",pid136_ops,10000,0},
{ 137,PROCESS_NEW, 3,"process138",pid137_ops,10000,0},
{ 138,PROCESS_NEW, 2,"process139",pid138_ops,10000,0},
{ 139,PROCESS_NEW, 6,"process140",pid139_ops,10000,0},
{ 140,PROCESS_NEW, 1,"process141",pid140_ops,10000,0},
{ 141,PROCESS_NEW, 1,"process142",pid141_ops,10000,0},
{ 142,PROCESS_NEW, 7,"process143",pid142_ops,10000,0},
{ 143,PROCESS_NEW, 8,"process144",pid143_ops,10000,0},
{ 144,PROCESS_NEW, 6,"process145",pid144_ops,10000,0},
{ 145,PROCESS_NEW, 6,"process146",pid145_ops,10000,0},
{ 146,PROCESS_NEW, 8,"process147",pid146_ops,10000,0},
{ 147,PROCESS_NEW, 1,"process148",pid147_ops,10000,0},
{ 148,PROCESS_NEW, 11,"process149",pid148_ops,10000,0},
{ 149,PROCESS_NEW, 4,"process150",pid149_ops,10000,0},
{ 150,PROCESS_NEW, 7,"process151",pid150_ops,10000,0},
{ 151,PROCESS_NEW, 10,"process152",pid151_ops,10000,0},
{ 152,PROCESS_NEW, 7,"process153",pid152_ops,10000,0},
{ 153,PROCESS_NEW, 3,"process154",pid153_ops,10000,0},
{ 154,PROCESS_NEW, 13,"process155",pid154_ops,10000,0},
{ 155,PROCESS_NEW, 0,"process156",pid155_ops,10000,0},
{ 156,PROCESS_NEW, 10,"process157",pid156_ops,10000,0},
{ 157,PROCESS_NEW, 4,"process158",pid157_ops,10000,0},
{ 158,PROCESS_NEW, 0,"process159",pid158_ops,10000,0},
{ 159,PROCESS_NEW, 13,"process160",pid159_ops,10000,0},
{ 160,PROCESS_NEW, 8,"process161",pid160_ops,10000,0},
{ 161,PROCESS_NEW, 6,"process162",pid161_ops,10000,0},
{ 162,PROCESS_NEW, 13,"process163",pid162_ops,10000,0},
{ 163,PROCESS_NEW, 7,"process164",pid163_ops,10000,0},
{ 164,PROCESS_NEW, 4,"process165",pid164_ops,10000,0},
{ 165,PROCESS_NEW, 17,"process166",pid165_ops,10000,0},
{ 166,PROCESS_NEW, 16,"process167",pid166_ops,10000,0},
{ 167,PROCESS_NEW, 4,"process168",pid167_ops,10000,0},
{ 168,PROCESS_NEW, 11,"process169",pid168_ops,10000,0},
{ 169,PROCESS_NEW, 13,"process170",pid169_ops,10000,0},
{ 170,PROCESS_NEW, 11,"process171",pid170_ops,10000,0},
{ 171,PROCESS_NEW, 11,"process172",pid171_ops,10000,0},
{ 172,PROCESS_NEW, 11,"process173",pid172_ops,10000,0},
{ 173,PROCESS_NEW, 10,"process174",pid173_ops,10000,0},
{ 174,PROCESS_NEW, 7,"process175",pid174_ops,10000,0},
{ 175,PROCESS_NEW, 0,"process176",pid175_ops,10000,0},
{ 176,PROCESS_NEW, 9,"process177",pid176_ops,10000,0},
{ 177,PROCESS_NEW, 14,"process178",pid177_ops,10000,0},
{ 178,PROCESS_NEW, 4,"process179",pid178_ops,10000,0},
{ 179,PROCESS_NEW, 15,"process180",pid179_ops,10000,0},
{ 180,PROCESS_NEW, 17,"process181",pid180_ops,10000,0},
{ 181,PROCESS_NEW, 17,"process182",pid181_ops,10000,0},
{ 182,PROCESS_NEW, 9,"process183",pid182_ops,10000,0},
{ 183,PROCESS_NEW, 17,"process184",pid183_ops,10000,0},
{ 184,PROCESS_NEW, 15,"process185",pid184_ops,10000,0},
{ 185,PROCESS_NEW, 12,"process186",pid185_ops,10000,0},
{ 186,PROCESS_NEW, 6,"process187",pid186_ops,10000,0},
{ 187,PROCESS_NEW, 19,"process188",pid187_ops,10000,0},
{ 188,PROCESS_NEW, 16,"process189",pid188_ops,10000,0},
{ 189,PROCESS_NEW, 13,"process190",pid189_ops,10000,0},
{ 190,PROCESS_NEW, 0,"process191",pid190_ops,10000,0},
{ 191,PROCESS_NEW, 12,"process192",pid191_ops,10000,0},
{ 192,PROCESS_NEW, 18,"process193",pid192_ops,10000,0},
{ 193,PROCESS_NEW, 3,"process194",pid193_ops,10000,0},
{ 194,PROCESS_NEW, 0,"process195",pid194_ops,10000,0},
{ 195,PROCESS_NEW, 19,"process196",pid195_ops,10000,0},
{ 196,PROCESS_NEW, 19,"process197",pid196_ops,10000,0},
{ 197,PROCESS_NEW, 18,"process198",pid197_ops,10000,0},
{ 198,PROCESS_NEW, 5,"process199",pid198_ops,10000,0},
{ 199,PROCESS_NEW, 5,"process200",pid199_ops,10000,0},
{ 200,PROCESS_NEW, 14,"process201",pid200_ops,10000,0},
{ 201,PROCESS_NEW, 18,"process202",pid201_ops,10000,0},
{ 202,PROCESS_NEW, 15,"process203",pid202_ops,10000,0},
{ 203,PROCESS_NEW, 10,"process204",pid203_ops,10000,0},
{ 204,PROCESS_NEW, 2,"process205",pid204_ops,10000,0},
{ 205,PROCESS_NEW, 5,"process206",pid205_ops,10000,0},
{ 206,PROCESS_NEW, 14,"process207",pid206_ops,10000,0},
{ 207,PROCESS_NEW, 16,"process208",pid207_ops,10000,0},
{ 208,PROCESS_NEW, 14,"process209",pid208_ops,10000,0},
{ 209,PROCESS_NEW, 18,"process210",pid209_ops,10000,0},
{ 210,PROCESS_NEW, 16,"process211",pid210_ops,10000,0},
{ 211,PROCESS_NEW, 14,"process212",pid211_ops,10000,0},
{ 212,PROCESS_NEW, 2,"process213",pid212_ops,10000,0},
{ 213,PROCESS_NEW, 5,"process214",pid213_ops,10000,0},
{ 214,PROCESS_NEW, 12,"process215",pid214_ops,10000,0},
{ 215,PROCESS_NEW, 1,"process216",pid215_ops,10000,0},
{ 216,PROCESS_NEW, 1,"process217",pid216_ops,10000,0},
{ 217,PROCESS_NEW, 8,"process218",pid217_ops,10000,0},
{ 218,PROCESS_NEW, 14,"process219",pid218_ops,10000,0},
{ 219,PROCESS_NEW, 4,"process220",pid219_ops,10000,0},
{ 220,PROCESS_NEW, 6,"process221",pid220_ops,10000,0},
{ 221,PROCESS_NEW, 9,"process222",pid221_ops,10000,0},
{ 222,PROCESS_NEW, 9,"process223",pid222_ops,10000,0},
{ 223,PROCESS_NEW, 7,"process224",pid223_ops,10000,0},
{ 224,PROCESS_NEW, 17,"process225",pid224_ops,10000,0},
{ 225,PROCESS_NEW, 13,"process226",pid225_ops,10000,0},
{ 226,PROCESS_NEW, 4,"process227",pid226_ops,10000,0},
{ 227,PROCESS_NEW, 3,"process228",pid227_ops,10000,0},
{ 228,PROCESS_NEW, 3,"process229",pid228_ops,10000,0},
{ 229,PROCESS_NEW, 6,"process230",pid229_ops,10000,0},
{ 230,PROCESS_NEW, 16,"process231",pid230_ops,10000,0},
{ 231,PROCESS_NEW, 16,"process232",pid231_ops,10000,0},
{ 232,PROCESS_NEW, 0,"process233",pid232_ops,10000,0},
{ 233,PROCESS_NEW, 3,"process234",pid233_ops,10000,0},
{ 234,PROCESS_NEW, 14,"process235",pid234_ops,10000,0},
{ 235,PROCESS_NEW, 10,"process236",pid235_ops,10000,0},
{ 236,PROCESS_NEW, 19,"process237",pid236_ops,10000,0},
{ 237,PROCESS_NEW, 4,"process238",pid237_ops,10000,0},
{ 238,PROCESS_NEW, 8,"process239",pid238_ops,10000,0},
{ 239,PROCESS_NEW, 15,"process240",pid239_ops,10000,0},
{ 240,PROCESS_NEW, 1,"process241",pid240_ops,10000,0},
{ 241,PROCESS_NEW, 10,"process242",pid241_ops,10000,0},
{ 242,PROCESS_NEW, 6,"process243",pid242_ops,10000,0},
{ 243,PROCESS_NEW, 6,"process244",pid243_ops,10000,0},
{ 244,PROCESS_NEW, 2,"process245",pid244_ops,10000,0},
{ 245,PROCESS_NEW, 14,"process246",pid245_ops,10000,0},
{ 246,PROCESS_NEW, 12,"process247",pid246_ops,10000,0},
{ 247,PROCESS_NEW, 10,"process248",pid247_ops,10000,0},
{ 248,PROCESS_NEW, 16,"process249",pid248_ops,10000,0},
{ 249,PROCESS_NEW, 15,"process250",pid249_ops,10000,0},
{ 250,PROCESS_NEW, 5,"process251",pid250_ops,10000,0},
{ 251,PROCESS_NEW, 10,"process252",pid251_ops,10000,0},
{ 252,PROCESS_NEW, 18,"process253",pid252_ops,10000,0},
{ 253,PROCESS_NEW, 14,"process254",pid253_ops,10000,0},
{ 254,PROCESS_NEW, 8,"process255",pid254_ops,10000,0},
{ 255,PROCESS_NEW, 9,"process256",pid255_ops,10000,0},
{ 256,PROCESS_NEW, 17,"process257",pid256_ops,10000,0},
{ 257,PROCESS_NEW, 16,"process258",pid257_ops,10000,0},
{ 258,PROCESS_NEW, 13,"process259",pid258_ops,10000,0},
{ 259,PROCESS_NEW, 12,"process260",pid259_ops,10000,0},
{ 260,PROCESS_NEW, 13,"process261",pid260_ops,10000,0},
{ 261,PROCESS_NEW, 19,"process262",pid261_ops,10000,0},
{ 262,PROCESS_NEW, 10,"process263",pid262_ops,10000,0},
{ 263,PROCESS_NEW, 1,"process264",pid263_ops,10000,0},
{ 264,PROCESS_NEW, 18,"process265",pid264_ops,10000,0},
{ 265,PROCESS_NEW, 0,"process266",pid265_ops,10000,0},
{ 266,PROCESS_NEW, 13,"process267",pid266_ops,10000,0},
{ 267,PROCESS_NEW, 5,"process268",pid267_ops,10000,0},
{ 268,PROCESS_NEW, 13,"process269",pid268_ops,10000,0},
{ 269,PROCESS_NEW, 2,"process270",pid269_ops,10000,0},
{ 270,PROCESS_NEW, 1,"process271",pid270_ops,10000,0},
{ 271,PROCESS_NEW, 17,"process272",pid271_ops,10000,0},
{ 272,PROCESS_NEW, 0,"process273",pid272_ops,10000,0},
{ 273,PROCESS_NEW, 15,"process274",pid273_ops,10000,0},
{ 274,PROCESS_NEW, 1,"process275",pid274_ops,10000,0},
{ 275,PROCESS_NEW, 0,"process276",pid275_ops,10000,0},
{ 276,PROCESS_NEW, 7,"process277",pid276_ops,10000,0},
{ 277,PROCESS_NEW, 10,"process278",pid277_ops,10000,0},
{ 278,PROCESS_NEW, 18,"process279",pid278_ops,10000,0},
{ 279,PROCESS_NEW, 17,"process280",pid279_ops,10000,0},
{ 280,PROCESS_NEW, 6,"process281",pid280_ops,10000,0},
{ 281,PROCESS_NEW, 11,"process282",pid281_ops,10000,0},
{ 282,PROCESS_NEW, 16,"process283",pid282_ops,10000,0},
{ 283,PROCESS_NEW, 5,"process284",pid283_ops,10000,0},
{ 284,PROCESS_NEW, 7,"process285",pid284_ops,10000,0},
{ 285,PROCESS_NEW, 3,"process286",pid285_ops,10000,0},
{ 286,PROCESS_NEW, 11,"process287",pid286_ops,10000,0},
{ 287,PROCESS_NEW, 19,"process288",pid287_ops,10000,0},
{ 288,PROCESS_NEW, 14,"process289",pid288_ops,10000,0},
{ 289,PROCESS_NEW, 19,"process290",pid289_ops,10000,0},
{ 290,PROCESS_NEW, 9,"process291",pid290_ops,10000,0},
{ 291,PROCESS_NEW, 5,"process292",pid291_ops,10000,0},
{ 292,PROCESS_NEW, 7,"process293",pid292_ops,10000,0},
{ 293,PROCESS_NEW, 5,"process294",pid293_ops,10000,0},
{ 294,PROCESS_NEW, 13,"process295",pid294_ops,10000,0},
{ 295,PROCESS_NEW, 7,"process296",pid295_ops,10000,0},
{ 296,PROCESS_NEW, 15,"process297",pid296_ops,10000,0},
{ 297,PROCESS_NEW, 13,"process298",pid297_ops,10000,0},
{ 298,PROCESS_NEW, 19,"process299",pid298_ops,10000,0},
{ 299,PROCESS_NEW, 17,"process300",pid299_ops,10000,0},
{ 300,PROCESS_NEW, 7,"process301",pid300_ops,10000,0},
{ 301,PROCESS_NEW, 0,"process302",pid301_ops,10000,0},
{ 302,PROCESS_NEW, 16,"process303",pid302_ops,10000,0},
{ 303,PROCESS_NEW, 4,"process304",pid303_ops,10000,0},
{ 304,PROCESS_NEW, 4,"process305",pid304_ops,10000,0},
{ 305,PROCESS_NEW, 10,"process306",pid305_ops,10000,0},
{ 306,PROCESS_NEW, 1,"process307",pid306_ops,10000,0},
{ 307,PROCESS_NEW, 4,"process308",pid307_ops,10000,0},
{ 308,PROCESS_NEW, 14,"process309",pid308_ops,10000,0},
{ 309,PROCESS_NEW, 1,"process310",pid309_ops,10000,0},
{ 310,PROCESS_NEW, 14,"process311",pid310_ops,10000,0},
{ 311,PROCESS_NEW, 17,"process312",pid311_ops,10000,0},
{ 312,PROCESS_NEW, 19,"process313",pid312_ops,10000,0},
{ 313,PROCESS_NEW, 2,"process314",pid313_ops,10000,0},
{ 314,PROCESS_NEW, 7,"process315",pid314_ops,10000,0},
{ 315,PROCESS_NEW, 3,"process316",pid315_ops,10000,0},
{ 316,PROCESS_NEW, 19,"process317",pid316_ops,10000,0},
{ 317,PROCESS_NEW, 18,"process318",pid317_ops,10000,0},
{ 318,PROCESS_NEW, 13,"process319",pid318_ops,10000,0},
{ 319,PROCESS_NEW, 12,"process320",pid319_ops,10000,0},
{ 320,PROCESS_NEW, 4,"process321",pid320_ops,10000,0},
{ 321,PROCESS_NEW, 9,"process322",pid321_ops,10000,0},
{ 322,PROCESS_NEW, 19,"process323",pid322_ops,10000,0},
{ 323,PROCESS_NEW, 3,"process324",pid323_ops,10000,0},
{ 324,PROCESS_NEW, 5,"process325",pid324_ops,10000,0},
{ 325,PROCESS_NEW, 13,"process326",pid325_ops,10000,0},
{ 326,PROCESS_NEW, 4,"process327",pid326_ops,10000,0},
{ 327,PROCESS_NEW, 7,"process328",pid327_ops,10000,0},
{ 328,PROCESS_NEW, 9,"process329",pid328_ops,10000,0},
{ 329,PROCESS_NEW, 19,"process330",pid329_ops,10000,0},
{ 330,PROCESS_NEW, 1,"process331",pid330_ops,10000,0},
{ 331,PROCESS_NEW, 9,"process332",pid331_ops,10000,0},
{ 332,PROCESS_NEW, 5,"process333",pid332_ops,10000,0},
{ 333,PROCESS_NEW, 3,"process334",pid333_ops,10000,0},
{ 334,PROCESS_NEW, 0,"process335",pid334_ops,10000,0},
{ 335,PROCESS_NEW, 11,"process336",pid335_ops,10000,0},
{ 336,PROCESS_NEW, 5,"process337",pid336_ops,10000,0},
{ 337,PROCESS_NEW, 18,"process338",pid337_ops,10000,0},
{ 338,PROCESS_NEW, 15,"process339",pid338_ops,10000,0},
{ 339,PROCESS_NEW, 5,"process340",pid339_ops,10000,0},
{ 340,PROCESS_NEW, 7,"process341",pid340_ops,10000,0},
{ 341,PROCESS_NEW, 0,"process342",pid341_ops,10000,0},
{ 342,PROCESS_NEW, 3,"process343",pid342_ops,10000,0},
{ 343,PROCESS_NEW, 4,"process344",pid343_ops,10000,0},
{ 344,PROCESS_NEW, 19,"process345",pid344_ops,10000,0},
{ 345,PROCESS_NEW, 4,"process346",pid345_ops,10000,0},
{ 346,PROCESS_NEW, 16,"process347",pid346_ops,10000,0},
{ 347,PROCESS_NEW, 7,"process348",pid347_ops,10000,0},
{ 348,PROCESS_NEW, 2,"process349",pid348_ops,10000,0},
{ 349,PROCESS_NEW, 13,"process350",pid349_ops,10000,0},
{ 350,PROCESS_NEW, 2,"process351",pid350_ops,10000,0},
{ 351,PROCESS_NEW, 7,"process352",pid351_ops,10000,0},
{ 352,PROCESS_NEW, 4,"process353",pid352_ops,10000,0},
{ 353,PROCESS_NEW, 14,"process354",pid353_ops,10000,0},
{ 354,PROCESS_NEW, 4,"process355",pid354_ops,10000,0},
{ 355,PROCESS_NEW, 8,"process356",pid355_ops,10000,0},
{ 356,PROCESS_NEW, 10,"process357",pid356_ops,10000,0},
{ 357,PROCESS_NEW, 3,"process358",pid357_ops,10000,0},
{ 358,PROCESS_NEW, 7,"process359",pid358_ops,10000,0},
{ 359,PROCESS_NEW, 6,"process360",pid359_ops,10000,0},
{ 360,PROCESS_NEW, 5,"process361",pid360_ops,10000,0},
{ 361,PROCESS_NEW, 15,"process362",pid361_ops,10000,0},
{ 362,PROCESS_NEW, 12,"process363",pid362_ops,10000,0},
{ 363,PROCESS_NEW, 12,"process364",pid363_ops,10000,0},
{ 364,PROCESS_NEW, 14,"process365",pid364_ops,10000,0},
{ 365,PROCESS_NEW, 18,"process366",pid365_ops,10000,0},
{ 366,PROCESS_NEW, 0,"process367",pid366_ops,10000,0},
{ 367,PROCESS_NEW, 19,"process368",pid367_ops,10000,0},
{ 368,PROCESS_NEW, 5,"process369",pid368_ops,10000,0},
{ 369,PROCESS_NEW, 5,"process370",pid369_ops,10000,0},
{ 370,PROCESS_NEW, 9,"process371",pid370_ops,10000,0},
{ 371,PROCESS_NEW, 10,"process372",pid371_ops,10000,0},
{ 372,PROCESS_NEW, 19,"process373",pid372_ops,10000,0},
{ 373,PROCESS_NEW, 1,"process374",pid373_ops,10000,0},
{ 374,PROCESS_NEW, 18,"process375",pid374_ops,10000,0},
{ 375,PROCESS_NEW, 8,"process376",pid375_ops,10000,0},
{ 376,PROCESS_NEW, 19,"process377",pid376_ops,10000,0},
{ 377,PROCESS_NEW, 0,"process378",pid377_ops,10000,0},
{ 378,PROCESS_NEW, 8,"process379",pid378_ops,10000,0},
{ 379,PROCESS_NEW, 7,"process380",pid379_ops,10000,0},
{ 380,PROCESS_NEW, 3,"process381",pid380_ops,10000,0},
{ 381,PROCESS_NEW, 2,"process382",pid381_ops,10000,0},
{ 382,PROCESS_NEW, 13,"process383",pid382_ops,10000,0},
{ 383,PROCESS_NEW, 4,"process384",pid383_ops,10000,0},
{ 384,PROCESS_NEW, 12,"process385",pid384_ops,10000,0},
{ 385,PROCESS_NEW, 5,"process386",pid385_ops,10000,0},
{ 386,PROCESS_NEW, 9,"process387",pid386_ops,10000,0},
{ 387,PROCESS_NEW, 6,"process388",pid387_ops,10000,0},
{ 388,PROCESS_NEW, 18,"process389",pid388_ops,10000,0},
{ 389,PROCESS_NEW, 3,"process390",pid389_ops,10000,0},
{ 390,PROCESS_NEW, 9,"process391",pid390_ops,10000,0},
{ 391,PROCESS_NEW, 10,"process392",pid391_ops,10000,0},
{ 392,PROCESS_NEW, 5,"process393",pid392_ops,10000,0},
{ 393,PROCESS_NEW, 9,"process394",pid393_ops,10000,0},
{ 394,PROCESS_NEW, 8,"process395",pid394_ops,10000,0},
{ 395,PROCESS_NEW, 9,"process396",pid395_ops,10000,0},
{ 396,PROCESS_NEW, 4,"process397",pid396_ops,10000,0},
{ 397,PROCESS_NEW, 1,"process398",pid397_ops,10000,0},
{ 398,PROCESS_NEW, 10,"process399",pid398_ops,10000,0},
{ 399,PROCESS_NEW, 14,"process400",pid399_ops,10000,0},
{ 400,PROCESS_NEW, 7,"process401",pid400_ops,10000,0},
{ 401,PROCESS_NEW, 7,"process402",pid401_ops,10000,0},
{ 402,PROCESS_NEW, 5,"process403",pid402_ops,10000,0},
{ 403,PROCESS_NEW, 4,"process404",pid403_ops,10000,0},
{ 404,PROCESS_NEW, 12,"process405",pid404_ops,10000,0},
{ 405,PROCESS_NEW, 6,"process406",pid405_ops,10000,0},
{ 406,PROCESS_NEW, 0,"process407",pid406_ops,10000,0},
{ 407,PROCESS_NEW, 0,"process408",pid407_ops,10000,0},
{ 408,PROCESS_NEW, 6,"process409",pid408_ops,10000,0},
{ 409,PROCESS_NEW, 9,"process410",pid409_ops,10000,0},
{ 410,PROCESS_NEW, 18,"process411",pid410_ops,10000,0},
{ 411,PROCESS_NEW, 14,"process412",pid411_ops,10000,0},
{ 412,PROCESS_NEW, 8,"process413",pid412_ops,10000,0},
{ 413,PROCESS_NEW, 19,"process414",pid413_ops,10000,0},
{ 414,PROCESS_NEW, 8,"process415",pid414_ops,10000,0},
{ 415,PROCESS_NEW, 14,"process416",pid415_ops,10000,0},
{ 416,PROCESS_NEW, 11,"process417",pid416_ops,10000,0},
{ 417,PROCESS_NEW, 11,"process418",pid417_ops,10000,0},
{ 418,PROCESS_NEW, 3,"process419",pid418_ops,10000,0},
{ 419,PROCESS_NEW, 6,"process420",pid419_ops,10000,0},
{ 420,PROCESS_NEW, 16,"process421",pid420_ops,10000,0},
{ 421,PROCESS_NEW, 10,"process422",pid421_ops,10000,0},
{ 422,PROCESS_NEW, 8,"process423",pid422_ops,10000,0},
{ 423,PROCESS_NEW, 16,"process424",pid423_ops,10000,0},
{ 424,PROCESS_NEW, 8,"process425",pid424_ops,10000,0},
{ 425,PROCESS_NEW, 11,"process426",pid425_ops,10000,0},
{ 426,PROCESS_NEW, 7,"process427",pid426_ops,10000,0},
{ 427,PROCESS_NEW, 11,"process428",pid427_ops,10000,0},
{ 428,PROCESS_NEW, 18,"process429",pid428_ops,10000,0},
{ 429,PROCESS_NEW, 18,"process430",pid429_ops,10000,0},
{ 430,PROCESS_NEW, 0,"process431",pid430_ops,10000,0},
{ 431,PROCESS_NEW, 19,"process432",pid431_ops,10000,0},
{ 432,PROCESS_NEW, 18,"process433",pid432_ops,10000,0},
{ 433,PROCESS_NEW, 0,"process434",pid433_ops,10000,0},
{ 434,PROCESS_NEW, 17,"process435",pid434_ops,10000,0},
{ 435,PROCESS_NEW, 18,"process436",pid435_ops,10000,0},
{ 436,PROCESS_NEW, 8,"process437",pid436_ops,10000,0},
{ 437,PROCESS_NEW, 0,"process438",pid437_ops,10000,0},
{ 438,PROCESS_NEW, 7,"process439",pid438_ops,10000,0},
{ 439,PROCESS_NEW, 11,"process440",pid439_ops,10000,0},
{ 440,PROCESS_NEW, 14,"process441",pid440_ops,10000,0},
{ 441,PROCESS_NEW, 17,"process442",pid441_ops,10000,0},
{ 442,PROCESS_NEW, 11,"process443",pid442_ops,10000,0},
{ 443,PROCESS_NEW, 13,"process444",pid443_ops,10000,0},
{ 444,PROCESS_NEW, 17,"process445",pid444_ops,10000,0},
{ 445,PROCESS_NEW, 14,"process446",pid445_ops,10000,0},
{ 446,PROCESS_NEW, 17,"process447",pid446_ops,10000,0},
{ 447,PROCESS_NEW, 15,"process448",pid447_ops,10000,0},
{ 448,PROCESS_NEW, 19,"process449",pid448_ops,10000,0},
{ 449,PROCESS_NEW, 7,"process450",pid449_ops,10000,0},
{ 450,PROCESS_NEW, 7,"process451",pid450_ops,10000,0},
{ 451,PROCESS_NEW, 5,"process452",pid451_ops,10000,0},
{ 452,PROCESS_NEW, 17,"process453",pid452_ops,10000,0},
{ 453,PROCESS_NEW, 14,"process454",pid453_ops,10000,0},
{ 454,PROCESS_NEW, 9,"process455",pid454_ops,10000,0},
{ 455,PROCESS_NEW, 7,"process456",pid455_ops,10000,0},
{ 456,PROCESS_NEW, 1,"process457",pid456_ops,10000,0},
{ 457,PROCESS_NEW, 14,"process458",pid457_ops,10000,0},
{ 458,PROCESS_NEW, 7,"process459",pid458_ops,10000,0},
{ 459,PROCESS_NEW, 2,"process460",pid459_ops,10000,0},
{ 460,PROCESS_NEW, 5,"process461",pid460_ops,10000,0},
{ 461,PROCESS_NEW, 5,"process462",pid461_ops,10000,0},
{ 462,PROCESS_NEW, 3,"process463",pid462_ops,10000,0},
{ 463,PROCESS_NEW, 12,"process464",pid463_ops,10000,0},
{ 464,PROCESS_NEW, 4,"process465",pid464_ops,10000,0},
{ 465,PROCESS_NEW, 1,"process466",pid465_ops,10000,0},
{ 466,PROCESS_NEW, 5,"process467",pid466_ops,10000,0},
{ 467,PROCESS_NEW, 6,"process468",pid467_ops,10000,0},
{ 468,PROCESS_NEW, 12,"process469",pid468_ops,10000,0},
{ 469,PROCESS_NEW, 5,"process470",pid469_ops,10000,0},
{ 470,PROCESS_NEW, 19,"process471",pid470_ops,10000,0},
{ 471,PROCESS_NEW, 3,"process472",pid471_ops,10000,0},
{ 472,PROCESS_NEW, 0,"process473",pid472_ops,10000,0},
{ 473,PROCESS_NEW, 1,"process474",pid473_ops,10000,0},
{ 474,PROCESS_NEW, 13,"process475",pid474_ops,10000,0},
{ 475,PROCESS_NEW, 13,"process476",pid475_ops,10000,0},
{ 476,PROCESS_NEW, 13,"process477",pid476_ops,10000,0},
{ 477,PROCESS_NEW, 12,"process478",pid477_ops,10000,0},
{ 478,PROCESS_NEW, 10,"process479",pid478_ops,10000,0},
{ 479,PROCESS_NEW, 14,"process480",pid479_ops,10000,0},
{ 480,PROCESS_NEW, 0,"process481",pid480_ops,10000,0},
{ 481,PROCESS_NEW, 8,"process482",pid481_ops,10000,0},
{ 482,PROCESS_NEW, 1,"process483",pid482_ops,10000,0},
{ 483,PROCESS_NEW, 7,"process484",pid483_ops,10000,0},
{ 484,PROCESS_NEW, 9,"process485",pid484_ops,10000,0},
{ 485,PROCESS_NEW, 11,"process486",pid485_ops,10000,0},
{ 486,PROCESS_NEW, 13,"process487",pid486_ops,10000,0},
{ 487,PROCESS_NEW, 10,"process488",pid487_ops,10000,0},
{ 488,PROCESS_NEW, 16,"process489",pid488_ops,10000,0},
{ 489,PROCESS_NEW, 0,"process490",pid489_ops,10000,0},
{ 490,PROCESS_NEW, 11,"process491",pid490_ops,10000,0},
{ 491,PROCESS_NEW, 8,"process492",pid491_ops,10000,0},
{ 492,PROCESS_NEW, 12,"process493",pid492_ops,10000,0},
{ 493,PROCESS_NEW, 6,"process494",pid493_ops,10000,0},
{ 494,PROCESS_NEW, 11,"process495",pid494_ops,10000,0},
{ 495,PROCESS_NEW, 17,"process496",pid495_ops,10000,0},
{ 496,PROCESS_NEW, 5,"process497",pid496_ops,10000,0},
{ 497,PROCESS_NEW, 13,"process498",pid497_ops,10000,0},
{ 498,PROCESS_NEW, 10,"process499",pid498_ops,10000,0},
{ 499,PROCESS_NEW, 3,"process500",pid499_ops,10000,0}};
