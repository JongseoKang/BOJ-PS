#include<stdio.h>

int D[301][2],C[301];

int main(){
    int N,i;

    scanf("%d",&N);
    for(i=1; i<=N; i++) scanf("%d",C+i);

    D[1][0]=C[1];
    D[1][1]=-987654321;
    D[2][0]=C[2];
    D[2][1]=C[1]+C[2];
    for(i=3; i<=N; i++){
        D[i][0]=(D[i-2][0]<D[i-2][1] ? D[i-2][1]:D[i-2][0])+C[i];
        D[i][1]=D[i-1][0]+C[i];
    }

    printf("%d",(D[N][0]<D[N][1] ? D[N][1]:D[N][0]));
    return 0;
}
