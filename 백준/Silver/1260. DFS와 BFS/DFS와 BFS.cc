#include<stdio.h>

void dfs(int u);
void bfs(int u);

int dprint[1001],bprint[1001];
int dlen,blen,head;
int dcheck[1001],bcheck[1001];
int N,M,V;
int edge[1001][1001];

int main(){
    int i,u,v;

    scanf("%d%d%d",&N,&M,&V);
    for(i=0; i<M; i++){
        scanf("%d%d",&u,&v);
        edge[u][v]=edge[v][u]=1;
    }

    dfs(V);
    bfs(V);

    for(i=0; i<dlen; i++) printf("%d ",dprint[i]);
    puts("");
    for(i=0; i<blen; i++) printf("%d ",bprint[i]);
    return 0;
}

void dfs(int u){
    int i;
    dprint[dlen++]=u;
    dcheck[u]=1;
    for(i=1; i<=N; i++){
        if(!dcheck[i] && edge[u][i]){
            dfs(i);
        }
    }
}

void bfs(int u){
    int i;
    bprint[blen++]=u;
    bcheck[u]=1;
    while(head<blen){
        for(i=1; i<=N; i++){
            if(!bcheck[i] && edge[bprint[head]][i]){
                bprint[blen++]=i;
                bcheck[i]=1;
            }
        }
        head++;
    }
}
