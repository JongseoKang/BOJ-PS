#include<stdio.h>

int d[101][10];

int main(){
    int N,i,j;
    long long s=0;

    scanf("%d",&N);

    for(i=0; i<10; i++) d[1][i]=1;
    for(i=2; i<=N; i++){
        for(j=0; j<10; j++){
            if(j-1>=0) d[i][j]+=d[i-1][j-1];
            d[i][j]%=1000000000;
            if(j+1<10) d[i][j]+=d[i-1][j+1];
            d[i][j]%=1000000000;
        }
    }

    for(i=1; i<10; i++) s+=d[N][i];
    s%=1000000000;
    printf("%lld",s);
    return 0;
}
