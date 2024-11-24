#include<stdio.h>
#define P 16769023

int d[100001][2];

int main(){
    int n,i;

    scanf("%d",&n);
    d[1][0]=d[1][1]=1;
    for(i=2; i<=n; i++){
        if(i%2==0){
            d[i][0]=(d[i-1][0]+d[i-1][1])%P;
            d[i][1]=0;
        }
        else{
            d[i][0]=d[i-1][0];
            d[i][1]=d[i-1][0];
        }
    }

    printf("%d",(d[n][0]+d[n][1])%P);
    return 0;
}
