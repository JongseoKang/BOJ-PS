#include<stdio.h>
int t[20],p[20],d[20],N;
int main(){
    int i,j,Max;
    scanf("%d",&N);
    for(i=1; i<=N; i++) scanf("%d%d",t+i,p+i);
    for(i=1; i<=N; i++){
        if(t[i]+i>N+1) continue;
        Max=0;
        for(j=1; j<i; j++){
            if(t[j]+j<=i){
                if(Max<d[j]) Max=d[j];
            }
        }
        d[i]=Max+p[i];
    }
    Max=0;
    for(i=1; i<=N; i++) if(Max<d[i]) Max=d[i];
    printf("%d",Max);
    return 0;
}