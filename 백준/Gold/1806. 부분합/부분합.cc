#include<stdio.h>

int A[100001], N, s, Min=-1;

int main(){
    int i,j,sum;

    scanf("%d%d",&N, &s);
    for(i=1; i<=N; i++) scanf("%d",&A[i]);

    i=j=1;
    sum=A[1];
    while(1){
        if(sum>=s){
            if(Min==-1 || Min>j-i) Min=j-i;
            sum-=A[i++];
        }
        else{
            if(j<N) sum+=A[++j];
            else break;
        }
    }

    printf("%d",Min+1);
    return 0;
}
