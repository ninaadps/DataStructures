#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double compute(char symbol, char op1, double op2)
{
    switch(symbol)
    {
        case '+' : return op1+op2;
        case '-':  return op1-op2;
        case '*' : return op1*op2;
        case '/' : return op1/op2;
        case '$':
        case '^': return pow(op1,op2);
    }

}
void main()
{
    double s[20],res,op1,op2;
    char ar[20],symbol;
    printf("enter postfix expression");
    scanf("%s",ar);
    int top,i;
    top=-1;
    for(i=0;i<strlen(ar);i++)
    {    symbol=ar[i];
        if(isdigit(symbol))
        {
            s[++top]=symbol-'0';
        }
        else
        {
            op2=s[top--];
            op1=s[top--];
            res=compute(symbol,op1,op2);
            s[++top]=res;
        }
    }
    printf("%f",s[top]);
}