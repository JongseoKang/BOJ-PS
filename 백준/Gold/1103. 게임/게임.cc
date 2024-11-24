#include<stdio.h>

bool check[50][50];
char board[50][50];
int d[50][50],N,M;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dfs(int x,int y);

int main(){
    int i,j;
    scanf("%d%d",&N,&M);
    for(i=0; i<N; i++) scanf("%s",board[i]);

    for(i=0; i<N; i++){
        for(j=0; j<M; j++) d[i][j]=-2;
    }
    check[0][0]=true;
    printf("%d",dfs(0,0));
    return 0;
}

int dfs(int x,int y){
    if(d[x][y]!=-2) return d[x][y];

    int i,X,Y,ret=0,temp;

    for(i=0; i<4; i++){
        X=(board[x][y]-'0')*dir[i][0]+x;
        Y=(board[x][y]-'0')*dir[i][1]+y;
        if(X>=N || X<0 || Y>=M || Y<0 || board[X][Y]=='H') continue;
        if(check[X][Y]) return -1;
        check[X][Y]=true;
        temp=dfs(X,Y);
        if(temp==-1) return -1;
        if(temp>ret) ret=temp;
        check[X][Y]=false;
    }

    return d[x][y]=ret+1;
}
