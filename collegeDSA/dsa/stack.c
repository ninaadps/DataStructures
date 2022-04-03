#include<stdio.h>
#include<stdlib.h>

int top=-1;
int SIZE=3;
int arr[10];
void push(int item)
{
    if(top==SIZE-1)
    {
        printf("stack is full\n");
    }
    else{
        printf("item inserted: %d ",item);
        top++;
        arr[top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty");

    }
    else
    {
        printf("deleted item: %d ",arr[top--]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack is emty");
    }
    else{
        printf("elements of stack are: \n ");
        for(int i=0;i<=top;i++)
        {
            printf("%d ",arr[i]);
        }
    }
}
void main()
{    int item,c;
while(1)
{
    printf("enter operation 1.push 2.pop 3.display 4.exit\n");
    scanf("%d",&c);

    if(c==1)
    {
        printf("enter item to be inerted");
        scanf("%d",&item);
        push(item);
    }
    else if(c==2)
    {
        pop();
    }
    else if(c==3)
    {
    display();
    }
    else if(c==4)
    {
        exit(0);
    }

}
}