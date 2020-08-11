#include <stdio.h>
#include <stdlib.h>

struct  n {
    int data;
    struct n *next;
};
typedef struct n node;

void yazdir(node *r)
{
    printf("\n\nyazdir\n\n=");
    while(r!=NULL){
        printf("%d\n",r->data);
        r=r->next;
    }
}

int main() {
    node * root;
    root=(node *)malloc(sizeof(node));
    root->data=10;
    root->next=(node *)malloc(sizeof(node));
    root->next->data=20;
    root->next->next=(node *)malloc(sizeof(node));
    root->next->next->data=30;
    root->next->next->next=NULL;

    node *iter;
    iter=root;
    printf("%d\n",iter->data);
    iter=iter->next;
    printf("%d\n",iter->data);

    int i=0;
    while(iter!=NULL){
        i++;
        printf("%d. eleman= %d\n",i,iter->data);
        iter=iter->next;
    }

    for(int i=0;i<5;i++){
        iter->next=(node *) malloc(sizeof(node));
        iter=iter->next;
        iter->data=i*10;
        iter->next=NULL;

        //printf("%d\n",iter->data);
    }
    yazdir(root);

    while(iter!=NULL){
        printf("%d\n",root->data);
        root=root->next;
    }

    return 0;
}