#include<stdio.h>
#include<vector>
#define MAX 1000000007

using namespace std;

struct VEC
{ 
	vector<int> print; 
}ini;
vector<VEC> bigP;

vector<int> edge[501];
vector<int> reverse_edge[501];

int number[501], len = 1;
int check1[501], check2[501];
int V, E, x, y,g[501][501];
long long degree[501],facto[501];

void DFS1(int v);
void DFS2(int v);

int main()
{
	int i,j,k,in;
	long long rslt=1,cnt;

	scanf("%d", &V);
	facto[0]=1;
	for(i=1; i<=V; i++){
		for(j=1; j<=V; j++){
			scanf("%d",&in);
			if(in){
				edge[i].push_back(j);
				reverse_edge[j].push_back(i);
			}
			g[i][j]=in;
			degree[i]+=in;
		}
		facto[i]=(facto[i-1]*i)%MAX;
	}

	for (i = 1; i <= V; i++)
		if (!check1[i]) DFS1(i);

	for (i = V; i > 0; i--)
	{
		if (!check2[number[i]])
		{
			DFS2(number[i]);
			bigP.push_back(ini);
			ini.print.clear();
		}
	}

	for (i = 0; i < bigP.size(); i++){
		cnt=0;
		for(j=1; j<=V; j++){
			for(k=0; k<bigP[i].print.size(); k++){
				if(!g[j][bigP[i].print[k]]) break;
			}
			if(k==bigP[i].print.size() && degree[j]-1==bigP[i].print.size()){
				cnt++;
			}
		}
		rslt*=facto[bigP[i].print.size()-1];
		rslt%=MAX;
		while(cnt--){
			rslt*=bigP[i].print.size();
			rslt%=MAX;
		}
	}
	
	printf("%lld",rslt);
	return 0;
}

void DFS1(int v)
{
	check1[v] = 1;
	for (int i = 0; i < edge[v].size(); i++)
		if (!check1[edge[v][i]]) { DFS1(edge[v][i]); }
	number[len++] = v;
}

void DFS2(int v)
{
	check2[v] = 1;
	for (int i = 0; i < reverse_edge[v].size(); i++)
		if (!check2[reverse_edge[v][i]]){ DFS2(reverse_edge[v][i]); }
	ini.print.push_back(v);
}