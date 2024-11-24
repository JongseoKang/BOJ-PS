#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef struct ARRAY{
    ll v,oidx,cidx;
};
ARRAY i[500500];
bool cmp(ARRAY s, ARRAY t){
    return s.oidx<t.oidx;
}
bool cmp2(ARRAY s, ARRAY t){
    return s.v<t.v || (s.v==t.v && s.oidx<t.oidx);
}
bool f(ll c)
{
    ll l=0,r=1e9;
    bool re=false;
    while(l<=r){
        ll mid=(l+r)/2;
        if(mid*mid==c){
            re=true; break;
        }
        if(mid*mid<c) l=mid+1;
        else r=mid-1;
    }
    return re;
}
ll p(ll a, ll b){
    while(a%b!=0){
        ll t=a; a=b; b=t%b;
    }
    return b;
}
int main()
{
    ll n,x,out=1;
    scanf("%lld",&n);
    for(x=0;x<n;x++){
        scanf("%lld",&i[x].v);
        i[x].oidx=x;
    }
    sort(i,i+n,cmp2);
    for(x=0;x<n;x++) i[x].cidx=x;
    sort(i,i+n,cmp);
    for(x=0;x<n;x++){
        ll re=p(i[x].v,i[i[x].cidx].v);
        if( !f(i[x].v/re) || !f(i[i[x].cidx].v/re)) out=0;
    }
    if(out) printf("YES");
    else printf("NO");
    return 0;
}