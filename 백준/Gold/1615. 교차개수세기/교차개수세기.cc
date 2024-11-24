#include<stdio.h>
#include<algorithm>

using namespace std;

struct edge{
    long long a,b;
    bool operator< (const edge& p)const{
        return a<p.a || (a==p.a && b<p.b);
    }
}input[2005000];

long long mani[2005000],temp[2005000];
long long n,m,result;

void merge(int l, int r);

int main(){
    int i;
    scanf("%lld%lld",&n,&m);

    for(i=0; i<m; i++)
        scanf("%lld%lld",&input[i].a,&input[i].b);
   
    sort(input, input+m);
    for(i=0; i<m; i++) mani[i]=input[i].b;
    merge(0, m-1);

    printf("%lld",result);
    return 0;
}

void merge(int l, int r){
    int i,j,k=0;
    if(l==r) return;
    
    merge(l,(l+r)/2);
    merge((l+r)/2+1,r);
    i=l, j=(l+r)/2+1;
    while(k<=r-l){
        if(i>(l+r)/2 || (j<=r && mani[i]>mani[j])){
            temp[l+k++]=mani[j++];
            result+=((l+r)/2+1-i);
        }
        else
            temp[l+k++]=mani[i++];
    }

    for(i=l; i<=r; i++) mani[i]=temp[i];
    return;
}