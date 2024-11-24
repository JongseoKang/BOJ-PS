#include<stdio.h>

char print[2200][2200];

void f(int n,int x,int y){
    if(n==1){
        print[x][y]='*';
        return;
    }

    int t=n/3;
    f(t,x,y);
    f(t,x,y+t);
    f(t,x,y+t*2);
    f(t,x+t,y);
    f(t,x+t,y+t*2);
    f(t,x+t*2,y);
    f(t,x+t*2,y+t);
    f(t,x+t*2,y+t*2);
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    f(n,0,0);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%c",(print[i][j]=='*' ? '*':' '));
        puts("");
    }
    return 0;
}
