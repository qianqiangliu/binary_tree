#include <iostream>
#include <stack>

struct binary_tree {
    int elem;
    struct binary_tree *left;
    struct binary_tree *right;
};

int visit(const struct binary_tree *node)
{
    std::cout << node->elem << " ";
    return 0;
}

void pre_order(const struct binary_tree *root, int (*visit)(const struct binary_tree *))
{
    const struct binary_tree *p = root;
    std::stack<const struct binary_tree *>s;

    if (p)
        s.push(p);
    while (!s.empty()) {
        p = s.top();
        s.pop();
        visit(p);
        if (p->right)
            s.push(p->right);
        if (p->left)
            s.push(p->left);
    }
}

void in_order(const struct binary_tree *root, int (*visit)(const struct binary_tree *))
{
    const struct binary_tree *p = root;
    std::stack<const struct binary_tree *>s;

    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            visit(p);
            s.pop();
            p = p->right;
        }
    }
}

void post_order(const struct binary_tree *root, int (*visit)(const struct binary_tree *))
{
    const struct binary_tree *p = root;
    const struct binary_tree *q;
    std::stack<const struct binary_tree *>s;

    do {
        while (p) {
            s.push(p);
            p = p->left;
        }
        q = NULL;
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (p->right == q) {
                visit(p);
                q = p;
            } else {
                s.push(p);
                p = p->right;
                break;
            }
        }
    } while (!s.empty());
}

int main()
{
    struct binary_tree b1;
    struct binary_tree b2;
    struct binary_tree b3;
    struct binary_tree b4;

    b1.elem = 1;
    b1.left = &b2;
    b1.right = &b3;

    b2.elem = 2;
    b2.left = NULL;
    b2.right = &b4;

    b3.elem = 3;
    b3.left = NULL;
    b3.right = NULL;

    b4.elem = 4;
    b4.left = NULL;
    b4.right = NULL;

    pre_order(&b1, visit);
    std::cout << std::endl;

    in_order(&b1, visit);
    std::cout << std::endl;

    post_order(&b1, visit);
    std::cout << std::endl;

    return 0;
}
