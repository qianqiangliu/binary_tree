#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef int tree_node_elem_t;

typedef struct binary_tree_node {
    struct binary_tree_node *left;
    struct binary_tree_node *right;
    tree_node_elem_t elem;
} binary_tree_node_t;

int visit(const binary_tree_node_t *node)
{
    printf("%d ", node->elem);
    return 0;
}

void pre_order_r(const binary_tree_node_t *root, int (*visit)(const binary_tree_node_t *))
{
    if (root == NULL)
        return;
    visit(root);
    pre_order_r(root->left, visit);
    pre_order_r(root->right, visit);
}

void in_order_r(const binary_tree_node_t *root, int (*visit)(const binary_tree_node_t *))
{
    if (root == NULL)
        return;
    in_order_r(root->left, visit);
    visit(root);
    in_order_r(root->right, visit);
}

void post_order_r(const binary_tree_node_t *root, int (*visit)(const binary_tree_node_t *))
{
    if (root == NULL)
        return;
    post_order_r(root->left, visit);
    post_order_r(root->right, visit);
    visit(root);
}

void pre_order(const binary_tree_node_t *root, int (*visit)(const binary_tree_node_t *))
{
    const binary_tree_node_t *p = root;
    struct stack *stack = stack_init(128);

    if (stack == NULL)
        return;

    if (p != NULL)
        stack_push(stack, (void *)p);

    while (!is_stack_empty(stack)) {
        p = stack_pop(stack);
        visit(p);

        if (p->right != NULL)
            stack_push(stack, p->right);
        if (p->left != NULL)
            stack_push(stack, p->left);
    }

    stack_destroy(stack);
}

void in_order(const binary_tree_node_t *root, int (*visit)(const binary_tree_node_t *))
{
    const binary_tree_node_t *p = root;
    struct stack *stack = stack_init(128);

    if (stack == NULL)
        return;

    while (p || !is_stack_empty(stack)) {
        if (p != NULL) {
            stack_push(stack, (void *)p);
            p = p->left;
        } else {
            p = stack_pop(stack);
            visit(p);
            p = p->right;
        }
    }

    stack_destroy(stack);
}

void post_order(const binary_tree_node_t *root, int (*visit)(const binary_tree_node_t *))
{
    const binary_tree_node_t *p = root;
    const binary_tree_node_t *q;
    struct stack *stack = stack_init(128);

    if (stack == NULL)
        return;

    do {
        while (p != NULL) {
            stack_push(stack, (void *)p);
            p = p->left;
        }
        q = NULL;
        while (!is_stack_empty(stack)) {
            p = stack_pop(stack);
            if (p->right == q) {
                visit(p);
                q = p;
            } else {
                stack_push(stack, (void *)p);
                p = p->right;
                break;
            }
        }
    } while (!is_stack_empty(stack));

    stack_destroy(stack);
}

int main(int argc, char **argv)
{
    binary_tree_node_t *root = malloc(sizeof(binary_tree_node_t));
    binary_tree_node_t *node1 = malloc(sizeof(binary_tree_node_t));
    binary_tree_node_t *node2 = malloc(sizeof(binary_tree_node_t));
    binary_tree_node_t *node3 = malloc(sizeof(binary_tree_node_t));

    root->left = node1;
    root->right = node2;
    root->elem = 1;

    node1->left = NULL;
    node1->right = NULL;
    node1->elem = 2;

    node2->left = NULL;
    node2->right = node3;
    node2->elem = 3;

    node3->left = NULL;
    node3->right = NULL;
    node3->elem = 4;

    pre_order_r(root, visit);
    puts("\n-------");
    in_order_r(root, visit);
    puts("\n-------");
    post_order_r(root, visit);
    puts("\n");

    pre_order(root, visit);
    puts("\n-------");
    in_order(root, visit);
    puts("\n-------");
    post_order(root, visit);
    puts("");

    return 0;
}
