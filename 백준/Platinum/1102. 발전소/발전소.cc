#include<stdio.h>
#include<queue>

using namespace std;

struct data{
    unsigned int st;
    int cost;
    bool operator <(const data &p)const{
        return cost>p.cost;
    }
}in;

priority_queue<data> que;
int N,c[16][16],P;
int t[1<<16];
char onoff[20];

int main(){
    int i,j,k,Min;
    unsigned int s=0;

    scanf("%d",&N);
    for(i=0; i<N; i++)
        for(j=0; j<N; j++) scanf("%d",&c[i][j]);
    scanf("%s",onoff);
    scanf("%d",&P);
    if(!P){
        printf("0");
        return 0;
    }

    for(i=0; i<N; i++) {
        if(onoff[i]=='Y'){
            s+=1<<i;
        }
    }

    if(s==0) {printf("-1"); return 0;}

    for(i=0; i<(1<<N); i++) t[i]=99999999;
    t[s]=0;
    in.st=s;
    in.cost=0;
    que.push(in);
    while(1){
        s=que.top().st;
        que.pop();
        if(__builtin_popcount(s)>=P){
            printf("%d",t[s]);
            return 0;
        }
        for(j=0; j<N; j++){
            if(!(s&(1<<j))){
                Min=99999999;
                for(k=0; k<N; k++){
                    if((s&(1<<k)) && Min>c[k][j])
                        Min=c[k][j];
                }
                if(Min+t[s]<t[s+(1<<j)]){
                    t[s+(1<<j)]=Min+t[s];
                    in.st=s+(1<<j);
                    in.cost=t[in.st];
                    que.push(in);
                }
            }
        }
    }
    return 0;
}
