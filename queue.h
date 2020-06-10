#ifndef _QUEUE_H_
#define _QUEUE_H_

struct queue {
    void **array;
    int size;
    int front;
    int rear;
};

struct queue *queue_init(int size);
void queue_destroy(struct queue *q);
int is_queue_empty(struct queue *q);
int is_queue_full(struct queue *q);
int queue_push(struct queue *q, void *elem);
void *queue_pop(struct queue *q);

#endif /* _QUEUE_H_ */
