#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"
#define NOQ 3
#define NOC 4
#define HIGH_LOWER 0
#define HIGH_UPPER 5
#define MEDIUM_LOWER 6
#define MEDIUM_UPPER 14
#define LOW_LOWER 15
#define LOW_UPPER 19
#define TIME_SLICE 4


static pthread_mutex_t disk_mutex;
static pthread_mutex_t run_mutex;
static pthread_mutex_t current_mutex;

static pcb_t *current[NOC];
static struct Queue* run_queue[NOC];
static struct Queue* disks_queue[NOQ];
static int max_chunks;
static int no_of_chunks[NOQ];
static int size_of_chunk[NOQ];
static int group_cores[NOC];


void print_disks()
{
   int i;
   for(i=0;i<NOQ;i++){

     pthread_mutex_lock(&disk_mutex);
     printQueue(disks_queue[i]);
     pthread_mutex_unlock(&disk_mutex);
     printf("\n\n");
    }
}

void initialise_ready_and_run_queue()
{
   int i;
   max_chunks = 12;
   no_of_chunks[0] = max_chunks/6;
   no_of_chunks[1] = max_chunks/4;
   no_of_chunks[2] = max_chunks/2;

   for(i=0;i<NOQ;i++)
   {
     pthread_mutex_lock(&disk_mutex);
     disks_queue[i] = createQueue();
     pthread_mutex_unlock(&disk_mutex);
   }
   for(i=0;i<NOC;i++){

    group_cores[i] = 1+rand()%2;

    pthread_mutex_lock(&run_mutex);
    run_queue[i] = createQueue();
    pthread_mutex_unlock(&run_mutex);

    pthread_mutex_lock(&current_mutex);
    current[i] = NULL;
    pthread_mutex_unlock(&current_mutex);

    }
}

bool placeInQueue(pcb_t *p)
{
  int temp = p->priority;
  pthread_mutex_lock(&disk_mutex);
  if(temp>=HIGH_LOWER&&temp<=HIGH_UPPER)
    enQueue(disks_queue[0],p);
  else if(temp>=MEDIUM_LOWER&&temp<=MEDIUM_UPPER)
    enQueue(disks_queue[1],p);
  else if(temp>=LOW_LOWER&&temp<=LOW_UPPER)
    enQueue(disks_queue[2],p);
  else{
    pthread_mutex_unlock(&disk_mutex);
    return false;
  }
  pthread_mutex_unlock(&disk_mutex);
  return true;
}

int find_idlest_core_group(int group_id)
{
    int i;
    int smallLength = INT_MAX;
    int smallCore = INT_MAX;
    for(i=0;i<NOC;i++)
    {
       //pthread_mutex_lock(&run_mutex);
       if(group_cores[i]==group_id&&smallLength>run_queue[i]->length)
       {
         smallCore=i;
         smallLength=run_queue[i]->length;
       }
      // pthread_mutex_unlock(&run_mutex);
    }
    return smallCore;
}

int get_group_id(int cpu_id)
{
    return group_cores[cpu_id];
}

int find_idlest_core(int flag)
{
     int core;
     if(flag==0)
     {
       int i;
       int leastLength = INT_MAX;
       int leastCore = INT_MAX;
       for(i=0;i<NOC;i++)
       {
         // pthread_mutex_lock(&run_mutex);
          if(leastLength>run_queue[i]->length){
            leastCore = i;
            leastLength = run_queue[i]->length;
          }
        // pthread_mutex_unlock(&run_mutex);
       }
       core = leastCore;
     }
     else
     {
        int group_id = get_group_id(flag);
        core = find_idlest_core_group(group_id);
     }
     return core;
}

void dispatch_process(pcb_t *p)
{
    int core;
    if(p->cpu_id==-1)
        core = find_idlest_core(0);
    else
        core = find_idlest_core(p->cpu_id);

    p->cpu_id = core;
  //  pthread_mutex_lock(&run_mutex);
    enQueue(run_queue[core],p);
  //  pthread_mutex_unlock(&run_mutex);
}

void schedule_next_process()
{
   int i,j;
   //print_disks();
   int flag=0;
      while(true){

       for(i=0;i<NOQ;i++)
       {
          pthread_mutex_lock(&disk_mutex);

          size_of_chunk[i] = disks_queue[i]->length/no_of_chunks[i];
          if(size_of_chunk[i]<1)
            size_of_chunk[i]=1;
          for(j=0;j<size_of_chunk[i];j++)
          {
              struct QNode* node = deQueue(disks_queue[i]);
              if(node==NULL)
                break;
              flag++;
              pcb_t* p = node->key;
              pthread_mutex_lock(&run_mutex);
              dispatch_process(p);
              pthread_mutex_unlock(&run_mutex);
          }
          pthread_mutex_unlock(&disk_mutex);
       }
       if(flag==20)
            break;
      }

    /*  for(i=0;i<NOC;i++)
      {
          printf("\n");
          printQueue(run_queue[i]);
      }

     printf("\nScheduling Done.....\n");*/
}

extern void wake_up(pcb_t *process)
{
     process->state = PROCESS_READY;
     if(!placeInQueue(process))
        exit(1);
}

static void schedule(unsigned int cpu_id);
{
    pcb_t *p = NULL;
    int i;
    int group;
    int highest_utilized_core = INT_MIN;
    int highest_length = INT_MIN;
    QNode* node = deQueue(run_queue[cpu_id]);

    if(node!=NULL){
     p = node->key;
     current[cpu_id] = p;
    }
    else{

      group = get_group_id(cpu_id);
      for(i=0;i<NOC;i++){
        if(group_cores[i]==group_id && run_queue[i]->length<highest_length){
            highest_utitlized_core = i;
            highest_length = run_queue[i]->length;
        }
      }
      node = deQueue(run_queue[highest_utilized_core]);
      p = node->key;

    }
    if(p==NULL)
    {
       highest_utilized_core = INT_MIN;
       highest_length = INT_MIN;
       for(i=0;i<NOC;i++){
        if(run_queue[i]->length<highest_length){
            highest_utitlized_core = i;
            highest_length = run_queue[i]->length;
        }

      }
      node = deQueue(run_queue[highest_utilized_core]);
      p = node->key;
    }

    if(p==NULL)
       current[cpu_id] = NULL;
    else{
       current[cpu_id] = p;
       context_switch(cpu_id,p,TIME_SLICE);
     }
}


