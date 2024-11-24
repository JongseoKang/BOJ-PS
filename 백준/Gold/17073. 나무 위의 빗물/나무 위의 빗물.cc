#include<stdio.h>
#include<vector>

using namespace std;

vector<int> g[500001];
int N,W,chk[500001];

int dfs(int u);

int main(){
    int i,j,k;
    double ret;

    scanf("%d%d",&N,&W);
    for(i=0; i<N-1; i++){
        scanf("%d%d",&j,&k);
        g[j].push_back(k);
        g[k].push_back(j);
    }

    ret=(double)dfs(1);
    printf("%.4f",W/ret);
    return 0;
}

int dfs(int u){
    int ret=0;
    chk[u]=1;

    for(auto it=g[u].begin(); it!=g[u].end(); it++){
        if(!chk[*it]){
            ret+=dfs(*it);
        }
    }

    if(ret>0) return ret;
    return 1;
}
