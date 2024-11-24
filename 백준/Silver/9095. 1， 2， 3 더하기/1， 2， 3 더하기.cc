#include<stdio.h>

int ans[20]={1,};

int main(){
    int N,T,i;

    ans[0]=ans[1]=1;
    ans[2]=2;
    for(i=3; i<=11; i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }

    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
    return 0;
}
