#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

struct state{
	int t,p;
}init,h;

vector<int> g[200001];
queue<state> q;
int bel[200001],chk[200001],result[200001],N,M;

int main(){
	int i,j,input;

	scanf("%d",&N);
	for(i=1; i<=N; i++){
		while(1){
			scanf("%d",&input);
			if(input)
				g[i].push_back(input);
			else break;
		}
		result[i]=-1;
	}

	scanf("%d",&M);
	for(i=0; i<M; i++){
		scanf("%d",&input);
		chk[input]=1;
		init.t=0, init.p=input;
		q.push(init);
	}

	while(!q.empty()){
		h=q.front();
		q.pop();
		result[h.p]=h.t;
		for(i=0; i<g[h.p].size(); i++){
			if(!chk[g[h.p][i]]){
				bel[g[h.p][i]]++;
				if(bel[g[h.p][i]]>(g[g[h.p][i]].size()-1)/2){
					chk[g[h.p][i]]=1;
					init.t=h.t+1, init.p=g[h.p][i];
					q.push(init);
				}
			}
		}
	}

	for(i=1; i<=N; i++) printf("%d ",result[i]);
	return 0;
}