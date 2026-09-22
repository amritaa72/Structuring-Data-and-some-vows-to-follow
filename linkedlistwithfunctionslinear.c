#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

//traversal
void printlist(struct node* head){
    struct node* current = head;
    printf("Linked List : ");
    while(current!=NULL){
        printf("%d->", current-> data);
        current = current-> next; // move to next node 
           }
    printf("NULL\n");
}

//for a node at the beginning 
void insertathead(struct node** head_ref, int new_data ){
    //alocate memory for new node on the heap
    struct node* new_node= malloc(sizeof(struct node));

    //check if memory allocation was successful 
    if(new_node==NULL){
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data=new_data;
    new_node->next=(*head_ref);
    *head_ref=new_node;
}

//free memory allocated for th elist
void freelist(struct node* head){
    struct node* temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp); //free each node safely
    }
}

int main(){
    //initialise an  empty list 
    struct node* head= NULL;
    insertathead(&head,40);
    insertathead(&head,30);
    insertathead(&head,20);
    insertathead(&head,10);
    printlist(head);
    freelist(head);

    return 0;
}
