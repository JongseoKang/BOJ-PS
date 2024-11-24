#include<stdio.h>
#include<queue>

using namespace std;

struct XY{
    int x,y,t,k;
}ini,h;
queue<XY> q;
char maze[50][51];
int N,M,check[50][50][64];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    int i,j,X,Y;

    scanf("%d%d",&N,&M);
    for(i=0; i<N; i++){
        scanf("%s",maze[i]);
        for(j=0; j<M; j++){
            if(maze[i][j]=='0'){
                ini.t=0, ini.x=i, ini.y=j, ini.k=0;
                q.push(ini);
                check[i][j][0]=1;
                maze[i][j]='.';
                break;
            }
        }
    }

    while(!q.empty()){
        h=q.front();
        q.pop();
        for(i=0; i<4; i++){
            X=h.x+dir[i][0];
            Y=h.y+dir[i][1];
            if(X<0 || X>=N || Y<0 || Y>=M || maze[X][Y]=='#') continue;
            if(maze[X][Y]=='1'){
                printf("%d",h.t+1);
                return 0;
            }
            else if(maze[X][Y]=='.' && !check[X][Y][h.k]){
                ini.x=X, ini.y=Y, ini.t=h.t+1, ini.k=h.k;
                q.push(ini);
                check[X][Y][ini.k]=1;
            }
            else if(maze[X][Y]>='a' && maze[X][Y]<='f'){
                ini.k=h.k|(1<<(maze[X][Y]-'a'));
                if(!check[X][Y][h.k] && !check[X][Y][ini.k]){
                    ini.x=X, ini.y=Y, ini.t=h.t+1;
                    q.push(ini);
                    check[X][Y][h.k]=check[X][Y][ini.k]=1;
                }
            }
            else if(maze[X][Y]>='A' && maze[X][Y]<='F'){
                if(!check[X][Y][h.k] && ((1<<(maze[X][Y]-'A'))&h.k)==(1<<(maze[X][Y]-'A'))){
                    ini.x=X, ini.y=Y, ini.t=h.t+1, ini.k=h.k;
                    q.push(ini);
                    check[X][Y][ini.k]=1;
                }
            }
        }
    }

    printf("-1");
    return 0;
}
