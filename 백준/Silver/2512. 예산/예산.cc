#include<stdio.h>
#include<algorithm>

using namespace std;

int b[10000];
int N,M;

int main(){
    int i,key=1,in=0,s=0;

    scanf("%d",&N);
    for(i=0; i<N; i++) scanf("%d",&b[i]);
    scanf("%d",&M);

    sort(b,b+N);
    while(key<=b[N-1]){
        if(s+N-in<=M){
            s+=(N-in);
            key++;
        }
        else {
            printf("%d",key-1);
            return 0;
        }
        while(b[in]<key) in++;
    }

    printf("%d",b[N-1]);
    return 0;
}
