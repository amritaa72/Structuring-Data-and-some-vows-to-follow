#include <stdio.h>
#include <stdlib.h>

//structre for a node
struct node{
    int data;
    struct node*next;
};

void insertathead(struct node** head_ref,int new_data){
    struct node* newnode = malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n [ERROR] memory alloccation failed\n");
        return;
    }
    newnode->data=new_data;
    newnode->next=(*head_ref);
    *head_ref=newnode;
    printf("\n [Success] %d inserted at the begining.\n",new_data);

}

void insertattail(struct node** head_ref, int new_data){
    struct node* new_node = malloc (sizeof(struct node));
    if(new_node==NULL){
        printf("\n[ERROR] Memory allocation failed \n");
        return;
    }
    new_node->data= new_data;
    new_node->next=NULL;

    //edge case = if list empty new node is head
    if(*head_ref==NULL){
        *head_ref = new_node;
        printf("\n [SUCCESS]%d inserted as the fist node.\n",new_data);
        return;
        }

    //travese to find last node 
    struct node* last = *head_ref;
    while(last->next != NULL ){
        last= last->next;
    }
    last->next = new_node; //link old tail to new tail
    printf("\n [SUCCESS] %d inserted at the end. \n", new_data);
}

//traverse and display whole list 
void displaylist(struct node* head){
    if(head==NULL){
        printf("\n Linked list is completely empty.\n");
        return;
    }

    struct node* current = head;
    printf("\n Current linked list:");
    while(current!= NULL){
        printf("%d->", current->data);
        current=current->next;
    }
    printf("NULL\n");
}

/*Whenever you create a node in C using the malloc() function, 
the computer carves out a small block of memory from a temporary storage zone called the heap.
Unlike normal local variables (which automatically disappear when a function finishes),
 heap memory never cleans itself up. It stays occupied until you explicitly tell the computer to release it.
 The freeList utility function acts like a cleaning crew. It goes through every single node in your linked list, 
 one by one, and returns that memory back to your operating system. */

 /*if you DON'T use it? 
 (Memory Leaks)If you close your program (or delete nodes) without calling
  free(), that memory remains marked as "in use" by your computer,
   even though your program no longer has any way to access it.
    This is called a Memory Leak.If a program runs for a long time 
    (like a web server or a video game) and keeps leaking memory, 
    it will eventually run your entire computer completely out of RAM, 
    causing the program or your whole operating system to crash. */

void deletenode(struct node** head_ref,int key ){
    struct node* temp = *head_ref;
    struct node* prev= NULL;

    //case 1= node to delete in the head itself
    if (temp!=NULL && temp->data ==key)
    {
        *head_ref=temp->next;
        free(temp);
        printf("\n[SUCCESS] Node with value %d deleted \n", key);
        return;
    }

    //case 2 - search for the node to be deleted, keeping track of previous nodes
    while(temp!=NULL && temp->data!=key){
        prev= temp;
        temp=temp->next;
    }

    //if key aint in da list 
    if(temp==NULL){
        printf("\n [WARNING] Value %d not found in the list \n", key);
        return;
    }
     // when found unlink node from linked list and free its memory
     prev->next=temp->next;
     free(temp);
     printf("\n [SUCCESS] Node withh value %d deleted\n",key);
}

void searchnode(struct node* head, int key){
    struct node* current = head;
    int position= 1;
    while(current!= NULL){
        if(current->data==key){
            printf("\n [FOUND] Value %d is present at the position %d \n",key, position);
            return;
        }
        current=current->next;
        position++;
    }
    printf("\n [NOT FOUND] Value %d doesnt exist in the list\n",key);

}

void updatenode(struct node* head, int old_value, int new_value){
    struct node* current = head;
    while(current!=NULL){
        if(current->data==old_value){
            current->data=new_value;
            printf("\n [SUCCESS] Value updated from %d to %d \n",old_value, new_value);
            return;
        }
        current= current->next;
    }
    printf("\n[ERROR] Value %d not found, Update failed.\n",old_value);

}


void freelist(struct node* head){
    struct node* temp;
    while(head!=NULL){
        temp= head;
        head= head->next;
        free(temp);
    }
}

//final loop
int main(){
    struct node* head = NULL;
    int choice, value, new_value;
    while(1){
        printf("\n---------------------------------");
        printf("\n   LINKED LIST OPERATIONS     \n ");
        printf("\n---------------------------------");

        printf("\n 1. Insert at beginning (head)");
        printf("\n2. Insert at the END (Tail)");
        printf("\n3.Display Entire List" );
        printf("\n4. Delete a node in list");
        printf("\n5. Search for a value in the list");
        printf("\n6.Update a value in the list");
        printf("\n.7 Exit the program");
        printf("\nEnter you choice(1-)");
    

        if (scanf("%d", &choice)!=1)
        {
            printf("\n [ERROR ]Invalid input type, Enter a valid choice\n");
            while(getchar()!='\n');

            continue;
        }

        switch(choice){
            case 1:
                printf("Enter integer value to insert: ");
                scanf("%d",&value);
                insertathead(&head, value);
                break;

            case 2:
                printf("Enter integer value to insert :");
                scanf("%d",&value);
                insertattail(&head,value);
                break;
            case 3:
                displaylist(head);
                break;
            case 4:
                printf("\nEnter value to delete :");
                scanf("%d",&value);
                deletenode(&head, value);
                break;
            case 5:
                printf("\nEnter value to search: ");
                scanf("%d",&value);
                searchnode(head,value);
                break;
            case 6:
                printf("Enter the value to replace : ");
                scanf("%d",&value);
                printf("Enter the new value  : ");
                scanf("%d",&new_value);
                updatenode(head,value,new_value);
                break;
            case 7:
                printf("\n FREEING MEMORY BLOCKS AND CLOSING APPLICATION\n");
                freelist(head);
                exit(0);
            default:
                //handle inputs outta 7
                printf("\n[WARNING] Invalid option! PLease enter a value between (1-7)\n");



        }
    }
    return 0;
}
