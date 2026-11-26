# include <stdio.h>
# include <stdlib.h>
struct doubly{
    int data;
    struct doubly *prev;
    struct doubly *next;
}
;
struct doubly *head=NULL;
struct doubly *tail=NULL;

void insert(int value){
    struct doubly *newnode;
    newnode=malloc(sizeof(struct doubly));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void displayfwd(){
    struct doubly *temp = head;
    printf("\n fwd direction");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void displayback(){
    struct doubly *temp = tail;
    printf("\n backward direction");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->prev;
    } 
}

int main(){
    int n, value;
    printf("Enter number of nodes of doubly linked list");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element");
        scanf("%d",&value);

        insert(value);
    }
    displayfwd();
    displayback();
    return 0;
}
