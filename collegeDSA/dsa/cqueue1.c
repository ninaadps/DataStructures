#include<stdio.h>
#include<stdlib.h>
int front =-1;
int rear=-1;
int SIZE = 3;
int a[15];
void enq(int item)
{
    if(( front==0 && (rear==SIZE-1))|| front==rear+1)
    {
        printf("queue is full");
        return;
    }

    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%SIZE;
    a[rear]=item;

}
void deq()
{
    if(front==-1)
    {
        printf("queue is empty");
        return;
    }
    int element=a[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    
    front=(front+1)%SIZE;
    printf("deleted item: %d",element);
}

void display()
{
    if(front==-1)
    {
        printf("queue is empty");
        return;
    }
    int i;
    for( i=front;i!=rear;i=(i+1)%SIZE)
    {
        printf("%d",a[i]);
    }
    printf("%d",a[i]);
}
int main() {
   int item,c;
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

  return 0;
}