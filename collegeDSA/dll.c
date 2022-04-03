#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, n,type)  ((p) = (NODE)malloc((n) * sizeof (type)));

struct node{
        struct node *llink;
        int info;
        struct node *rlink;
};

typedef struct node *NODE;

NODE insert_rear(NODE head,int item){
    NODE temp,cur;
    MALLOC(temp,1,struct node);
    temp->rlink=NULL;
    temp->info=item;
    temp->llink=NULL;
    if(head==NULL)
        return temp;
    cur=head;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    return head;
}

NODE insert_any(NODE head, int item,int pos){
    NODE temp,cur,prev=NULL; int count=1;
    MALLOC(temp, 1, NODE);
	temp->rlink=NULL;
    temp->info=item;
    temp->llink=NULL;
    if(head==NULL)
        return temp;
    cur=head;
    if(pos==1){
        temp->rlink=head;
        head->llink=temp;                                                                                                                                            return temp;
        }
    else{
        while(cur->rlink!=NULL&&count!=pos){
                        prev=cur;
            cur=cur->rlink;
                ++count;
            }

            if(count==pos){
                temp->rlink=cur;
                cur->llink=temp;
                temp->llink=prev;
                prev->rlink=temp;
                 } if(count==pos-1){
                        cur->rlink=temp;
                        temp->llink=cur;
                 }else{
                        printf("INDEX Out of bound\n");
                }

        }
        return head;
}

void display(NODE head){
    NODE cur;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    cur=head;
    printf("The contents of the list:\n");
    while(cur!=NULL){
        printf("%d ", cur->info);
        cur=cur->rlink;
    }
    printf("\n");
}

NODE del(NODE head,int key){
        NODE cur,prev,next;
        if(head==NULL){
                printf("Empty list\n");
                return head;
        }
        cur=head;
        if(head->info==key){
                head=head->rlink;
        }
        else{
                prev=NULL;
                while(cur->info!=key&&cur->rlink!=NULL){
                        prev=cur;
                        cur=cur->rlink;
                }
                if(cur->info==key){
                        next=cur->rlink;
                        prev->rlink=next;
                        if(next==NULL)
                                prev->rlink=NULL;
                        else
                        next->llink=prev;
                }
                else{
                        printf("KEY not found\n");
                        return head;
                }
        }
        printf("The deleted element is %d\n",cur->info);
        free(cur);
        return head;

}
int main(){
    NODE first =NULL;
	int choice, item,pos,key;
	printf("MENU:\n");                                                                            
	printf("1.Insert\t2.Delete\n3.Display\t4.Exit\n");
	        for(;;){

                printf("Enter choice:");
                scanf("%d", &choice);        
				switch(choice)
                {
                        case 2: printf("Enter key to be deleted:");
									scanf("%d", &key);
                                        first = del(first,key);
                                        break;
                        case 3: display(first);
                                        break;
                        case 1: printf("Enter element to be inserted:");
                                scanf("%d", &item);
                                        printf("Enter the position:");
                                        scanf("%d",&pos);
                                        first = insert_any(first, item, pos);
                                        break;

                        case 4: printf("EXITING...");
									exit(0);
                        default:printf("Invalid choice\n");
                }
        }
        printf("\n");

}