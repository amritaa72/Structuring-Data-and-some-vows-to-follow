#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node*next;
};

struct node *front = NULL;
struct node *rear = NULL;

//insert at front
void insertfront(int x){
    struct node *newnode;
    newnode= malloc(sizeof(struct node));

    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=front;

    if(front==NULL){
        front = rear= newnode;
    }
    else
    {
        front->prev=newnode;
        front=newnode;
    }
}

//insert at rear
void insertrear(int x)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));

    newnode->data=x;
    newnode->prev=rear;
    newnode->next=NULL;

    if(rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear= newnode;
    }
}
//delete at front
void deletefront(){
    struct node *temp;
    if(front==NULL){
        printf("DEQUEUE IS EMPTY\n");
    }
    else{
        temp=front;
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
            front->prev=NULL;
        }
        free(temp);
        printf("Front element deleted\n");
    }
}

//delete at rear
void deleterear()
{
    struct node *temp;
    if(rear==NULL)
    {
        printf("DEQUE EMPTY\n");
    }
    else
    {
        temp=rear;
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            rear=rear->prev;
            rear->next=NULL;
        }
        free(temp);
        printf("rear element deleted \n");
    }
}

//display
void display()
{
    struct node *temp;
    if (front==NULL)
    {
        printf("DEQUE EMPTY \n");
        return;
    }
    temp=front;
    printf("DEQUE :\n");
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int choice,x;
    while(1)
    {
        printf("\n-----DEQUE OPERATIONS-----\n");
        printf("1.INSERT FRONT \n");
        printf("2.INSERT REAR \n");
        printf("3.DELETE FRONT\n");
        printf("4.DELETE REAR\n");
        printf("5.DISPLAY\n");
        printf("6.EXIT\n");

        printf("Enter your choices :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter element : ");
                scanf("%d",&x);
                insertfront(x);
                break;
            case 2:
                printf("\nEnter element : ");
                scanf("%d",&x);
                insertrear(x);
                break;
            case 3:
                deletefront();
                break;
            case 4:
                deleterear();
                break;
            case 5:
                display();
                break;
            case 6:
                while(front!=NULL)
                    deletefront();
                printf("EXITING \n");
                return 0;
            default:
                printf("INVALID CHOICE!!\n");
        }
    }
    return 0;
}