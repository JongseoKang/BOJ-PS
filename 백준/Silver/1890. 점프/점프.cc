#include<stdio.h>

int N;
long long arr[800][800],d[800][800];

int main(){
    int i,j;

    scanf("%d",&N);
    for(i=0; i<N; i++)
        for(j=0; j<N; j++) scanf("%d",&arr[i][j]);

    d[0][0]=1;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(i==j && i==N-1) break;
            d[i+arr[i][j]][j]+=d[i][j];
            d[i][j+arr[i][j]]+=d[i][j];
        }
    }

    printf("%lld",d[N-1][N-1]);
    return 0;
}
