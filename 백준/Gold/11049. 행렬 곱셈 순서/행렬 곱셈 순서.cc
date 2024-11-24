#include<stdio.h>

struct matrix
{
	int width;
	int height;
}arr[500];

long long table[500][500];
int N;

int main()
{
	int i, j, k;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d%d", &arr[i].height, &arr[i].width);

	for (i = 0; i < N - 1; i++)
		table[i][i + 1] = arr[i].height*arr[i].width*arr[i + 1].width;

	for (j = 2; j < N; j++)
	{
		for (i = 0; i < N - j; i++)
		{
			long long min = 999999999999999999ll;
			for (k = i; k < i + j; k++)
			{
				if (min > table[i][k] + table[k + 1][i + j] + arr[i].height*arr[k].width*arr[i + j].width)
					min = table[i][k] + table[k + 1][i + j] + arr[i].height*arr[k].width*arr[i + j].width;
			}

			table[i][i + j] = min;
		}
	}

	printf("%lld", table[0][N - 1]);
}