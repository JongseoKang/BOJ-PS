#include<stdio.h>

int  s[30],N,S;
int recur(int level,int sum){
    if(level==N) return sum==S;
    return recur(level+1,sum)+recur(level+1,sum+s[level]);
}

int main(){
    int i,cnt;

    scanf("%d%d",&N,&S);
    for(i=0; i<N; i++) scanf("%d",s+i);

    cnt=recur(0,0)-(!S);
    printf("%d",cnt);
    return 0;
}
