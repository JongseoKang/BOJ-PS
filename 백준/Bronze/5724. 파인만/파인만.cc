#include<stdio.h>

int N;

int main()
{
	int i, j;
	while (1)
	{
		scanf("%d", &N);

		if (!N)
			return 0;

		int square = 0;
		for (i = 1; i <= N; i++)
		{
			square += (N - i + 1)*(N - i + 1);
		}

		printf("%d\n", square);
	}
}