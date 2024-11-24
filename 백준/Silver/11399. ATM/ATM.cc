#include<stdio.h>
#include<algorithm>

using namespace std;

int N,P[1001];

int main(){
    int i,sum=0;
    scanf("%d",&N);
    for(i=0; i<N; i++) scanf("%d",P+i);
    sort(P,P+N);
    for(i=0; i<N; i++) sum+=(N-i)*P[i];
    printf("%d",sum);
}