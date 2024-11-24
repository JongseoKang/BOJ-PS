#include<stdio.h>

long long pascal[31][31];
long long result;

int main()
{
	long long N, M, K;
	long long x, y;

	scanf("%lld%lld%lld", &N, &M, &K);

	if (!K) K = 1;
	x = (K - 1) % M + 1;
	y = (K - 1) / M + 1;

	pascal[0][0] = 1;
	for (int i = 1; i <= N + M; i++)
	{
		pascal[i][0] = 1;
		for (int j = 1; j <= i; j++)
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
	}

	result = pascal[x + y - 2][x - 1] * pascal[M + N - x - y][M - x];
	printf("%lld", result);
	return 0;
}

