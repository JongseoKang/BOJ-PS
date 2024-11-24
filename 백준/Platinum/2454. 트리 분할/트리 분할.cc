#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
	int n,l,p;
	bool operator<(const node &y)const{
		return l>y.l || (l==y.l && p>y.p) || (l==y.l && p==y.p && n>y.n);
	}
}nodes[300001];

vector<int> g[300001];
int child[300001],len;
int N,K,rslt,chk[300001],sub[300001];

void leveling(int v,int level);

int main(){
	int i,j,u,v,min,min2;

	scanf("%d%d",&N,&K);
	for(i=1; i<N; i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	leveling(1,0);
	sort(nodes,nodes+N-1);
	for(i=0; i<N-1; i++){
		if(sub[nodes[i].n]<K) child[len++]=nodes[i].n;
		if(i==N-2 || nodes[i].p!=nodes[i+1].p){
			if(!len);
			else if(len==1 && sub[child[0]]+1<=K){
				sub[nodes[i].p]=sub[child[0]]+1;
				if(sub[nodes[i].p]==K) rslt++;
			}
			else if(len==1)
				rslt++;
			else{
				min=0;
				for(j=1; j<len; j++) min=sub[child[min]]>sub[child[j]] ? j:min;
				min2=!min ? 1:(min-1);
				for(j=1; j<len; j++){
					if(min==j) continue;
					min=sub[child[min2]]>sub[child[j]] ? j:min;
				}
				if(sub[child[min]]+sub[child[min2]]+2<=K) sub[nodes[i].p]=K;
				else{
					sub[nodes[i].p]=sub[child[min]]+1;
					if(sub[nodes[i].p]==K) rslt++;
				}
				rslt+=len-1;
			}
			len=0;
		}
	}
	
	if(sub[1]<K) rslt++;
	printf("%d",rslt);
	return 0;
}

void leveling(int v,int level){
	chk[v]=1;
	for(auto it=g[v].begin(); it!=g[v].end(); it++){
		if(!chk[*it]){
			nodes[*it-2]={*it,level+1,v};
			leveling(*it,level+1);
		}
	}
}