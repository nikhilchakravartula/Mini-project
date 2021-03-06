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
static pthread_mutex_t run_mutex;
static pthread_mutex_t current_mutex;
static  pcb_t *current[NOC];
static struct Queue* run_queue[NOC];
static struct Queue* ready_queue[NOQ];
static int max_chunks;
static int no_of_chunks[NOQ];
static int size_of_chunk[NOQ];
static int group_cores[NOC];
static unsigned migration_cost;
static double optimum_core_load=0;
static int TIME_SLICE=-1;
static int SCHEDULING_TYPE; 

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

extern struct QNode *deQueueAtRear(struct Queue *q,int flag);

extern struct QNode *deQueueAtFront(struct Queue *q,int flag);

extern void sorted_enqueue(struct Queue *q, pcb_t *p);

extern void sorted_enqueue_priority(struct Queue *q, pcb_t *p);







extern void printQueue(struct Queue *q)
{

    struct QNode* temp = q->front;
		if(q==NULL)
			return;
    if(temp==NULL){
	/*printf("Empty Queue :p :D :D :D\n");*/
        return;
    }



    printf("Length is:%d\n",q->length);

    while(temp!=q->rear)

    {

       printf("%d %d\t\n",temp->key->pid,temp->key->state);

       temp = temp->next;

    }

       printf("%d %d\t\n",temp->key->pid,temp->key->state);

    

}

/*
extern void printQueues()
{
int i;

printf("\nREADY QUEUE\n");
for(i=0;i<NOQ;i++)
printQueue(ready_queue[i]);


printf("RUN QUEUE\n");
for(i=0;i<NOC;i++)
printQueue(run_queue[i]);
}*/
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

    struct QNode *temp ;
/*printf("\nenQueue from %d\n",(int)pthread_self());*/
pthread_mutex_lock(&ready_queue_mutex);
	temp= newNode(p);
    if (q->rear == NULL)

    {

        q->front = q->rear = temp;

        q->length++;
pthread_mutex_unlock(&ready_queue_mutex);
/*printf("\nfinished enqueue\n");*/
        return;

    }

    q->rear->next = temp;

    temp->prev = q->rear;

    q->rear = temp;

    q->length++;
pthread_mutex_unlock(&ready_queue_mutex);
/*printf("finished enqueue\n");*/
}



extern struct QNode *deQueueAtFront(struct Queue *q,int flag)

{
    struct QNode* temp;

/*printf("\ndeque at front from %d\n",(int)pthread_self());	*/

	if(flag==1)
	{
		pthread_mutex_lock(&ready_queue_mutex);

	}
	else
	{
		pthread_mutex_lock(&run_mutex);
	}

    if (q->front == NULL)
{
	if(flag==1)
	{
		pthread_mutex_unlock(&ready_queue_mutex);

	}
	else
	{
		pthread_mutex_unlock(&run_mutex);
	}
        return NULL;
}
    temp = q->front;

    q->front = temp->next;

    if(q->front!=NULL)

        q->front->prev = NULL;

    if(q->front == NULL)

        q->rear = NULL;

    q->length--;

	if(flag==1)
	{
		pthread_mutex_unlock(&ready_queue_mutex);

	}
	else
	{
		pthread_mutex_unlock(&run_mutex);
	}

    return temp;

}



extern struct QNode *deQueueAtRear(struct Queue *q,int flag)
{

    struct QNode * temp;

	/*printf("\ndequeue from rear %d\n",(int)pthread_self());*/
    if(q->front == NULL)

        return NULL;

    temp = q->rear;

    q->rear = temp->prev;

    if(q->rear != NULL)

        q->rear->next = NULL;

    if(q->rear == NULL)

        q->front = NULL;

    q->length--;

	

    return temp;

}



extern void sorted_enqueue(struct Queue *q, pcb_t *p)
{

    struct QNode *temp, *prv, *n;
    pthread_mutex_lock(&run_mutex);
    n =newNode(p);
/*printf("\nsorted_enqueue from %d\n",(int)pthread_self());*/

    if(q->front == NULL)
    {

        q->front = q->rear = n;
        q->length++;
        pthread_mutex_unlock(&run_mutex);
/*printf("\n\nFInished sorted Enqueue\n\n");*/
        return;

    }

    temp = q->front;

    while(temp!=q->rear)
    {

        if(temp->key->vruntime > p->vruntime)

            break;

        temp = temp->next;

    }

    if(temp == q->front)
    {

        if(temp->key->vruntime > p->vruntime)
        {

            temp->prev = n;

            n->next = temp;

            q->front = n;

            q->length++;

        }

        else
        {

            prv = temp->next;

            temp->next = n;

            n->prev = temp;

            if(temp == q->rear)
            {

                q->rear = n;

            }

            else
            {

                prv->prev = n;

                n->next = prv;

            }

            q->length++;

        }

    }

    else if(temp == q->rear)
    {

        if(q->rear->key->vruntime > p->vruntime)
        {

            prv = temp->prev;

            prv->next = n;

            n->prev = prv;

            n->next = q->rear;

            q->rear->prev = n;

        }

        else
        {

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

    else if(temp!=NULL)
    {

        prv = temp->prev;

        prv->next = n;

        n->prev = prv;

        n->next = temp;

        temp->prev = n;

        q->length++;

    }
pthread_mutex_unlock(&run_mutex);
/*printf("\n\nfinished sorted enqueue\n\n");*/
}



extern void sorted_enqueue_priority(struct Queue *q, pcb_t *p)
{

    struct QNode *temp, *prv, *n;

   pthread_mutex_lock(&ready_queue_mutex);
    n =newNode(p);
/*printf("\nsorted_enqueue from %d\n",(int)pthread_self());*/

    if(q->front == NULL)
    {

        q->front = q->rear = n;

        q->length++;
   pthread_mutex_unlock(&ready_queue_mutex); 
/*printf("\n\nFInished sorted Enqueue\n\n");*/
        return;

    }

    temp = q->front;

    while(temp!=q->rear)
    {

        if(temp->key->priority > p->priority)

            break;

        temp = temp->next;

    }

    if(temp == q->front)
    {

        if(temp->key->priority > p->priority)
        {

            temp->prev = n;

            n->next = temp;

            q->front = n;

            q->length++;

        }

        else
        {

            prv = temp->next;

            temp->next = n;

            n->prev = temp;

            if(temp == q->rear)
            {

                q->rear = n;

            }

            else
            {

                prv->prev = n;

                n->next = prv;

            }

            q->length++;

        }

    }

    else if(temp == q->rear)
    {

        if(q->rear->key->priority > p->priority)
        {

            prv = temp->prev;

            prv->next = n;

            n->prev = prv;

            n->next = q->rear;

            q->rear->prev = n;

        }

        else
        {

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

    else if(temp!=NULL)
    {

        prv = temp->prev;

        prv->next = n;

        n->prev = prv;

        n->next = temp;

        temp->prev = n;

        q->length++;

    }

  pthread_mutex_unlock(&ready_queue_mutex);
 /*  pthread_mutex_unlock(&run_mutex);  */
/*printf("\n\nfinished sorted enqueue\n\n");*/
}




/*======================================================================*/



extern void preempt(unsigned cpu_id)

{
	pcb_t* pcb;
	pthread_mutex_lock(&current_mutex);
	pcb=current[cpu_id];
	pcb->state=PROCESS_READY;
	pthread_mutex_unlock(&current_mutex);
	placeInQueue(pcb);
	schedule(cpu_id);
}





extern  void idle(unsigned cpu_id)
{
	schedule(cpu_id);
}



extern void yield(unsigned cpu_id)
{
    pcb_t* pcb;
    pthread_mutex_lock(&current_mutex);
    pcb=current[cpu_id];
    pcb->state=PROCESS_BLOCKED;
    pthread_mutex_unlock(&current_mutex);
    schedule(cpu_id);
}



extern  void terminate(unsigned cpu_id)

{
    pcb_t* pcb;
    pthread_mutex_lock(&current_mutex);
    pcb=current[cpu_id];
    pcb->state=PROCESS_TERMINATED;
    pthread_mutex_unlock(&current_mutex);
    schedule(cpu_id);
}

static void initialise_ready_and_run_queue()

{

    int i;
	int group_val=1;
    max_chunks = 12;

    no_of_chunks[0] = max_chunks/6;

    no_of_chunks[1] = max_chunks/4;

    no_of_chunks[2] = max_chunks/2;

    for(i=0; i<NOQ; i++)

    {
        ready_queue[i] = createQueue();

    }
	for(i=0;i<NOC;i++)
	{
		if(i&1)
			{
				group_cores[i]=group_val;
				group_val++;
			}
		else
				group_cores[i]=group_val;
	printf("\n %d belongs to %d\n",i,group_cores[i]);
	}

    for(i=0; i<NOC; i++)
    {
        run_queue[i] = createQueue();
        current[i] = NULL;
    }

}





static bool placeInQueue( pcb_t *pcb)

{

  if(SCHEDULING_TYPE==0)
  { 

    assert(pcb->priority>=HIGH_LOWER && pcb->priority<=LOW_UPPER);
	
    if( pcb->priority>=HIGH_LOWER&& pcb->priority<=HIGH_UPPER){
	
        enQueue(ready_queue[0],pcb);}

    else if( pcb->priority>=MEDIUM_LOWER&& pcb->priority<=MEDIUM_UPPER)
	{
	        enQueue(ready_queue[1],pcb);}

    else if( pcb->priority>=LOW_LOWER&& pcb->priority<=LOW_UPPER)
	{
        enQueue(ready_queue[2],pcb);
	}	

    return true;
  }

  else if(SCHEDULING_TYPE==2)
  {
     enQueue(ready_queue[0],pcb);  
     return true; 
  } 

  else if(SCHEDULING_TYPE==3)
  {
     sorted_enqueue_priority(ready_queue[0],pcb);    
     return true;  
  }
  return false;
}





static int find_idlest_core_group(const int group_id)

{

    int i;

    int smallLength = INT_MAX;

    int smallCore = INT_MAX;

    for(i=0; i<NOC; i++)

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

/*
static int calculate_overall_load(){

}
*/




extern void print_migration_details()
{
	printf("\nMIGRATION COST\t %d\n\n",migration_cost);
}

static int find_idlest_core(unsigned int flag)

{

    /*MAKE TRADE OFF IN THIS FUNCTION*/
    int core;
    int core1, core2;
    int i;
    int leastLength = INT_MAX;
    int leastCore = INT_MAX;
    int total_length = 0;
    if(flag==0)
    {
        /*pthread_mutex_lock(&run_mutex);*/

        for(i=0; i<NOC; i++)
        {
            if(leastLength>run_queue[i]->length)
            {

                leastCore = i;

                leastLength = run_queue[i]->length;

            }

        }
        /*pthread_mutex_unlock(&run_mutex);*/

        core = leastCore;
    }

    else
    {
        /*MAKE TRADE OFF HERE ... IF LOAD IS GREATER THAN waht it should be migrate it to other core*/

        core1 = find_idlest_core_group(get_group_id(flag));

        for(i=0; i<NOC; i++)
            total_length += run_queue[i]->length;
        if( ( ( (run_queue[core1]->length)+1)*10)/((float)(total_length+1)) > optimum_core_load)
        {
            leastLength = INT_MAX;
            leastCore = INT_MAX;
            /*pthread_mutex_lock(&run_mutex);*/
            for(i=0; i<NOC; i++)
            {
                if(leastLength>run_queue[i]->length)
                {
                    leastCore = i;
                    leastLength = run_queue[i]->length;
                }
            }
            /*pthread_mutex_unlock(&run_mutex);*/
            core2 = leastCore;
            if( ( ( (run_queue[core2]->length)+1)*10)/((float)(total_length+1)) > optimum_core_load*0.5)
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
   
	    if(pcb->prev_cpu_id==10000)

		core = find_idlest_core(0);

	    else

		core = find_idlest_core(pcb->prev_cpu_id);

	    if(core!=pcb->prev_cpu_id){
	pcb->prev_vruntime=pcb->vruntime;
	    pcb->vruntime=0;

	    }
	    sorted_enqueue(run_queue[core],pcb);
        
               
}





static unsigned int get_group_id(unsigned int cpu_id)
{

    return group_cores[cpu_id];

}

static void* schedule_next_process()
{
    pcb_t* pcb;
    int i,j;
    struct QNode* node;
            
		for(i=0; i<NOQ; i++)
		{
		    size_of_chunk[i] = ready_queue[i]->length/no_of_chunks[i];
		    if(size_of_chunk[i]<1)
		        size_of_chunk[i]=1;

		    for(j=0; j<size_of_chunk[i]; j++)
		    {
			node = deQueueAtFront(ready_queue[i],1);
		        if(node==NULL)
				{
					pcb=NULL;
					break;				
				}
		        pcb = node->key;
		      dispatch_process(pcb);
		    }
		}
	    
	       return NULL;
           

}


extern  void wake_up( pcb_t *pcb)
{
    int flag = 0; 
    int i;

    if(SCHEDULING_TYPE==3)
    {  
       pthread_mutex_lock(&current_mutex);
          for(i=0;i<NOC;i++)
            { 
               if(current[i]==NULL)
		  {
                    flag=1; 
		    break;  	
                  }
            }
 
          if(flag==1)
	    {
               pcb->state = PROCESS_READY;
		       placeInQueue(pcb);    
            }

           else
            {    
		  for(i=0;i<NOC;i++)
		    {
		       if(current[i]->priority > pcb->priority)
		          {
		            flag=2;
		            break;     
			  } 
		    }   
		    if(flag==0)
		    {
		       pcb->state = PROCESS_READY;
		       placeInQueue(pcb);  
		    }
		    
		    if(flag==2)
		    {
		       force_preempt(i);	
		       pcb->state = PROCESS_READY;   
		       placeInQueue(pcb);
		    }  
             } 
         pthread_mutex_unlock(&current_mutex);
    }
    else
    {
	  pcb->state = PROCESS_READY;
	  placeInQueue(pcb);
    }
}



extern  void schedule(unsigned int cpu_id)
{
                
        pcb_t *pcb = NULL;
	struct QNode* node=NULL;
	int i,j,total_length=0;
	int highest_utilized_core = INT_MIN;
	int highest_length = INT_MIN;
             
             if(SCHEDULING_TYPE==0)
               {  
			pthread_mutex_lock(&current_mutex);
			schedule_next_process();
			node = deQueueAtFront(run_queue[cpu_id],0); 


		    if(node!=NULL)
		    {

			pcb= node->key;

			current[cpu_id] = pcb;

			pcb->state=PROCESS_RUNNING;

		    }

		    else
		    {
			pcb=NULL;
			for(j=0;j<NOC;j++)total_length+=run_queue[j]->length;

			for(i=0; i<NOC; i++)
			{
				
			    if(group_cores[i]==get_group_id(i) && run_queue[i]->length>highest_length&& run_queue[i]->length/(float)total_length> optimum_core_load)
			    {

				highest_utilized_core = i;

				highest_length = run_queue[i]->length;

			    }

			}

			if(highest_utilized_core!=INT_MIN)
			node = deQueueAtFront(run_queue[highest_utilized_core],0);

			if(node!=NULL)

			    pcb = node->key;
			else pcb=NULL;
		    }
	

		    if(pcb==NULL)

		    {

			highest_utilized_core = INT_MIN;

			highest_length = INT_MIN;

			for(i=0; i<NOC; i++)
			{

			    if(run_queue[i]->length>highest_length)
			    {

				highest_utilized_core = i;

				highest_length = run_queue[i]->length;

			    }
			}
			node = deQueueAtFront(run_queue[highest_utilized_core],0);


			if(node!=NULL)

			    pcb = node->key;
			else pcb=NULL;
		    }
			/*if(pcb==NULL)
			printf("\ncontext12345\n===============++++++++++++++++++++++++++++++============ with NULL\t\n\n");
			else printf("\nCONTEXT SWITCH WITH NOT NULL\n");       */ 
			current[cpu_id] = pcb;
			if(pcb!=NULL){
			pcb->state=PROCESS_RUNNING;
			if(pcb->prev_cpu_id!=cpu_id)
				{
					if( (pcb->prev_cpu_id!=10000 )&& (get_group_id(pcb->prev_cpu_id)!=get_group_id(cpu_id)) )
					migration_cost+=LEVEL2_MIG_COST*(pcb->prev_vruntime/100.0);
					pcb->prev_cpu_id=cpu_id;
				}
			}
			pthread_mutex_unlock(&current_mutex);
			context_switch(cpu_id,pcb,TIME_SLICE);
                   }

                  else if(SCHEDULING_TYPE==2)
                   {
			node = deQueueAtFront(ready_queue[0],1);
			 pthread_mutex_lock(&current_mutex);
			pcb=NULL;			
			if(node!=NULL)	
			 {		
                               pcb = node->key;
				pcb->state=PROCESS_RUNNING;
				if(pcb->prev_cpu_id!=cpu_id)
				{
					if( (pcb->prev_cpu_id!=10000 )&& (get_group_id(pcb->prev_cpu_id)!=get_group_id(cpu_id)) )
					{migration_cost+=LEVEL2_MIG_COST*(pcb->prev_vruntime/100.0);pcb->prev_vruntime=pcb->vruntime;pcb->vruntime=0;}
					pcb->prev_cpu_id=cpu_id;
				}

			}
		                current[cpu_id] = pcb;						
				pthread_mutex_unlock(&current_mutex);
				context_switch(cpu_id,pcb,-1);  
		
		   }
                
                  else if(SCHEDULING_TYPE==3)
                   {
			node = deQueueAtFront(ready_queue[0],1);
			 pthread_mutex_lock(&current_mutex);
			pcb=NULL;			
			if(node!=NULL)	
			 {		
                               pcb = node->key;
				pcb->state=PROCESS_RUNNING;
				if(pcb->prev_cpu_id!=cpu_id)
				{
					if( (pcb->prev_cpu_id!=10000 )&& (get_group_id(pcb->prev_cpu_id)!=get_group_id(cpu_id)) )
					{migration_cost+=LEVEL2_MIG_COST*(pcb->prev_vruntime/100.0);pcb->prev_vruntime=pcb->vruntime;pcb->vruntime=0;}
					pcb->prev_cpu_id=cpu_id;
				}

			}
		                current[cpu_id] = pcb;						
				pthread_mutex_unlock(&current_mutex);
				context_switch(cpu_id,pcb,-1);  
		
		   }     
 
}



int main(int argc,char** argv)

{
    /*NOC=atoi(argv[1]);int i;*/

    if(argc<2)
    {
        printf("WHAT HAVE YOU GIVEN ME\t EXPECTING SOME OTHER THING :P");
        exit(0);
    }

   SCHEDULING_TYPE = atoi(argv[2]);
    if(SCHEDULING_TYPE<0&&SCHEDULING_TYPE>2){
      printf("\n Give valid schediuling algorithm..");     
      return 1; 
    }  

   if(SCHEDULING_TYPE==0||SCHEDULING_TYPE==1)
     TIME_SLICE=atoi(argv[3]);
   
    pthread_mutex_init(&ready_queue_mutex,NULL);
    pthread_mutex_init(&run_mutex,NULL);
    pthread_mutex_init(&current_mutex,NULL);
    initialise_ready_and_run_queue();

    migration_cost=0;
    optimum_core_load=100.0/NOC;
    start_simulator(NOC);
    return 0;
}
