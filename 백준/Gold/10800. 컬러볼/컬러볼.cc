#include<stdio.h>
#include<algorithm>

using namespace std;

struct st{
    int S,C,P;
    bool operator <(const st &a)const{
        return S<a.S;
    }
}ball[200001];;
int N,B[200001],sum,ans[200000];

int main(){
    int i,j,t;

    scanf("%d",&N);
    for(i=0; i<N; i++){ scanf("%d%d",&ball[i].C,&ball[i].S); ball[i].P=i;}
    sort(ball,ball+N);

    for(i=0; ball[0].S==ball[i].S; i++){
        B[ball[i].C]+=ball[i].S;
        sum+=ball[i].S;
    }

    for(j=i; i<N; i++){
        t=0;
        while(ball[j].S==ball[i].S){
            t+=ball[i].S;
            ans[ball[i].P]=sum-B[ball[i].C];
            i++;
        }
        i--;
        while(j<=i){
            B[ball[j].C]+=ball[j].S;
            j++;
        }
        sum+=t;
    }

    for(i=0; i<N; i++) printf("%d\n",ans[i]);
    return 0;
}
