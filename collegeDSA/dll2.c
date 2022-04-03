#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,n,type) ((p)=(type*)malloc(n * sizeof(struct node)));
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void ins_beg()
{  int item;
    struct node *ptr;
    MALLOC(ptr,1,struct node);
    printf("enter item\n");
    scanf("%d",&item);
    if(head==NULL)
    { ptr->data=item;
    ptr->prev=NULL;
    ptr->next=NULL;
    head=ptr;
    }
    else{ ptr->data=item;
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
}
void insert_lst()
{
    int item;
    struct node *ptr;
    struct node *cur;
    MALLOC(ptr,1,struct node);
    printf("enter item\n");
    scanf("%d",&ptr->data);
    if(head==NULL)
    { 
    ptr->prev=NULL;
    ptr->next=NULL;
    head=ptr;
    }
    else{
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=ptr;
    ptr->prev=cur;
    ptr->next=NULL;
}
}

void insert_any()
{
    int item,pos;
    struct node *ptr;
    struct node *temp1;
    struct node *temp2;
    MALLOC(ptr,1,struct node);
    printf("enter data\n");
    scanf("%d",&ptr->data);
    printf("enter the postion\n");
    scanf("%d",&pos);
    temp1=head;
    int i=1;
    while(i<pos)
    { temp2=temp1;
      temp1=temp1->next;
      i++;
    }
    temp2->next=ptr;
    ptr->prev=temp2;
    ptr->next=temp1;
    temp1->prev=ptr;


}
void display()
{
    struct node *ptr;
        ptr=head;
      while(ptr!=NULL)
      {
          printf("%d ",ptr->data);
          ptr=ptr->next;
      }
      printf("\n");
    
}
void delete_first()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("empty list\n");
        
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else{
        ptr=head;
        head=head->next;
        head->prev=NULL;

        free(ptr);
    }
}

void delete_last()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("list mpty\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else{
        ptr=head;
        while(ptr->next!=NULL)
        {   
            ptr=ptr->next;
        }
        ptr->prev->next=NULL;
        free(ptr);

    }
}
void delete_any()
{   int pos;
    struct node *temp,*ptr;
    printf("enter the position of deletion\n");
   scanf("%d",&pos);
   int i=1;
   ptr=head;
   while(i<pos)
   {
       temp=ptr;
       ptr=ptr->next;
       i++;
   }
  temp->next=ptr->next;
  ptr->next->prev=temp;
  free(ptr);


}
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last \n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            ins_beg();  
            break;  
            case 2:  
                    insert_lst();  
            break;  
            case 3:  
            insert_any();  
            break;  
            case 4:  
            display();  
            break;  
            case 5:  
            delete_first();  
            break; 
            case 6:  
            delete_last();  
            break; 
            case 7:  
            delete_any();  
            break; 
            case 8:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  