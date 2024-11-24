#include<stdio.h>
#include<algorithm>

using namespace std;

struct st{
    int overall,num;
}p[500000],t[500000];

int N,c[500000];
void Merge(int s,int e);

int main(){
    int i;
    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d",&p[i].overall);
        p[i].num=i;
    }

    Merge(0,N-1);
    for(i=0; i<N; i++){
        printf("%d\n",i-c[i]+1);
    }

    return 0;
}

void Merge(int s,int e){
    if(s==e) return;
    Merge(s,(s+e)/2);
    Merge((s+e)/2+1,e);

    int l=s,r=(s+e)/2+1,k=s;

    while(k<=e){
        if(l>(s+e)/2){
            t[k++]=p[r++];
        }
        else if(r>e){
            t[k++]=p[l++];
        }
        else if(p[r].overall>p[l].overall){
            t[k++]=p[r];
            c[p[r++].num]+=((s+e)/2-l+1);
        }
        else{
            t[k++]=p[l++];
        }
    }
    for(l=s; l<=e; l++) {p[l]=t[l];}
}
