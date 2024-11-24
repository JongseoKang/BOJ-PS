#include<stdio.h>

int d[2][3],cost[3];

int main(){
    int N,i,j,k,Min;
    scanf("%d",&N);

    for(i=1; i<=N; i++){
        scanf("%d%d%d",cost,cost+1,cost+2);
        for(j=0; j<3; j++){
            Min=9999999;
            for(k=0; k<3 ;k++){
                if(j==k) continue;
                if(Min>d[(i-1)%2][k]){
                    Min=d[(i-1)%2][k];
                }
            }
            d[i%2][j]=Min+cost[j];
        }
    }
    
    Min=9999999;
    for(i=0; i<3; i++){
        if(d[N%2][i]<Min) Min=d[N%2][i];
    }
    
    printf("%d",Min);
    return 0;
}