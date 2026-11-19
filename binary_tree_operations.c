#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//node creation
struct node* createnode(int value){
    struct node *newnode;
    newnode= malloc(sizeof(struct node));
    newnode->data=value;
    newnode->right=NULL;
    newnode->left= NULL;

    return newnode;
};

//preorder traversal
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//inorder
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

//postorder
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}

int main(){
    struct node *root, *newnode, *temp;
    struct node *queue[100];
    int front =0,rear=0;
    int choice,ch;

    //create root
    root=malloc(sizeof(struct node));
    printf("\nEnter root data :");
    scanf("%d",&root->data);

    root->left=NULL;
    root->right=NULL;

    queue[rear++]=root;

    while(front<rear)
    {
        temp=queue[front++];

        //left child
        printf("Does %d have a left child? (1/0): " , temp->data);
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\n Enter left child data : ");
            newnode=malloc(sizeof(struct node));
            scanf("%d",&newnode->data);

            newnode->left=NULL;
            newnode->right=NULL;

            temp->left=newnode;
            queue[rear++]=newnode;

        }
    

        //right child 
        printf("Does %d have a right child? (1/0): ",temp->data);
        scanf("%d",&choice);

        if(choice==1)
        {
            newnode = malloc(sizeof(struct node));

            printf("Enter right child data : ");
            scanf("%d",&newnode->data);

            newnode->left=NULL;
            newnode->right=NULL;

            temp->right=newnode;
            queue[rear++]=newnode;
        }

    }
    //traversal menu
    printf("\nChoose Traversal:\n");
    printf("1.Inorder\n");
    printf("2.Preorder\n");
    printf("3.Postorder \n");
    
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Inorder : ");
            inorder(root);
            break;
        case 2:
            printf("Preorder : ");
            preorder(root);
            break;
        case 3:
            printf("Postorder :  ");
            postorder(root);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}
