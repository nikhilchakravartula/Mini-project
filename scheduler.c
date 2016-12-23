//write the scheduler here
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "simulator.h"
#include <stdbool.h>
#include <limits.h>
#define NOQ 3
#define NOC 4
#define HIGH_LOWER 0
#define HIGH_UPPER 5
#define MEDIUM_LOWER 6
#define MEDIUM_UPPER 14
#define LOW_LOWER 15
#define LOW_UPPER 19
#define CACHE_LEVEL1_ACCESS_TIME 1
#define CACHE_LEVEL2_ACCESS_TIME 4
#define CACHE_HIT_RATE 80
#define CACHE_MISS_RATE 20
#define MEMORY_ACCESS_TIME 100
#define LEVEL1_MIG_COST (CACHE_HIT_RATE/100.0)*(CACHE_LEVEL1_ACCESS_TIME) +(CACHE_MISS_RATE/100.0)*(CACHE_LEVEL2_ACCESS_TIME)
#define LEVEL2_MIG_COST (CACHE_HIT_RATE/100.0)*(CACHE_LEVEL2_ACCESS_TIME) +(CACHE_MISS_RATE/100.0)*(MEMORY_ACCESS_TIME) 
/*static unsigned NOC;*/
static pthread_mutex_t ready_queue_mutex;
static pthread_cond_t cpu_not_idle;
static pthread_mutex_t run_mutex;
static pthread_mutex_t current_mutex;
static  pcb_t *current[NOC];
static struct Queue* run_queue[NOC];
static struct Queue* ready_queue[NOQ];
static int max_chunks;
static int no_of_chunks[NOQ];
static int size_of_chunk[NOQ];
static int group_cores[NOC];
static unsigned num_processes_in_ready;
static unsigned migration_cost;
static double optimum_core_load=0; 
static unsigned TIME_SLICE=-1;
static bool placeInQueue( pcb_t *pcb);
static void schedule(unsigned int cpu_id);
static unsigned int get_group_id(unsigned int cpu_id);
/*============================================================================*/

struct QNode
{
     pcb_t *key;
    struct QNode *next,*prev;
};

struct Queue
{
    struct QNode *front, *rear;
    int length;
};

extern void printQueue(struct Queue *q);
extern  struct QNode* newNode( pcb_t* k);
extern struct Queue *createQueue();
extern void enQueue(struct Queue *q, pcb_t* k);
extern struct QNode *deQueueAtRear(struct Queue *q);
extern struct QNode *deQueueAtFront(struct Queue *q);
extern void sorted_enqueue(struct Queue *q, pcb_t *p);




extern void printQueue(struct Queue *q)
{
  struct QNode* temp = q->front;
  if(temp==NULL)
    return;

  printf("Length is:%d\n",q->length);
  /*while(temp!=q->rear)
  {
     printf("%d\t%d\t%d\t%d\n",temp->key->pid,temp->key->priority,temp->key->cpu_id,temp->key->vruntime);
     temp = temp->next;
  }
  printf("%d\t%d\t%d\t%d\n",temp->key->pid,temp->key->priority,temp->key->cpu_id,temp->key->vruntime);
*/
}

extern struct QNode* newNode(pcb_t *p)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = p;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

extern struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->length = 0;
    return q;
}

extern void enQueue(struct Queue *q, pcb_t* p)
{
    struct QNode *temp = newNode(p);
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       q->length++;
       return;
    }
    q->rear->next = temp;
    temp->prev = q->rear;
    q->rear = temp;
    q->length++;
}

extern struct QNode *deQueueAtFront(struct Queue *q)
{
    if (q->front == NULL)
       return NULL;
    struct QNode *temp = q->front;
    q->front = temp->next;
    if(q->front!=NULL)
        q->front->prev = NULL;
    if(q->front == NULL)
       q->rear = NULL;
    q->length--;
    return temp;
}

extern struct QNode *deQueueAtRear(struct Queue *q){
    if(q->front == NULL)
        return NULL;
    struct QNode *temp = q->rear;
    q->rear = temp->prev;
    if(q->rear != NULL)
        q->rear->next = NULL;
    if(q->rear == NULL)
        q->front = NULL;
    q->length--;
    return temp;
}

extern void sorted_enqueue(struct Queue *q, pcb_t *p){
    struct QNode *temp, *prv, *n;
    n =newNode(p);
 
    if(q->front == NULL){
        q->front = q->rear = n;
        q->length++;
        return;
    }
    temp = q->front;
    while(temp!=q->rear){
        if(temp->key->vruntime > p->vruntime)
            break;
        temp = temp->next;
    }
    if(temp == q->front){
        if(temp->key->vruntime > p->vruntime){
            temp->prev = n;
            n->next = temp;
            q->front = n;
            q->length++;
        }
        else{
            prv = temp->next;
            temp->next = n;
            n->prev = temp;
            if(temp == q->rear){
                q->rear = n;
            }
            else{
                prv->prev = n;
                n->next = prv;
            }
            q->length++;
        }
    }
    else if(temp == q->rear){
        if(q->rear->key->vruntime > p->vruntime){
            prv = temp->prev;
            prv->next = n;
            n->prev = prv;
            n->next = q->rear;
            q->rear->prev = n;
        }
        else{
            q->rear->next = n;
            n->prev = q->rear;
            q->rear = n;
        }
        q->length++;
    }/*
    else if(temp == NULL){
        q->rear->next = n;
        n->prev = q->rear;
        q->rear = n;
        q->length++;
    }*/
    else if(temp!=NULL){
        prv = temp->prev;
        prv->next = n;
        n->prev = prv;
        n->next = temp;
        temp->prev = n;
        q->length++;
    }
}





















/*======================================================================*/

extern void preempt(unsigned cpu_id)
{
pthread_mutex_lock(&ready_queue_mutex);
 pcb_t* pcb=current[cpu_id];/*ready queue member of cpuid*/
pcb->state=PROCESS_READY;
/*ADDTOTHEREADYQUEUE(cpu_id);*/
placeInQueue(pcb);
num_processes_in_ready+=1;
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);
}


extern  void idle(unsigned cpu_id)
{
pthread_mutex_lock(&ready_queue_mutex);
while( num_processes_in_ready==0)
pthread_cond_wait(&cpu_not_idle,&ready_queue_mutex);
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);

}

extern void yield(unsigned cpu_id)
{
    pthread_mutex_lock(&ready_queue_mutex);
  pcb_t* pcb=current[cpu_id];/*ready queue member of cpuid*/
pcb->state=PROCESS_BLOCKED;
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);


}

extern  void terminate(unsigned cpu_id)
{
pthread_mutex_lock(&ready_queue_mutex);
 pcb_t* pcb=current[cpu_id];/*ready queue member of cpuid*/
pcb->state=PROCESS_TERMINATED;
schedule(cpu_id);
pthread_mutex_unlock(&ready_queue_mutex);


}



static void initialise_ready_and_run_queue()
{
   int i;
   max_chunks = 12;
   no_of_chunks[0] = max_chunks/6;
   no_of_chunks[1] = max_chunks/4;
   no_of_chunks[2] = max_chunks/2;

   for(i=0;i<NOQ;i++)
   {
     pthread_mutex_lock(&ready_queue_mutex);
     ready_queue[i] = createQueue();
     pthread_mutex_unlock(&ready_queue_mutex);
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


static bool placeInQueue( pcb_t *pcb)
{
  
  assert(pcb->priority>=HIGH_LOWER && pcb->priority<=LOW_UPPER);
  pthread_mutex_lock(&ready_queue_mutex);
  if( pcb->priority>=HIGH_LOWER&& pcb->priority<=HIGH_UPPER)
    enQueue(ready_queue[0],pcb);
  else if( pcb->priority>=MEDIUM_LOWER&& pcb->priority<=MEDIUM_UPPER)
    enQueue(ready_queue[1],pcb);
  else if( pcb->priority>=LOW_LOWER&& pcb->priority<=LOW_UPPER)
    enQueue(ready_queue[2],pcb);
    pthread_cond_broadcast(&cpu_not_idle);
    return true;
  }


/*WHAT THE FUCK IS THIS!!!*/

static int find_idlest_core_group(const int group_id)
{
    int i;
    int smallLength = INT_MAX;
    int smallCore = INT_MAX;
    for(i=0;i<NOC;i++)
    {
       /*pthread_mutex_lock(&run_mutex);*/
       if(group_cores[i]==group_id&&smallLength>run_queue[i]->length)
       {
         smallCore=i;
         smallLength=run_queue[i]->length;
       }
       /*pthread_mutex_unlock(&run_mutex);*/
    }
    return smallCore;
}


static int calculate_overall_load(){
    
}


static int find_idlest_core(unsigned int flag)
{
  /*MAKE TRADE OFF IN THIS FUNCTION*/
     int core;
     int core1, core2;
     int i;
     int leastLength = INT_MAX;
     int leastCore = INT_MAX;
     if(flag==0)
     {
       /*pthread_mutex_lock(&run_mutex);*/
       for(i=0;i<NOC;i++)
       {
          if(leastLength>run_queue[i]->length){
            leastCore = i;
            leastLength = run_queue[i]->length;
          }
       }
       /*pthread_mutex_unlock(&run_mutex);*/
     }
     else
     {
       /*MAKE TRADE OFF HERE ... IF LOAD IS GREATER THAN waht it should be migrate it to other core*/
        int group_id = get_group_id(flag);
        core1 = find_idlest_core_group(group_id);
        int total_length = 0;
        for(i=0; i<NOC; i++)
            total_length += run_queue[i]->length;
        if(((run_queue[core1]+1)*10)/(total_length+1) > optimum_core_load){
            leastLength = INT_MAX;
            leastCore = INT_MAX;
            /*pthread_mutex_lock(&run_mutex);*/
            for(i=0;i<NOC;i++)
            {
                if(leastLength>run_queue[i]->length){
                    leastCore = i;
                    leastLength = run_queue[i]->length;
                }
            }
            /*pthread_mutex_unlock(&run_mutex);*/
            core2 = leastCore;
            if(((run_queue[core2]+1)*10)/(total_length+1) > optimum_core_load*0.5)
                core = core2;
            else
                core = core1;
        }
        else
            core = core1;
     }
     return core;
}


static void dispatch_process( pcb_t *pcb)
{
    int core;
    if(pcb->prev_cpu_id==-1)
        core = find_idlest_core(0);
    else
        core = find_idlest_core(pcb->prev_cpu_id);

    pcb->prev_cpu_id = core;
    /*pthread_mutex_lock(&run_mutex);*/
    sorted_enqueue(run_queue[core],pcb);
    /*pthread_mutex_unlock(&run_mutex);*/
}


static unsigned int get_group_id(unsigned int cpu_id)
{
    return group_cores[cpu_id];
}


static void schedule_next_process()
{
   int i,j;
 
      while(true){

       for(i=0;i<NOQ;i++)
       {
          pthread_mutex_lock(&ready_queue_mutex);

          size_of_chunk[i] = ready_queue[i]->length/no_of_chunks[i];
          if(size_of_chunk[i]<1)
            size_of_chunk[i]=1;
          for(j=0;j<size_of_chunk[i];j++)
          {
              struct QNode* node = deQueueAtFront(ready_queue[i]);
              if(node==NULL)
                break;
              
              pcb_t* pcb = node->key;
              pthread_mutex_lock(&run_mutex);
              dispatch_process(pcb);
              num_processes_in_ready--;
              pthread_mutex_unlock(&run_mutex);
          }
          pthread_mutex_unlock(&ready_queue_mutex);
       }
       
      }

    /*  for(i=0;i<NOC;i++)
      {
          printf("\n");
          printQueue(run_queue[i]);
      }

     printf("\nScheduling Done.....\n");*/
}

extern  void wake_up( pcb_t *pcb)
{
    pthread_mutex_lock(&ready_queue_mutex);
     pcb->state = PROCESS_READY;

   /*  if(!placeInQueue(process))
        exit(1);     MODIFIED THIS*/


        placeInQueue(pcb);
        num_processes_in_ready+=1;
    pthread_mutex_unlock(&ready_queue_mutex);
}

extern  void schedule(unsigned int cpu_id)
{
     pcb_t *pcb = NULL;
    int i;
    int group;
    int highest_utilized_core = INT_MIN;
    int highest_length = INT_MIN;
    struct QNode* node = deQueueAtRear(run_queue[cpu_id]);

    if(node!=NULL){
     pcb= node->key;
     current[cpu_id] = pcb;
     pcb->state=PROCESS_RUNNING;
    }
    else{

      group = get_group_id(cpu_id);
      for(i=0;i<NOC;i++){
        if(group_cores[i]==get_group_id(i) && run_queue[i]->length<highest_length){
            highest_utilized_core = i;
            highest_length = run_queue[i]->length;
        }
      }
      /*WHAT IF NODE IS NULL HERE*/
      node = deQueueAtFront(run_queue[highest_utilized_core]);
      if(node!=NULL)
      pcb = node->key;

    }
    if(pcb==NULL)
    {
       highest_utilized_core = INT_MIN;
       highest_length = INT_MIN;
       for(i=0;i<NOC;i++){
        if(run_queue[i]->length<highest_length){
            highest_utilized_core = i;
            highest_length = run_queue[i]->length;
        }

      }
      node = deQueueAtFront(run_queue[highest_utilized_core]);
      /*WHAT IF NODE IS NULL HERE*/
      
      if(node!=NULL)
      pcb = node->key;
    }

    if(pcb==NULL)
       current[cpu_id] = NULL;
    else{
       current[cpu_id] = pcb;
       pcb->state=PROCESS_RUNNING;
       context_switch(cpu_id,pcb,TIME_SLICE);
     }
}


int main(int argc,char** argv)
{
    /*NOC=atoi(argv[1]);*/
    int i;
    pthread_t sch;
    if(argc<2)
    {
    
    printf("WHAT HAVE YOU GIVEN ME\t EXPECTING SOME OTHER THING :P");
    exit(0);
    }
    TIME_SLICE=atoi(argv[2]);
    pthread_mutex_init(&ready_queue_mutex,NULL);
    pthread_cond_init(&cpu_not_idle,NULL);
    initialise_ready_and_run_queue();
    migration_cost=0;
    optimum_core_load=100.0/NOC;
    pthread_start(sch, NULL, schedule_next_process, NULL);
    start_simulator(NOC);

}
