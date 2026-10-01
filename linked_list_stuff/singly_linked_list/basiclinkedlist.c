#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *p= NULL;
    struct node *q = NULL;

    p= malloc(sizeof(struct node));
    p-> data = 10;
    p-> next =NULL;

    q=malloc(sizeof(struct node));
    q->data = 20;
    q->next=NULL;

    //link node p to q
    p-> next =q;

    printf("Node p: Data =%d , Next Points to node q\n",p-> data);
    printf("Node q: Data =%d, Next Points to %p (NULL)\n",p->next->data,(void*)q->next);

}
