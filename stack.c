#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack_t *stack_init(int size)
{
    stack_t *s = malloc(sizeof(stack_t));
    if (s == NULL)
        return NULL;

    s->stack = malloc(size * sizeof(void *));
    if (s->stack == NULL) {
        free(s);
        return NULL;
    }
    s->size = size;
    s->index = -1;
    return s;
}

void stack_destroy(stack_t *s)
{
    if (s) {
        free(s->stack);
        free(s);
        s = NULL;
    }
}

int is_stack_full(const stack_t *s)
{
    if (s->index == s->size - 1)
        return 1;
    else
        return 0;
}

int is_stack_empty(const stack_t *s)
{
    if (s->index == -1)
        return 1;
    else
        return 0;
}

void *stack_top(const stack_t *s)
{
    if (is_stack_empty(s))
        return NULL;
    return s->stack[s->index];
}

int stack_push(stack_t *s, void *elem)
{
    if (is_stack_full(s))
        return -1;
    s->index++;
    s->stack[s->index] = elem;
    return 0;
}

void *stack_pop(stack_t *s)
{
    if (is_stack_empty(s))
        return NULL;
    void *elem = s->stack[s->index];
    s->index--;
    return elem;
}
