#include<stdio.h>

int C[100001],chk[100001];

int main(){
    int N,M,a,b,i,j;

    scanf("%d%d",&N,&M);
    for(i=1; i<=N; i++) C[i]=i;
    while(M--){
        scanf("%d%d",&a,&b);
        C[a]++;
        C[b]--;
    }

    for(i=1; i<=N; i++){
        if(!chk[C[i]]) chk[C[i]]=1;
        else {printf("-1"); return 0;}
    }

    for(i=1; i<=N; i++) printf("%d ",C[i]);
    return 0;
}
