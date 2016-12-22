
#include <stdlib.h>
#include <stdio.h>
#include "simulator.h"
#include "queue.h"
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
    n = (struct QNode*)malloc(sizeof(struct QNode));
    n->key = p;
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

