#include<stdio.h>

struct jewel{
    int v,w;
}jewels[100];

int N,K,d[100001];

int main(){
    int i,j,k;

    scanf("%d%d",&N,&K);
    for(i=0; i<N; i++){ scanf("%d%d",&jewels[i].w,&jewels[i].v); }

    for(j=0; j<N; j++){
        for(i=K; i>=jewels[j].w; i--){
            if(d[i-jewels[j].w]+jewels[j].v>d[i]){
                d[i]=d[i-jewels[j].w]+jewels[j].v;
            }
        }
    }

    printf("%d",d[K]);
    return 0;
}
