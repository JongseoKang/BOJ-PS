#include<stdio.h>

int K,C,R;
int arrow;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int check[1001][1001];

int main()
{
    int i,j;
    int X=1,Y=1;

    scanf("%d%d%d",&C,&R,&K);

    if(C*R<K)
    {
        printf("0");
        return 0;
    }

    X=1;
    Y=0;
    for(i=1; i<=C*R; i++)
    {
        X+=dir[arrow][0];
        Y+=dir[arrow][1];
        if(check[X][Y] || X<1 || Y<1 || X>C || Y>R)
        {
            X-=dir[arrow][0];
            Y-=dir[arrow
            ][1];
            arrow=(arrow+1)%4;
            X+=dir[arrow][0];
            Y+=dir[arrow][1];
        }
        check[X][Y]=i;

        if(i==K)
        {
            printf("%d %d",X,Y);
            return 0;
        }
    }

    return 0;
}
