#include<stdio.h>

int gcd(int n,int p)
{
    if(p!=0)
    {
        return gcd(p,n%p);
    }
    else{
        return n;
    }
}
void main()
{   int x,y;
    printf("enter numbers 2");
    scanf("%d %d",&x,&y); 
    int hcf=gcd(x,y);
    printf("\n %d",hcf);
}