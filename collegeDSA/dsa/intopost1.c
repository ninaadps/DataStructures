#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char s[50];
int top=-1;
void push(char x)
{
    s[++top]=x;

}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return s[top--];
    }
}
int priority(char x)
{
    if(x=='(')
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
    char str[50];
    char *e,z;
    printf("enter the expression\n");
    scanf("%s",str);
    e=str;
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
            while((z=pop())!='(')
            {
                printf("%c",z);
            }
        }
        else
        {
            if(priority(*e)<=priority(s[top]))
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