#include<stdio.h>

int N;
int chk[1000][1000];
int search(int x,int y,int lx,int ly,int level);

int main(){
    scanf("%d",&N);
    if(N<5){ printf("0"); return 0; }
    else if(N==5){ printf("2"); return 0; }
    chk[500][500]=1;
    chk[499][500]=1;
    printf("%d",search(500,500,499,500,N));
    return 0;
}

int search(int x,int y,int lx,int ly,int level){
    int cnt=0;
    if(level==1){
    if((x%2==0 && y%2==0) || (x%2==0 && y%2==1)){
        if((lx!=x+1 || ly!=y+1) && chk[x+1][y+1]) cnt++;

        if((lx!=x+1 || ly!=y-1) && chk[x+1][y-1]) cnt++;

        if((lx!=x-1 || ly!=y) && chk[x-1][y]) cnt++;
    }
    else{
        if((lx!=x+1 || ly!=y) && chk[x+1][y]) cnt++;

        if((lx!=x-1 || ly!=y-1) && chk[x-1][y-1]) cnt++;
        if((lx!=x-1 || ly!=y+1) && chk[x-1][y+1]) cnt++;
    }
    return cnt;
    }
if((x%2==0 && y%2==0) || (x%2==0 && y%2==1)){
        if(!chk[x+1][y+1]){
            chk[x+1][y+1]=1;
            cnt+=search(x+1,y+1,x,y,level-1);
            chk[x+1][y+1]=0;
        }

        if(!chk[x+1][y-1]){
            chk[x+1][y-1]=1;
            cnt+=search(x+1,y-1,x,y,level-1);
            chk[x+1][y-1]=0;
        }

        if(!chk[x-1][y]){
            chk[x-1][y]=1;
            cnt+=search(x-1,y,x,y,level-1);
            chk[x-1][y]=0;
        }
    }
    else{
        if(!chk[x+1][y]){
            chk[x+1][y]=1;
            cnt+=search(x+1,y,x,y,level-1);
            chk[x+1][y]=0;
        }

        if(!chk[x-1][y-1]){
            chk[x-1][y-1]=1;
            cnt+=search(x-1,y-1,x,y,level-1);
            chk[x-1][y-1]=0;
        }
        if(!chk[x-1][y+1]){
            chk[x-1][y+1]=1;
            cnt+=search(x-1,y+1,x,y,level-1);
            chk[x-1][y+1]=0;
        }
    }
    return cnt;
}