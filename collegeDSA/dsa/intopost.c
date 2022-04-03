#include<stdio.h>
#include<ctype.h>

char stack[50];
int top=-1;
void push(char x)
{
     stack[++top]=x;
}

char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else{
        return stack[top--];

    }
}

int priority(char x)
{   if(x=='(')
    {
     return 0;
    }
    if(x=='+' || x=='-')
    {
         return 1;
    }
    if(x=='*' || x=='/')
    {
        return 2;
    }
    if(x=='^')
    {
        return 3;
    }
}

void main()
{
    char ex[50];
    char *e,z;
    printf("enter the expression: \n");
    scanf("%s",ex);
    e=ex;
    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            printf("%c",*e);
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while((z=pop()) != '(')
            {
                printf("%c",z);
            }
        }
        else{
              if(priority(*e)<=priority(stack[top]))
              {
                printf("%c",pop());
              }
                push(*e);
              
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}