#include<stdio.h>

int d[1000001];

int main(){
    int i,N;

    scanf("%d",&N);
    for(i=2; i<=N; i++) d[i]=99999999;
    d[1]=0;

    for(i=1; i<N; i++){
        if(i*3<=N && d[i]+1<d[i*3]) d[i*3]=d[i]+1;
        if(i*2<=N && d[i]+1<d[i*2]) d[i*2]=d[i]+1;
        if(d[i]+1<d[i+1]) d[i+1]=d[i]+1;
    }

    printf("%d",d[N]);
    return 0;
}
