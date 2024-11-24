#include<stdio.h>
#include<algorithm>

using namespace std;

struct xy{
    int x,y,c;
    bool operator <(const xy &a)const{
        return c<a.c;
    }
}bamb[250001];

int arr[501][501],d[501][501];

int main(){
    int N,i,j,p,q,Max=0;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    scanf("%d",&N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d",&arr[i][j]);
            bamb[i*N+j].x=i;
            bamb[i*N+j].y=j;
            bamb[i*N+j].c=arr[i][j];
        }
    }

    sort(bamb,bamb+(N*N));

    for(i=0; i<N*N; i++){
        for(j=0; j<4; j++){
            p=bamb[i].x+dir[j][0];
            q=bamb[i].y+dir[j][1];
            if(p>=0 && p<N && q>=0 && q<N){
                if(arr[bamb[i].x][bamb[i].y]>arr[p][q]
                   && d[bamb[i].x][bamb[i].y]<d[p][q]+1){
                    d[bamb[i].x][bamb[i].y]=d[p][q]+1;
                }
            }
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            if(Max<d[i][j]) Max=d[i][j];
    }

    printf("%d",Max+1);
    return 0;
}
