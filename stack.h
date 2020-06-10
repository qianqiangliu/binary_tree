#ifndef _STACK_H_
#define _STACK_H_

struct stack {
    void **array;
    int size;
    int index;
};

struct stack *stack_init(int size);
void stack_destroy(struct stack *s);
int is_stack_full(const struct stack *s);
int is_stack_empty(const struct stack *s);
void *stack_top(const struct stack *s);
int stack_push(struct stack *s, void *elem);
void *stack_pop(struct stack *s);

#endif /* _STACK_H_ */
