#include<stdio.h>
#include<algorithm>

using namespace std;

struct st{
    int s,e,c;
    bool operator ()(const st &a,const st &b)const {
        return a.e<b.e || (a.e==b.e && a.s>b.s);
    }
}box[10000];
int carrying[2001];

int N,C,M;
int carried;

int main(){
    int i,j;
    int lim,loadup;

    scanf("%d%d%d",&N,&C,&M);
    for(i=0; i<M; i++){
        scanf("%d%d%d",&box[i].s,&box[i].e,&box[i].c);
    }

    sort(box,box+M,st());

    for(i=0; i<M; i++){
        lim=loadup=0;
        for(j=box[i].s;j<box[i].e;j++){
            if(lim<carrying[j]){
                lim=carrying[j];
            }
        }
        if(lim+box[i].c<=C) loadup=box[i].c;
        else if(lim+box[i].c>C) loadup=C-lim;
        for(j=box[i].s;j<box[i].e;j++){
            carrying[j]+=loadup;
        }
        carried+=loadup;
    }

    printf("%d",carried);
    return 0;
}
