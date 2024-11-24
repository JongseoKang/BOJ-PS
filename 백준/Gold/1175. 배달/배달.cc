#include<stdio.h>
#include<queue>

using namespace std;

struct XY{
    int x,y;
}del[2],S;

struct state{
    int x,y,s,d,t;
}init,head;

queue<state> q;
int N,M,c;
char Map[50][51];
int check[50][50][4][4];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int main(){
    int i,j,k,x,y,s,d,t;

    scanf("%d%d",&N,&M);
    for(i=0; i<N; i++){
        scanf("%s",Map[i]);
        for(j=0; j<M; j++){
            if(Map[i][j]=='C'){
                del[c].x=i, del[c].y=j;
                c++;
            }
            else if(Map[i][j]=='S') S.x=i, S.y=j;
        }
    }

    init.x=S.x, init.y=S.y, init.s=0, init.d=-1, init.t=0;
    q.push(init);
    check[S.x][S.y][0][0]=1;
    check[S.x][S.y][0][1]=1;
    check[S.x][S.y][0][2]=1;
    check[S.x][S.y][0][3]=1;
    while(!q.empty()){
        head=q.front();
        for(i=0; i<4; i++){
            x=head.x+dir[i][0];
            y=head.y+dir[i][1];
            if(i!=head.d && x>=0 && x<N && y>=0 && y<M && Map[x][y]!='#')
            {
                s=(del[0].x==x && del[0].y==y)+2*(del[1].x==x && del[1].y==y);
                if(!check[x][y][head.s|s][i]){
                    if((head.s|s)==3){
                        printf("%d",head.t+1);
                        return 0;
                    }
                    init.x=x, init.y=y, init.s=head.s|s, init.d=i, init.t=head.t+1;
                    check[x][y][head.s|s][i]=1;
                    q.push(init);
                }
            }
        }
        q.pop();
    }

    printf("-1");
    return 0;
}
