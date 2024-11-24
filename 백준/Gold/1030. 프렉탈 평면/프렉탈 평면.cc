#include<stdio.h>

int s,N,K,R1,R2,C1,C2,l,r;
int pow[11];
bool calc(int level,int x,int y);

int main(){
    int i,j;

    scanf("%d%d%d%d%d%d%d",&s,&N,&K,&R1,&R2,&C1,&C2);
    l=(N-K)/2, r=N-(N-K)/2;

    pow[0]=1;
    for(i=1; i<=s; i++) pow[i]=pow[i-1]*N;

    for(i=R1; i<=R2; i++){
        for(j=C1; j<=C2; j++) printf("%d",calc(s,i,j));
        puts("");
    }

    return 0;
}

bool calc(int level,int x,int y){
    if(x/pow[level]>=l && x/pow[level]<r &&
       y/pow[level]>=l && y/pow[level]<r)
        return true;
    if(!level) return false;
    return calc(level-1,x%pow[level],y%pow[level]);
}
