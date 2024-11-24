#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

/*struct XY
{
	int x, y;
}ini;*/

vector<int> graph[200001];
queue<int> que, save;

int N, M;
int check[200001];
int len;

int main()
{
	int i;

	scanf("%d%d", &N, &M);
	for (i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
	}

	que.push(1);
	check[1] = 1;

	while (!check[N])
	{
		while (!que.empty())
		{
			int u = que.front();

			for (i = 0; i < graph[u].size(); i++)
			{
				if (!check[graph[u][i]])
				{
					check[graph[u][i]] = 1;
					save.push(graph[u][i]);
				}
			}

			que.pop();
		}

		while (!save.empty())
		{
			que.push(save.front());
			save.pop();
		}

		if (que.empty()) break;
		len++;
	}

	if (check[N]) printf("%d", len);
	else printf("-1");
	return 0;
}