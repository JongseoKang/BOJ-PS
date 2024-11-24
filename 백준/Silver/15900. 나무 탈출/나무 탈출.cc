#include<stdio.h>
#include<vector>

using namespace std;

vector<int>g[500001];
int N,chk[500001];
long long cnt;
void dfs(int v,long long level){
	bool flag=true;
	chk[v]=1;
	for(auto it=g[v].begin(); it!=g[v].end(); it++){
		if(!chk[*it]){
			dfs(*it,level+1);
			flag=false;
		}
	}
	chk[v]=0;
	if(flag) cnt+=level;
}

int main(){
	int i,u,v;

	scanf("%d",&N);
	for(i=0; i<N-1; i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	if(cnt%2==1) printf("Yes");
	else printf("No");
	return 0;
}