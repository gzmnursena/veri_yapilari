#include <stdio.h>
#include <stdlib.h>

struct  Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

int main() {
    node * root;
    root=(node *)malloc(sizeof(node));
    root->data=10;
    root->next=(node *)malloc(sizeof(node));
    root->next->data=20;
    root->next->next=(node *)malloc(sizeof(node));
    root->next->next->data=30;

    node *iter;
    iter=root;
    printf("%d\n",iter->data);
    iter=iter->next;
    printf("%d\n",iter->data);

    return 0;
}