#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

struct Node{
    int p,D,Pa;
    vector<int> C;
}V[100001];

vector<int> P;
int N,N2,M,Q[100000][2],t[550000];
void dfs(int n,int d);
int ans(int l,int r);

int main(){
    int i,j,k,u,v;
    double x;
    V[0].D=123456789;
    scanf("%d",&N);
    for(i=1; i<N; i++){
        scanf("%d%d",&u,&v);
        V[u].C.push_back(v);
        V[v].C.push_back(u);
    }
    N2=2*N-1;
    x=log((double)N2)/log(2.0);
    N2=(int)ceil(x);
    N2=1<<(N2+1);
    scanf("%d",&M);
    for(i=0; i<M; i++) scanf("%d%d",Q[i],Q[i]+1);

    dfs(1,0);

    for(i=N2/2; i<N2 && i-N2/2<2*N-1; i++) t[i]=P[i-N2/2];
    i=N2/4;j=i*2;
    while(i){
        for(k=i; k<j; k++){
            if(V[t[2*k]].D<V[t[2*k+1]].D) t[k]=t[2*k];
            else t[k]=t[2*k+1];
        }
        i/=2;
        j/=2;
    }

    for(i=0; i<M; i++){
        j=V[Q[i][0]].p;
        k=V[Q[i][1]].p;
        if(j>k){
            u=j;
            j=k;
            k=u;
        }
        u=ans(j,k);
        printf("%d\n",u);
    }

    return 0;
}

void dfs(int n,int d){
    V[n].D=d;
    P.push_back(n);
    V[n].p=P.size()-1+N2/2;
    for(int i=0; i<V[n].C.size(); i++){
        if(V[n].C[i]==V[n].Pa) continue;
        V[V[n].C[i]].Pa=n;
        dfs(V[n].C[i],d+1);
        P.push_back(n);
    }
}

int ans(int l,int r){
    int Min=0;
    while(l<r){
        if(V[Min].D>V[t[l]].D) Min=t[l];
        if(V[Min].D>V[t[r]].D) Min=t[r];

        if(l%2==1){
            l++;
            if(V[Min].D>V[t[l]].D) Min=t[l];
        }
        if(r%2==0){
            r--;
            if(V[Min].D>V[t[r]].D) Min=t[r];
        }
        l/=2,r/=2;
    }

    if(l==r && V[Min].D>V[t[l]].D) Min=t[l];
    return Min;
}
