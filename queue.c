#include <stdlib.h>
#include <stdio.h>
#include "simulator.h"

struct QNode
{
     pcb_t *key;
    struct QNode *next;
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
extern struct QNode *deQueue(struct Queue *q);

extern void printQueue(struct Queue *q)
{
  struct QNode* temp = q->front;
  if(temp==NULL)
    return;

  printf("Length is:%d\n",q->length);
  /*while(temp!=q->rear)
  {
     printf("%d\t%d\t%d\n",temp->key->pid,temp->key->priority,temp->key->cpu_id);
     temp = temp->next;
  }
  printf("%d\t%d\t%d\n",temp->key->pid,temp->key->priority,temp->key->cpu_id);
*/
}

extern struct QNode* newNode( pcb_t *p)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = p;
    temp->next = NULL;
    return temp;
}

extern struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->length = 0;
    return q;
}

extern void enQueue(struct Queue *q,  pcb_t* p)
{
    struct QNode *temp = newNode(p);
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       q->length++;
       return;
    }
    q->rear->next = temp;
    q->rear = temp;
    q->length++;
}

extern struct QNode *deQueue(struct Queue *q)
{
    if (q->front == NULL)
       return NULL;
    struct QNode *temp = q->front;
    q->front = temp->next;
    if (q->front == NULL)
       q->rear = NULL;
    q->length--;
    return temp;
}
