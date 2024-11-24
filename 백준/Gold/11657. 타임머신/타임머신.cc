#include<stdio.h>
#include<vector>

using namespace std;

struct edge{
	long long u,v,c;
};

vector<edge> g;

int N,M;
long long dist[501];

int main(){
	int i,j;
	int u,v,c;
	
	scanf("%d%d",&N,&M);
	
	dist[1]=0;
	for(i=2; i<=N; i++) dist[i]=99999999999999999;
	
	for(i=0; i<M; i++){
		scanf("%lld%lld%lld",&u,&v,&c);
		g.push_back({u,v,c});
	}
	
	for(i=0; i<N-1; i++){
		for(j=0; j<M; j++){
			if(dist[g[j].v]>dist[g[j].u]+g[j].c)
				dist[g[j].v]=dist[g[j].u]+g[j].c;
		}
	}
	
	for(j=0; j<M; j++){
		if(dist[g[j].u]<=60000000 && dist[g[j].v]>dist[g[j].u]+g[j].c){
			printf("-1");
			return 0;
		}
	}
	
	for(i=2; i<=N; i++) printf("%lld\n", (dist[i]<=60000000 ? dist[i]:-1));
	return 0;
}