#include<stdio.h>
#include<queue>

using namespace std;

struct D{
    int X,Y,B;
    bool operator <(const D& b)const{
        return B>b.B;
    }
}in,h;
priority_queue<D> heap;
int N;
char Map[50][51];
int dest[50][50];
int arrow[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main(){
    int i,j,x,y;

    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%s",Map[i]);
        for(j=0; j<N; j++) dest[i][j]=99999;
    }

    in.X=in.Y=in.B=0;
    heap.push(in);
    dest[0][0]=0;

    for(i=0; i<N*N; i++){
        h=heap.top();
        heap.pop();
        for(j=0; j<4; j++){
            x=h.X+arrow[j][0];
            y=h.Y+arrow[j][1];
                if(x>=0 && x<N && y>=0 && y<N && h.B-Map[x][y]+49<dest[x][y]){
                    in.B=dest[x][y]=h.B-Map[x][y]+49;
                    in.X=x,in.Y=y;
                    heap.push(in);
                }
        }
    }

    printf("%d",dest[N-1][N-1]);
    return 0;
}
