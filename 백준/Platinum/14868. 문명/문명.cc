#include<stdio.h>
#include<vector>

using namespace std;

struct vertex{
    int px,py,Rank;
}g[3000][3000],in,in2;

vector<vertex> q;
int N,K;
int Civil[3000][3000];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
vertex Find(int x,int y){
    if(g[x][y].px==x && g[x][y].py==y) return g[x][y];
    return g[x][y]=Find(g[g[x][y].px][g[x][y].py].px,g[g[x][y].px][g[x][y].py].py);
}

void Union(vertex a,vertex b){
    if(a.px==b.px && a.py==b.py) return;

    K--;
    if(a.Rank<b.Rank){
        vertex t=a;
        a=b;
        b=t;
    }
    int x=b.px,y=b.py;
    g[x][y].px=a.px;
    g[x][y].py=a.py;
    if(a.Rank==g[x][y].Rank){
        g[a.px][a.py].Rank+1;
    }
}

int main(){
    int i,j,h=0,r,x,y,d=0;

    scanf("%d%d",&N,&K);

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            in.px=i,in.py=j;
            in.Rank=0;
            g[i][j]=in;
        }
    }

    for(i=0; i<K; i++){
        scanf("%d%d",&in.px,&in.py);
        in.px--,in.py--;
        Civil[in.px][in.py]=1;
        q.push_back(in);
    }

    while(1){
        r=q.size();
        for(i=h; i<r; i++){
            in=Find(q[i].px,q[i].py);
            for(j=0; j<4; j++){
                x=q[i].px+dir[j][0];
                y=q[i].py+dir[j][1];
                if(0<=x && x<N && 0<=y && y<N && Civil[x][y]){
                    in2=Find(x,y);
                    Union(in,in2);
                }
            }
        }
        if(K==1) break;

        d++;
        for(; h<r; h++){
            in=Find(q[h].px,q[h].py);
            for(j=0; j<4; j++){
                x=q[h].px+dir[j][0];
                y=q[h].py+dir[j][1];
                if(0<=x && x<N && 0<=y && y<N && !Civil[x][y]){
                    Civil[x][y]=1;
                    in.px=x,in.py=y;
                    q.push_back(in);
                    g[x][y].px=q[h].px;
                    g[x][y].py=q[h].py;
                }
            }
        }
    }
    printf("%d",d);
    return 0;
}
