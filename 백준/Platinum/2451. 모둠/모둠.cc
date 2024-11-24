#include<stdio.h>

int g[3010][3010],l[3010][3010],t[3010];
int N,Back[3010],print[3001],len;

int main(){
    int i,j,k,a;

    scanf("%d",&N);
    i=1;
    while(i<=N){
        scanf("%d",&a);
        if(a){ g[i][a]=g[a][i]=1; }
        else i++;
    }

    for(i=1; i<N; i++){
        for(j=1; j<=N-i; j++){
            l[j][j+i]=l[j+1][j+i]+l[j][j+i-1]-l[j+1][j+i-1]+g[j][j+i];
        }
    }
    for(i=2; i<=N; i++){
        t[i]=(l[1][N]-l[1][i]-l[i+1][N])+(i*(i-1)/2-l[1][i]);
        for(j=0; j<i; j++){
            if(t[i]>t[j]+l[1][i]-l[1][j]-l[j+1][i]+(i-j)*(i-j-1)/2-l[j+1][i]){
                t[i]=t[j]+l[1][i]-l[1][j]-l[j+1][i]+(i-j)*(i-j-1)/2-l[j+1][i];
                Back[i]=j;
            }
        }
    }
    i=N;
    print[len++]=i;
    while(Back[i]){
        i=Back[i];
        print[len++]=i;
    }
    printf("%d\n%d ",t[N],len);
    for(; len>0; len--){
        printf("%d ",print[len-1]-print[len]);
    }
    return 0;
}
