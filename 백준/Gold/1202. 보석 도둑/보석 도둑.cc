#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;

multiset<int> bag;

struct jewel{
    int m,v;
    bool operator<(const jewel &p)const{
        return v>p.v;
    }
}j[300000];

int  N,K;
long long result;

int main(){
    int i,in;

    scanf("%d%d",&N,&K);
    for(i=0; i<N; i++) scanf("%d%d",&j[i].m,&j[i].v);
    sort(j,j+N);
    for(i=0; i<K; i++){
        scanf("%d",&in);
        bag.insert(in);
    }

    for(i=0; i<N; i++){
        auto it=bag.lower_bound(j[i].m);
        if(it!=bag.end()){
            result+=j[i].v;
            bag.erase(it);
        }
    }

    printf("%lld",result);
    return 0;
}
