#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int SIZE=3;
int arr[10];
void enq(int item)
{
    if(rear==SIZE-1)
    {
        printf("queue is full\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    
            printf("item inserted: %d ",item);
        rear++;
        arr[rear]=item;
    }

void deq()
{
    if(front==-1 || front>rear)
    {
        printf("queue is empty");
        return;

    }
    
        printf("deleted item: %d ",arr[front]);
        front++;
    
}
void display()
{
    if(front==-1)
    {
        printf("queue is emty \n");
    }
    else{
        printf("elements of queue are: \n ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",arr[i]);
        }
    }
}
void main()
{    int item,c;
for(;;)
{
    printf("enter operation 1.push 2.pop 3.display 4.exit\n");
    scanf("%d",&c);

    if(c==1)
    {
        printf("enter item to be inerted");
        scanf("%d",&item);
        enq(item);
    }
    else if(c==2)
    {
        deq();
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