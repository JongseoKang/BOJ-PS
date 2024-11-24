#include<stdio.h>
#include<algorithm>

using namespace std;

struct XY
{
	int X, Y;
	bool operator() (XY a, XY b)
	{
		return a.X < b.X || (a.X == b.X && a.Y < b.Y);
	}
}fish[100];

int N, L, M;
int maxFish;

int main()
{
	int i, j, k, l;

	scanf("%d%d%d", &N, &L, &M);
	L /= 2;
	for (i = 0; i < M; i++)
		scanf("%d%d", &fish[i].X, &fish[i].Y);
	
	sort(fish, fish + M, XY());

	for (i = 0; i < M; i++)
	{
		j = 1;
		while (j < L)
		{
			for (l = 0; l <= j; l++)
			{
				int cnt = 0;
				for (k = 0; k < M; k++)
				{
					if (fish[i].X <= fish[k].X && fish[i].X + j >= fish[k].X &&
						fish[i].Y + l >= fish[k].Y && fish[i].Y + l - (L - j) <= fish[k].Y)
					{
						cnt++;
					}
				}

				if (cnt > maxFish)
					maxFish = cnt;
			}

			j++;
		}
	}

	printf("%d", maxFish);
	return 0;
}