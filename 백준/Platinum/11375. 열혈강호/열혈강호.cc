#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> man[1001];
int check[1001],W[1001];

int dfs(int u){
    check[u]=1;
    for(int i=0; i<man[u].size(); i++){
        if(!W[man[u][i]] || (!check[W[man[u][i]]] && dfs(W[man[u][i]]))){
            W[man[u][i]]=u;
            return 1;
        }
    }
    return 0;
}

int main(){
    int N,M,i,j,a,b,cnt=0;

    scanf("%d%d",&N,&M);
    for(i=1; i<=N; i++){
        scanf("%d",&a);
        for(j=0; j<a; j++){scanf("%d",&b); man[i].push_back(b);}
    }

    for(i=1; i<=N; i++){ fill(check,check+N,0); cnt+=dfs(i); }

    printf("%d",cnt);
    return 0;
}
