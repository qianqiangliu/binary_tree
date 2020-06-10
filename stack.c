#include <stdlib.h>

#include "stack.h"

struct stack *stack_init(int size)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL)
        return NULL;

    s->array = malloc(size * sizeof(void *));
    if (s->array == NULL) {
        free(s);
        return NULL;
    }
    s->size = size;
    s->index = -1;
    return s;
}

void stack_destroy(struct stack *s)
{
    if (s) {
        free(s->array);
        free(s);
        s = NULL;
    }
}

int is_stack_full(const struct stack *s)
{
    if (s->index == s->size - 1)
        return 1;
    else
        return 0;
}

int is_stack_empty(const struct stack *s)
{
    if (s->index == -1)
        return 1;
    else
        return 0;
}

void *stack_top(const struct stack *s)
{
    if (is_stack_empty(s))
        return NULL;
    return s->array[s->index];
}

int stack_push(struct stack *s, void *elem)
{
    if (is_stack_full(s))
        return -1;
    s->index++;
    s->array[s->index] = elem;
    return 0;
}

void *stack_pop(struct stack *s)
{
    if (is_stack_empty(s))
        return NULL;
    void *elem = s->array[s->index];
    s->index--;
    return elem;
}
