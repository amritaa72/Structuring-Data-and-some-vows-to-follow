#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;

};

struct node *head= NULL;

//insertion at beginning
void insertatBeginning(int value){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=head;

}

//insert at end
void insertatEnd(int value){
    struct node *newnode;
    struct node *temp;

    newnode=malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=NULL;

    //handling if empty list
    if(head==NULL){
        head=newnode;
        return;
    }

    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
//insert at a a location
void insertatLocation(int value, int position){
    struct node *newnode;
    struct node *temp;

    int i;
    newnode=malloc(sizeof(struct node));

    newnode->data=value;

    if(position==1){
        newnode->next=head;
        head=newnode;
        return;
    }

    temp=head;

    for(i=1;i<position-1 && temp!=NULL;i++){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid Position\n");
        free(newnode);
        return;

    }

    newnode->next=temp->next;
    temp->next=newnode;
}

//deletion at beginning
void deleteBeginning(){
    struct node *temp;
    
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }

    temp=head;
    head=head->next;

    free(temp);

}
//deletion at end
void deleteEnd(){
    struct node *temp;
    struct node *prev;

    if (head==NULL){
        printf("LIST IS EMPTY\n");
        return;
    }
    //in the presence of only ONE ELEMENT
    if(head->next==NULL){
        free(head);
    }

    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    //when null reached
    prev->next=NULL;

    free(temp);
}

//delete at a location
void deleteatLocation(int position){
    struct node *temp;
    struct node *prev;

    if(head==NULL){
        printf("LIST IS EMPTY\n");
        return;
    }

    if(position==1){
        temp=head;
        head=head->next;
        free(temp);
        return;
    }

    temp=head;

    for(int i=1;i<position-1 && temp!=NULL;i++){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }

    prev->next=temp->next;

    free(temp);
}

//display
void display(){
    struct node *temp=head;

    if(head==NULL){
        printf("LIST IS EMPTY\n");
        return;
    }

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    insertatEnd(10);
    insertatEnd(20);

    printf("Original list :\t");
    display();

    insertatBeginning(5);
    printf("After insertion at beginning\n");
    display();

    insertatLocation(15,3);
    printf("After inserton at position 3\n");
    display();

    insertatEnd(40);
    printf("After insertion at end\n");
    display();

    deleteBeginning();
    printf("After deleting at the beginning\n");
    display();

    deleteatLocation(3);
    printf("After deletion at postion 3\n");
    display();

    return 0;
}
