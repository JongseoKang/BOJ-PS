#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> g[200];
int N, M, d[200][200];

int dfs(int i, int from);

int main(){
	int i,j,u,v;

	scanf("%d%d",&N,&M);
	for(i=1; i<N; i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(i=1; i<=N; i++) for(j=0; j<=M; j++) d[i][j]=99999;
	printf("%d",dfs(1, 0));
	return 0;
}

int dfs(int i, int from){
	int r=99999;
	for(auto j : g[i]) if(j!=from) r=min(r,dfs(j, i));
	d[i][1]=g[i].size();
	for(auto j : g[i]){
		if(j==from) continue;
		for(int k=M; k>1; k--)
			for(int l=1; l<k; l++) d[i][k]=min(d[j][l]+d[i][k-l]-2, d[i][k]);
	}

	return min(d[i][M],r);
}
