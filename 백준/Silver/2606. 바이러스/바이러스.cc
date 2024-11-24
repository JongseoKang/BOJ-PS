#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[101];
queue<int> que;
int N;
int check[101], cnt;

int main()
{
	int i, u, v;
	
	scanf("%d%d", &N, &i);
	while (i--)
	{
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	que.push(1), check[1] = 1;
	while (!que.empty())
	{
		for (i = 0; i < graph[que.front()].size(); i++)
		{
			if (!check[graph[que.front()][i]])
			{
				check[graph[que.front()][i]] = 1;
				que.push(graph[que.front()][i]);
				cnt++;
			}
		}

		que.pop();
	}

	printf("%d", cnt);
	return 0;
}