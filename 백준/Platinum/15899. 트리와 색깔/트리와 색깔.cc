#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX 1000000007 

using namespace std;

vector<int> g[200001],tree[1<<19];
int color[200001],query[200001][2],chk[200001];
int N,M,C,S,cnt,rslt;
int ordering(int v);
void maketree(int v);
int solve(int l,int r,int c);

int main(){
	int i,u,v;

	scanf("%d%d%d",&N,&M,&C);
	S=N-1;
	i=0;
	while(S){ S>>=1; i++; }
	S=1<<i;

	for(i=1; i<=N; i++) scanf("%d",color+i);
	for(i=0; i<N-1; i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	ordering(1);
	for(i=1; i<=N; i++) tree[query[i][0]+S].push_back(color[i]);
	maketree(1);
	for(i=0; i<M; i++){
		scanf("%d%d",&u,&v);
		rslt+=solve(query[u][0]+S,query[u][1]+S,v);
		rslt%=MAX;
	}
	
	printf("%d",rslt);
	return 0;
}

int ordering(int v){
	chk[v]=1;
	int ret;
	query[v][0]=ret=cnt++;
	for(auto it=g[v].begin(); it!=g[v].end(); it++)
		if(!chk[*it])  ret=ordering(*it);

	return query[v][1]=ret;
}

void maketree(int v){
	if(v>=S) return;
	maketree(v*2);
	maketree(v*2+1);
	auto i=tree[v*2].begin(),j=tree[v*2+1].begin();
	while(i!=tree[v*2].end() || j!=tree[v*2+1].end()){
		if(i==tree[v*2].end() || (j!=tree[v*2+1].end() && *i>*j)){
			tree[v].push_back(*j);
			j++;
		}
		else{
			tree[v].push_back(*i);
			i++;
		}
	}
}

int solve(int l,int r,int c){
	int ret=0;
	while(l<r){
		if(l%2==1){
			ret+=upper_bound(tree[l].begin(),tree[l].end(),c)-tree[l].begin();
			l++;
		}
		if(r%2==0){
			ret+=upper_bound(tree[r].begin(),tree[r].end(),c)-tree[r].begin();
			r--;
		}
		if(l>=r) break;
		l>>=1, r>>=1;
	}

	if(l==r) ret+=upper_bound(tree[l].begin(),tree[l].end(),c)-tree[l].begin();
	return ret;
}