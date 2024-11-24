#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct D{
    long long X,Y;
    bool operator() (D a,D b){
        return (a.X<b.X || (a.X==b.X && a.Y<b.Y));
    }
}st[100000];

long long N,L,t[100000][2];
vector<long long> x,y;

long long rv(long long a){
    if(a>0) return a;
    return -a;
}

int main(){
    int i,px,py;
    long long temp,Max=0;

    scanf("%lld%lld",&N,&L);
    for(i=0; i<N; i++){
        scanf("%lld%lld",&st[i].X,&st[i].Y);
        x.push_back(st[i].X);
        y.push_back(st[i].Y);
    }

    sort(st,st+N,D());
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());

    for(i=0; i<N; i++){
        px=(lower_bound(x.begin(),x.end(),st[i].X)-x.begin());
        py=(lower_bound(y.begin(),y.end(),st[i].Y)-y.begin());

        temp=t[px][0];
        if(temp<t[py][1]+L+rv(st[i].X-st[i].Y)){
            temp=t[py][1]+L+rv(st[i].X-st[i].Y);
        }

        if(t[py][1]<t[px][0]+L+rv(st[i].X-st[i].Y)){
            t[py][1]=t[px][0]+L+rv(st[i].X-st[i].Y);
        }
        t[px][0]=temp;
    }

    for(i=0; i<N; i++){
//        printf("x: %lld  y:%lld\n",t[i][0],t[i][1]);
        if(Max<t[i][0]) Max=t[i][0];
        if(Max<t[i][1]) Max=t[i][1];
    }
    printf("%lld",Max);
    return 0;
}

