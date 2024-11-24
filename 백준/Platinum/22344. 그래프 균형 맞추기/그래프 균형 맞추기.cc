#include<stdio.h>
#include<vector>
#include<algorithm>
#define abs(a) (a>0 ? (a):-(a))

using namespace std;

struct edge{
	int u;
	long long c;
};
struct f{
	long long val,sign;
}num[100001];
vector<edge> g[100001];

int N,M,visit[100001],ansChk;
long long A[100000],ans;
bool dfs(int u,int prev){
	visit[u]=1;
	for(auto i : g[u]){
		if(i.u==prev)continue;
		if(visit[i.u]){
			if(num[u].sign!=num[i.u].sign){
				if(num[u].val+num[i.u].val!=i.c) return false;
			}
			else{
				long long temp=i.c-num[u].val-num[i.u].val;
				if(abs(temp)&1) return false;
				if(!ansChk){
					ansChk=1;
					ans=temp/(num[u].sign+num[i.u].sign);
				}
				else if(ans!=temp/(num[u].sign+num[i.u].sign)) return false;
			}
		}else{
			num[i.u]={i.c-num[u].val,-num[u].sign};
			if(!dfs(i.u,u)) return false;
		}
	}

	return true;
}

int main(){
	int i, u,v;
	long long c;

	scanf("%d%d",&N,&M);
	while(M--){
		scanf("%d%d%lld",&u,&v,&c);
		g[u].push_back({v,c});
		g[v].push_back({u,c});
	}
	
	num[1]={0,1};
	if(dfs(1,0)){
		if(!ansChk){
			for(i=1; i<=N; i++) A[i-1]=-num[i].sign*num[i].val;
			sort(A,A+N);
			ans=A[N/2];
		}

		printf("Yes\n");
		for(i=1; i<=N; i++){
			printf("%lld ",num[i].val+ans*num[i].sign);
		}
	}else{
		printf("No");
	}
	return 0;
}
