#include<stdio.h>

int main(){
    int t1,t2,t3,N;
    int i,j,k;

    scanf("%d%d%d%d",&t1,&t2,&t3,&N);
    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            for(k=0; k<=N; k++){
                if(t1*i+t2*j+t3*k==N){
                    printf("1");
                    return 0;
                }
            }
        }
    }

    printf("0");
    return 0;
}
