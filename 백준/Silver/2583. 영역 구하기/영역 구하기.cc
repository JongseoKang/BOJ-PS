#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

struct xy{
    int x,y;
}in;
queue<xy> q;
int Map[100][100],dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},ans[100000];

void print(int M,int N){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++) printf("%d ",Map[i][j]);
        puts("");
    }
}

int main(){
    int N,M,K,a,b,c,d;
    int i,j,k;

    scanf("%d%d%d",&M,&N,&K);
    while(K--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for(i=a; i<c; i++){
            for(j=b; j<d; j++) Map[j][i]=1;
        }
    }

    c=0;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            if(!Map[i][j]){
                //print(M,N);
                in.x=i;
                in.y=j;
                Map[i][j]=1;
                q.push(in);
                a=1;
                while(!q.empty()){
                    for(k=0; k<4; k++){
                        in.x=q.front().x+dir[k][0];
                        in.y=q.front().y+dir[k][1];
                        if(in.x>=0 && in.x<M && in.y>=0 && in.y<N && !Map[in.x][in.y]){
                            q.push(in);
                            Map[in.x][in.y]=1;
                            a++;
                        }
                    }
                    q.pop();
                }
                ans[c++]=a;
            }
        }
    }

    sort(ans,ans+c);
    printf("%d\n",c);
    for(i=0; i<c; i++) printf("%d ",ans[i]);
    return 0;
}
