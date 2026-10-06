#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    return stack[top--];
}

int isMatching(char open, char close)
{
    if (open=='('&& close==')')
        return 1;
    if (open=='{'&& close=='}')
        return 1;
    if(open=='['&& close==']')
        return 1;
    
    return 0; //if none return 1 it'd get to this last line return 0
    
}

int isBalanced(char exp[])
{
    int i;

    for(i=0;exp[i]!='\0';i++)
    {
        if (exp[i]=='('|| exp[i]=='['|| exp[i]=='{')
        {
            push(exp[i]);
        }

        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if (top==-1)
                return 0;
            if (!isMatching(pop(),exp[i]))
                return 0;
        }
    }

    //stack must be empty
    if(top==-1)
    {
        return 1;
    }
    else 
        return 0;
}

int main()
{
    char exp[SIZE];

    printf("Enter an expression :");
    //scanf("%s",exp);
    //DOESNT ACCOUNT FOR WHITE-SPACES
    //It literally decides the expression ends where ever it encountered a white space
    //so that's why a perfectly balanced expression like this one got an out put that it wasnt balanced
    /*Enter an expression :9x-(6*x^3 - 8x^9)[(51+66)-(15+10)]^{15x^9} 
    NOT BALANCED*/

    scanf("%[^\n]",exp);
    //Keep reading everything until the user presses Enter
    /*Enter an expression :9x-(6*x^3 - 8x^9)[(51+66)-(15+10)]^{15x^9} 
    BALANCED*/

    if(isBalanced(exp))
        printf("\n BALANCED");
    else
        printf("\nNOT BALANCED");
    
        return 0;
}

