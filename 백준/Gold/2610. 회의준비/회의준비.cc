#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

struct member{
    int v, cost;
};

std::vector<int> g[101];
int check[101], group[101], result[101], ans[101];
int N, M, numGroups;

void bfs(int s);

int main(){
    int i;

    scanf("%d%d", &N,&M);
    for(i = 0; i < M; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= N; i++){
        check[i] = i;
        if(!group[i]) group[i] = ++numGroups;
        bfs(i);
    }

    printf("%d\n", numGroups);
    std::sort(result + 1, result + numGroups + 1);
    for(i = 1; i <= numGroups; i++) printf("%d\n", result[i]);

    return 0;
}

void bfs(int s){
    std::queue<member> q;

    q.push({s, 0});
    int ret = 0;
    while(!q.empty()){
        member f = q.front();
        ret = f.cost;
        q.pop();
        for(auto u = g[f.v].begin(); u != g[f.v].end(); u++){
            if(check[*u] != s){
                group[*u] = group[s];
                check[*u] = s;
                q.push({*u, f.cost + 1});
            }
        }
    }

    if(ans[group[s]] == 0 || ans[group[s]] > ret){
        ans[group[s]] = ret;
        result[group[s]] = s;
    }
}