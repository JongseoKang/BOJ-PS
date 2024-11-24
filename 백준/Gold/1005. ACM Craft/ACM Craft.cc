#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int T;
	int i, j;

	scanf("%d", &T);
	while (T--)
	{
		vector<int> graph[1001];
		int table[1001] = { 0 };
		int degree[1001] = { 0 };
		int time[1001] = { 0 };
		int N, K, W, X, Y;

		scanf("%d%d", &N, &K);
		for (i = 1; i <= N; i++)
			scanf("%d", &time[i]);

		for (i = 0; i < K; i++)
		{
			scanf("%d%d", &X, &Y);
			graph[X].push_back(Y);
			degree[Y]++;
		}

		scanf("%d", &W);
		while (degree[W])
		{
			for (i = 0; i <= N; i++)
			{
				for (j = graph[i].size() - 1; !degree[i] && j >= 0; j--)
				{
					if (table[graph[i][j]] < table[i] + time[i])
						table[graph[i][j]] = table[i] + time[i];
					degree[graph[i][j]]--;
					graph[i].pop_back();
				}
			}
		}

		printf("%d\n", table[W] + time[W]);
	}

	return 0;
}