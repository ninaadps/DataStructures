#include<stdio.h>

void bsearch(int arr[],int l,int h, int k)
{
    int mid;
    if(l>h)
    {
        printf("key not found");
        return;
    }
    mid=(l+h)/2;
    if(arr[mid]==k)
    {
       printf("key found at location %d",mid+1);
       return;
    }
    else if(arr[mid]<k)
    {   bsearch(arr,mid+1,h,k);

    }
    else 
    {   bsearch(arr,l,mid-1,k);

    }
}

void main()
{   int n;
    int a[50];
    int key;
    printf("enter number of elements");
    scanf("%d",&n);
    printf("enter elements");
    for(int i=0;i<n;i++)    {
    scanf("%d",&a[i]);
}
printf("enter key");
    scanf("%d",&key);

   bsearch(a,0,n,key);



}