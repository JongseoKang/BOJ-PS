#include<stdio.h>

int N,M,K,s=1;
long long t[3000000],a[1000000];

void maketree();
long long sum(long long l, long long r);
void update(long long v, long long x);

int main(){
    int i;
    long long p,q,r;

    scanf("%d%d%d",&N,&M,&K);
    for(i=0; i<N; i++) scanf("%lld",a+i);

    maketree();

    for(i=0; i<M+K; i++){
        scanf("%lld%lld%lld",&p,&q,&r);
        if(p==1) update(q,r);
        else printf("%lld\n",sum(q,r));
    }

    return 0;
}

void maketree(){
    int i,j;

    while(s<N) s<<=1;
    for(i=0; i<N; i++){
        j=i+s;
        while(j>0){
            t[j]+=a[i];
            j>>=1;
        }
    }
}

long long sum(long long l, long long r){
    long long ret=0;
    l+=s-1, r+=s-1;
    while(l<r){
        if(l%2==1){
            ret+=t[l];
            l++;
        }
        else if(r%2==0){
            ret+=t[r];
            r--;
        }
        else{
            l>>=1;
            r>>=1;
        }
    }

    if(l==r) ret+=t[r];
    return ret;
}

void update(long long v, long long x){
    v+=s-1;
    long long d=x-t[v];

    while(v>0){
        t[v]+=d;
        v>>=1;
    }
}
