#include<stdio.h>
#include<vector>

using namespace std;

vector<int> g[100001];
int N,S,D,chk[100001],d[100001],cnt;

int dfs(int v);
void solve(int v);

int main(){
	int i,j,u,v;

	scanf("%d%d%d",&N,&S,&D);
	for(i=0; i<N-1; i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(S);
	solve(S);
	printf("%d",cnt);
	return 0;
}

int dfs(int v){
	int i,Max=0,c;
	chk[v]=1;
	for(i=0; i<g[v].size(); i++){
		if(!chk[g[v][i]]){
			c=dfs(g[v][i]);
			if(Max<c) Max=c;
		}
	}
	
	d[v]=Max;
	return Max+1;
}

void solve(int v){
	int i;
	chk[v]=0;
	for(i=0; i<g[v].size(); i++){
		if(chk[g[v][i]] && d[g[v][i]]>=D){
			cnt++;
			solve(g[v][i]);
			cnt++;
		}
	}
}