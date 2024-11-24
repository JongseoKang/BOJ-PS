#include<stdio.h>
#define Min(a,b) (a<b ? a:b)

int N;
int cnt[3];
int arr[100000];
int type[3][3];
int dream[100000];

int abc(int a,int b,int c);

int main(){
    int i,t,m=9999999;

    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d",&arr[i]);
        cnt[arr[i]-1]++;
    }

    t=abc(1,2,3);
    if(m>t) m=t;
    t=abc(1,3,2);
    if(m>t) m=t;
    t=abc(2,1,3);
    if(m>t) m=t;
    t=abc(2,3,1);
    if(m>t) m=t;
    t=abc(3,1,2);
    if(m>t) m=t;
    t=abc(3,2,1);
    if(m>t) m=t;

    printf("%d",m);
    return 0;
}

int abc(int a,int b,int c){
    int i,j,k,r=0;
    for(i=0; i<cnt[a-1]; i++){
        dream[i]=a;
    }
    for(j=0; j<cnt[b-1]; j++){
        dream[i+j]=b;
    }
    for(k=0; k<cnt[c-1]; k++){
        dream[i+j+k]=c;
    }
    for(i=0; i<N; i++){
        type[arr[i]-1][dream[i]-1]++;
    }

    type[0][0]=type[1][1]=type[2][2]=0;
    r+=Min(type[0][1],type[1][0])+Min(type[0][2],type[2][0])+Min(type[2][1],type[1][2]);
    r+=(type[0][1]+type[1][0]-2*Min(type[1][0],type[0][1]))*2;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++) type[i][j]=0;
    }
    return r;
}
