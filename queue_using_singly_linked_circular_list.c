//using circular singly linked list implementing queue
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear= NULL;

//ENQUEUE
void enqueue(int value)
{
    struct node *newNode;
    newNode=malloc(sizeof(struct node));
    newNode->data=value;

    if(front==NULL)
    {
        front=rear=newNode;
        newNode->next=front;
    }
    else{
        newNode->next=front;
        rear->next=newNode;
        rear=newNode;
    }

}

//DEQUEUE
void dequeue()
{
    struct node *temp;
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }

    if(front==rear){
        temp=front;
        front=rear=NULL;
        free(temp);
    }

    else
    {
        temp=front;
        front=front->next;
        rear->next=front;
        free(temp);

    }
}

//display
void display()
{
    struct node *cur;
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }

    cur=front;
    do {
        printf("%d  ",cur->data);
        cur = cur->next;
    }
    while(cur!=front);

    printf("\n");
}

int main()
{
    int choice, value;
    while(1){
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    
    }
    return 0;
}