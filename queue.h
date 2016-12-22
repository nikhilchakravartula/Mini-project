#ifndef __QUEUE_H__
#define __QUEUE_H__
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

#endif
