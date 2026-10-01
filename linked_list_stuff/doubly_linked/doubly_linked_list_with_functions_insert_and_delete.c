#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head= NULL;

//insert at beginning
void insertatBeginning(int value){
    struct node *newnode= malloc(sizeof(struct node));

    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=head;

    if(head!=NULL){
        head->prev=newnode;
        return;
    }

    head=newnode;
}
//insertatlocation
void insertLocation(int value,int pos){
    struct node *newnode;
    struct node *temp;
    newnode = malloc(sizeof(struct node));

    newnode->data=value;

    if(pos==1){
        newnode->prev=NULL;
        newnode->next=head;

        if(head!=NULL)
        {
            head->prev= newnode;
        }
        head=newnode;

        return;
    }

    temp=head;
    //move temp to node before require position
    for(int i=1;i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid Position\n");
        free(newnode);
        return;
    }

    newnode->next=temp->next;

    newnode->prev=temp;

    if(temp->next!=NULL)
    {temp->next->prev=newnode;}

    temp->next=newnode;
}

//insert at end
void insertEnd(int value)
{
    struct node *newnode;
    struct node *temp;

    newnode=malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    //if list empty
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;

        return;
    }
    temp=head;

    //go to last node
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
}

//delete at beginning
void deleteBeginning(){

    struct node *temp;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    temp=head;

    head=head->next;

    if(head!=NULL){
        head->prev=NULL;
    }

    free(temp);
}

//delete at location
void deleteLocation(int pos){
    struct node *temp;

    if(head==NULL){
        printf("The list is EMPTY!\n");
        return;
    }

    temp=head;

    //move to the position
    for(int i=1; i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }

    //deleting at first node
    if(temp==head){
        head=head->next;

        if(head!=NULL)
            head->prev=NULL;
        
        free(temp);
        return;
    }

    //connect previous node to next
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    free(temp);
}

void deleteEnd(){
    struct node *temp = head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    //go to last node
    while(temp->next!=NULL){
        temp=temp->next;
    }

    //if only one node
    if (temp->prev==NULL)
    {
        head=NULL;
    }
    else{
        temp->prev->next=NULL;
    }

    free(temp);
}

void display(){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insertatBeginning(4);
    insertatBeginning(15);

    insertEnd(51);
    insertLocation(2,10);

    display();

    insertLocation(10,2);

    display();
    return 0;
}
