#include<stdio.h>
#include<algorithm>

using namespace std;

long long arr[1000000];
int N;
long long C;

bool check(long long a);
long long para(long long l,long long r);

int main(){
    int i;
    long long rs;

    scanf("%d%lld",&N,&C);
    for(i=0; i<N; i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+N);
    rs=para(0,arr[N-1]);
    printf("%lld",rs);
    return 0;
}

bool check(long long a){
    long long sum=0;
    for(int i=0; i<N; i++){
        if(arr[i]>a) sum+=(arr[i]-a);
    }
    if(C<=sum) return true;
    return false;
}

long long para(long long l,long long r){
    if(l==r) return l;
    if(l+1==r){
        if(check(r)) return r;
        return l;
    }
    long long m=(l+r)/2;

    if(check(m)){
        return para(m,r);
    }
    return para(l,m-1);
}
