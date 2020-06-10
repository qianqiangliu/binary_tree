#ifndef _STACK_H_
#define _STACK_H_

typedef struct {
    void **stack;
    int size;
    int index;
} stack_t;

stack_t *stack_init(int size);
void stack_destroy(stack_t *s);
int is_stack_full(const stack_t *s);
int is_stack_empty(const stack_t *s);
void *stack_top(const stack_t *s);
int stack_push(stack_t *s, void *elem);
void *stack_pop(stack_t *s);

#endif /* _STACK_H_ */
