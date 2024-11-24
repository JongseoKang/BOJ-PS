#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

struct state
{
	long long time, garnet, V;
	bool operator <(const state &s)const
	{
		return s.time < time || (s.time == time && s.garnet > garnet);
	}
}ini;

vector<state> graph[50001];
long long T[50001][2];
long long G[50001][2];

int e;
int S, M, N;
int x, y, t, g;

int main()
{
	int i, j, k = 1;

	scanf("%d", &S);
	while (k <= S)
	{
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; i++)
		{
			graph[i].clear();
			T[i][0] = 1ll << 63 - 1;
			T[i][1] = 1ll << 63 - 1;
			G[i][0] = 0;
			G[i][1] = 0;
		}

		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d%d", &x, &y, &t, &g);
			ini.V = y;
			ini.time = t;
			ini.garnet = g;
			graph[x].push_back(ini);
			ini.V = x;
			ini.time = t;
			ini.garnet = g;
			graph[y].push_back(ini);
		}

		priority_queue<state> que;
		e = 0;
		T[1][0] = 0;
		G[1][0] = 0;
		ini.V = 1;
		ini.garnet = 0;
		ini.time = 0;
		que.push(ini);

		while (1)
		{
			state min = que.top();
			que.pop();
			if (min.V == N) e++;
			if (e == 2) break;
			for (j = 0; j < graph[min.V].size(); j++)
			{
				if (T[graph[min.V][j].V][0] > min.time + graph[min.V][j].time ||
					(T[graph[min.V][j].V][0] == min.time + graph[min.V][j].time &&
					G[graph[min.V][j].V][0] < min.garnet + graph[min.V][j].garnet))
				{
					T[graph[min.V][j].V][1] = T[graph[min.V][j].V][0];
					G[graph[min.V][j].V][1] = G[graph[min.V][j].V][0];
					T[graph[min.V][j].V][0] = min.time + graph[min.V][j].time;
					G[graph[min.V][j].V][0] = min.garnet + graph[min.V][j].garnet;
					ini.V = graph[min.V][j].V;
					ini.time = T[graph[min.V][j].V][0];
					ini.garnet = G[graph[min.V][j].V][0];
					que.push(ini);
				}
				else if (T[graph[min.V][j].V][1] > min.time + graph[min.V][j].time || 
					(T[graph[min.V][j].V][1] == min.time + graph[min.V][j].time &&
					G[graph[min.V][j].V][1] < min.garnet + graph[min.V][j].garnet))
				{
					T[graph[min.V][j].V][1] = min.time + graph[min.V][j].time;
					G[graph[min.V][j].V][1] = min.garnet + graph[min.V][j].garnet;
					ini.V = graph[min.V][j].V;
					ini.time = T[graph[min.V][j].V][1];
					ini.garnet = G[graph[min.V][j].V][1];
					que.push(ini);
				}
			}
		}

		if (T[N][0] == T[N][1])
			printf("Game #%d: Suckzoo ends game in time %lld, earning %lld garnet(s).\n", k, T[N][0], G[N][0]);
		else printf("Game #%d: Suckzoo ends game in time %lld, earning %lld garnet(s).\n", k, T[N][1], G[N][1]);
		k++;
	}
	return 0;
}