#include<stdio.h>
void hanoi(int n,char start ,char aux,char end);
void main()
{
    int l;
    scanf("%d",&l);
    char start ='A',aux='B',end='C';
    hanoi(l,start,aux,end);
}
void hanoi(int n,char start ,char aux,char end)
{
    if (n>0)

    {
    hanoi(n-1,start,end,aux);
    printf("%c to %c \n",start,end);
    hanoi(n-1,aux,start,end);
    }
   
}
