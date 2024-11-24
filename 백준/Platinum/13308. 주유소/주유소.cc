#include<stdio.h>
#include<queue>
#include<vector>

struct st{
	long long node,cost;
	bool operator<(const st &p) const{
        return cost>p.cost;
    }
}ini;

std::priority_queue<st> heap;
std::vector<st> graph[2501];

int N,M;
long long dist[2501][2501];
long long gas[2501];
long long table[2501],min;
int check[2501];

int main(){
	long long i,j,k,u,v,c;
	long long temp;
	
	scanf("%d%d",&N,&M);	/*Begin of Input*/
	for(i=0;i<N;i++)scanf("%lld",&gas[i+1]);
	for(i=0;i<M;i++){
		scanf("%lld%lld%lld",&u,&v,&c);
		ini.node=v,ini.cost=c,graph[u].push_back(ini);
		ini.node=u,graph[v].push_back(ini);
	}						/*End of Input*/
	
	for(i=1;i<=N;i++){		/*Initialization(for Dijkstra)*/
		for(j=1;j<=N;j++){
			dist[i][j]=999999999	;
		}
	}
	
	for(i=1;i<=N;i++){		/*Begin of Dijkstra*/
		dist[i][i]=0;
		ini.node=i,ini.cost=0,heap.push(ini);
		for(j=0;j<N;j++)
		{
			v=heap.top().node,heap.pop();
			for(k=0;k<graph[v].size();k++){
				if(dist[i][graph[v][k].node]>dist[i][v]+graph[v][k].cost){
					dist[i][graph[v][k].node]=dist[i][v]+graph[v][k].cost;
					ini.node=graph[v][k].node,ini.cost=dist[i][graph[v][k].node];
					heap.push(ini);
				}
			}
		}
		while(!heap.empty()){
			heap.pop();
		}
	}						/*End of Dijstra*/	
	
	for(i=2;i<=N;i++)table[i]=300000000000;	/*Initialization(for DP)*/
	/*for(i=1;i<=N;i++)real[i]=i;
	
	for(i=1;i<=N;i++){
		for(j=1;j<=N-i;j++){
			if(gas[j]>gas[j+1]){
				temp=gas[j];
				gas[j]=gas[j+1];
				gas[j+1]=temp;
				temp=real[j];
				real[j]=real[j+1];
				real[j+1]=temp;
			}
		}
	}*/
	
	for(i=1;i<=N;i++){
		min=0;
		for(j=1;j<=N;j++){
			if(!check[j] && (!min || table[min]>table[j])){
				min=j;
			}
		}
		check[min]=1;
		for(j=1;j<=N;j++){
			if(table[j]>table[min]+dist[min][j]*gas[min]){
				table[j]=table[min]+dist[min][j]*gas[min];
			}
		}
	}
	
	printf("%lld",table[N]);
	return 0;
}