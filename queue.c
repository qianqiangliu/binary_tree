#include <stdlib.h>

#include "queue.h"

struct queue *queue_init(int size)
{
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL)
        return NULL;
    q->array = malloc(size * sizeof(void *));
    if (q->array == NULL) {
        free(q);
        return NULL;
    }
    q->size = size;
    q->front = 0;
    q->rear = 0;
    return q;
}

void queue_destroy(struct queue *q)
{
    if (q) {
        free(q->array);
        free(q);
        q = NULL;
    }
}

int is_queue_empty(struct queue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

int is_queue_full(struct queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
        return 1;
    else
        return 0;
}

int queue_push(struct queue *q, void *elem)
{
    if (is_queue_full(q))
        return -1;
    q->array[q->rear] = elem;
    q->rear = (q->rear + 1) % q->size;
    return 0;
}

void *queue_pop(struct queue *q)
{
    if (is_queue_empty(q))
        return NULL;
    void *elem = q->array[q->front];
    q->front = (q->front + 1) % q->size;
    return elem;
}
