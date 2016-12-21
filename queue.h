#include "process.h"

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

void printQueue(struct Queue *q);
struct QNode* newNode(pcb_t* k);
struct Queue *createQueue();
void enQueue(struct Queue *q,pcb_t* k);
struct QNode *deQueue(struct Queue *q);
