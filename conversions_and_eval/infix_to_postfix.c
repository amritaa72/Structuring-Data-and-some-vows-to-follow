//expression to postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

struct stack{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, char item){
    if (s->top >= SIZE-1)
        return;
    s->data[++(s->top)]= item;

}

char pop(STACK *s){
    if (s->top < 0)
        return '\0';
    return s->data[(s->top)--];
}

int preceed(char symbol){
    switch(symbol)
    {
        case '+' :
        case '-':
            return 1;
        case '*':
        case '/': 
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixtopostfix(STACK *s, const char infix[SIZE], char postfix[SIZE])
{
    int i,j=0;
    char temp,symbol;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))
            postfix[j++]=symbol;
        else if(symbol=='(')
            push(s,symbol);
        else if(symbol==')')
        {
            while(1)
            {
                temp = pop(s);
                if (temp == '\0' || temp == '(')
                    break;
                postfix[j++]=temp;
            }
        }
        else
        {
            while(s->top != -1 && preceed(s->data[s->top])>=preceed(symbol))
                postfix[j++]=pop(s);
            push(s,symbol);
        }
    }
    while (s->top != -1)
        postfix[j++]=pop(s);
    postfix[j]='\0';

}


int main()
{
    STACK s;
    s.top=-1;
    char infix[SIZE];
    char postfix[SIZE];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    infixtopostfix(&s,infix,postfix);
    printf("Postfix expression: %s\n",postfix);
    return 0;
}
