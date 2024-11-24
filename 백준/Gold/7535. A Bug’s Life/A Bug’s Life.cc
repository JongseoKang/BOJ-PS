#include<stdio.h>
#include<vector>
#include<queue>

#define COLOR(s) (s==1 ? 2:1)

using namespace std;

int main()
{
	int T, N, M;
	
	scanf("%d", &T);

	int k = 1;
	while (k <= T)
	{
		vector<int> graph[2001];
		int color[2001] = { 0 };
		int i, j, x, y, end = 0;

		scanf("%d%d", &N, &M);
		for (i = 0; i < M; i++)
		{
			scanf("%d%d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (i = 1; i <= N; i++)
		{
			if (!color[i])
			{
				queue<int> que;
				que.push(i);
				color[i] = 1;
				while (!que.empty())
				{
					int s = que.front();
					for (j = 0; j < graph[s].size(); j++)
					{
						if (!color[graph[s][j]]) 
						{ color[graph[s][j]] = COLOR(color[s]); que.push(graph[s][j]); }
						else if (color[graph[s][j]] == color[s]) { end = 1; break; }
					}
					if (end) break;
					que.pop();
				}
				if (end) break;
			}
			if (end) break;
		}

		if (end) printf("Scenario #%d:\nSuspicious bugs found!\n\n", k);
		else printf("Scenario #%d:\nNo suspicious bugs found!\n\n", k);
		k++;
	}

	return 0;
}