#include<stdio.h>
#include<string.h>
#include<vector>
#define PRINT(a,b) (a==b ? "YES":"NO")

int N,Q,len;
int query[400000][3];
int p[200001][2];
int parent[200001];
char result[200001][4];
int Find(int v);
void Union(int u,int v);

int main() {
	int i,j,Pa,Pb;
	
	scanf("%d%d",&N,&Q);
	parent[1]=1;
	for(i=2;i<=N;i++)scanf("%d",&parent[i]);
	for(i=0;i<N-1+Q;i++){
		scanf("%d",&query[i][0]);
		if(!query[i][0])scanf("%d",&query[i][1]);
		else scanf("%d%d",&query[i][1],&query[i][2]);
	}
	
	for(i=1;i<=N;i++){p[i][0]=i,p[i][1]=1;}
	for(i=N-2+Q;i>=0;i--){
		if(!query[i][0]){
			Union(query[i][1],parent[query[i][1]]);
		}
		else{
			Pa=Find(query[i][1]);
			Pb=Find(query[i][2]);
			strcpy(result[len++],PRINT(Pa,Pb));
		}
	}
	
	for(i=len-1;i>=0;i--){
		printf("%s\n",result[i]);
	}
	return 0;
}

int Find(int v){
	int u=v;
	std::vector<int>collapse;
	while(u!=p[u][0]){
		collapse.push_back(u);
		u=p[u][0];
	}
	for(int i=0;i<collapse.size();i++){p[collapse[i]][0]=u;}
	return u;
}

void Union(int u,int v){
	u=Find(u);
	v=Find(v);
	if(p[u][1]>p[v][1]){p[v][0]=u;}
	else if(p[u][1]<p[v][1]){p[u][0]=v;}
	else{p[v][0]=u;p[u][1]++;}
	return;
}