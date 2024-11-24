#include<stdio.h>
#include<vector>

using namespace std;

struct XY{
    int x,y;
}in;

int arr[100][100];
int check[100][100];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void del(int N);
void enqueue(int x,int y,int N,int rain);
int flood(int N,int rain);

int main(){
    int N,i,j;
    int Max=1,r;

    scanf("%d",&N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=1; i<=100; i++){
        r=flood(N,i);
        if(r>Max) Max=r;
    }

    printf("%d",Max);
    return 0;
}

void del(int N){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            check[i][j]=0;
}

void enqueue(int x,int y,int N,int rain){
    int h=0,i,X,Y;
    check[x][y]=1;
    in.x=x,in.y=y;
    vector<XY> cue;
    cue.push_back(in);
    while(h<cue.size()){
        for(i=0; i<4; i++){
            X=cue[h].x+dir[i][0];
            Y=cue[h].y+dir[i][1];
            if(0<=X && X<N && 0<=Y & Y<N && !check[X][Y] && arr[X][Y]>rain){
                check[X][Y]=1;
                in.x=X,in.y=Y;
                cue.push_back(in);
            }
        }
        h++;
    }
    return;
}

int flood(int N,int rain){
    int i,j,k,c=0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(!check[i][j] && arr[i][j]>rain){
                enqueue(i,j,N,rain);
                c++;
            }
        }
    }

    del(N);
    return c;
}
