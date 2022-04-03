#include<stdio.h>

void towers(int, char, char, char);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char source, char dest, char temp)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", source, dest);
        return;
    }
    towers(num - 1, source, temp, dest);
    printf("\n Move disk %d from peg %c to peg %c", num, source, dest);
    towers(num - 1, temp, dest, source);
}