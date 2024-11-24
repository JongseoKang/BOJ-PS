#include<stdio.h>

int main()
{
    int p,q,w,h,x,y,t;

    scanf("%d%d%d%d%d",&w,&h,&p,&q,&t);

    if((p+t)/w%2)
        x=w-(p+t)%w;
    else
        x=(p+t)%w;

    if((q+t)/h%2)
        y=h-(q+t)%h;
    else
        y=(q+t)%h;

    printf("%d %d",x,y);
    return 0;
}
