#include<stdio.h>
#include<map>

using namespace std;

map<long long,long long> cache;
long long P,Q;
long long memo(long long x);

int main(){
    long long N;
    scanf("%lld %lld %lld",&N,&P,&Q);

    printf("%lld",memo(N));
    return 0;
}

long long memo(long long x){
    if(!x) return 1;
    if(cache.find(x)!=cache.end()) return cache[x];
    return cache[x]=memo(x/P)+memo(x/Q);
}
