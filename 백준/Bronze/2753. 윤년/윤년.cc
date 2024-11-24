#include<stdio.h>

int main()
{
    int A,B;
    scanf("%d",&A);
    printf("%d",A%400==0 || (A%100!=0 && A%4==0));

    return 0;
}
