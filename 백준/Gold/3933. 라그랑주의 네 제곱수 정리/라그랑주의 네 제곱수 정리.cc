#include<stdio.h>
#define MAX_SIZE 1<<15

int table[5][MAX_SIZE + 1];

int main()
{
	int i, j, k;
	int input;

	table[0][0] = 1;
	for (k = 1; k*k <= MAX_SIZE; k++)
	{
		for (i = 1; i <= 4; i++)
		{
			for (j = k*k; j <= MAX_SIZE; j++)
			{
				table[i][j] += table[i - 1][j - k*k];
			}
		}
	}

	scanf("%d", &input);
	while (input)
	{
		printf("%d\n", table[1][input] + table[2][input] + table[3][input] + table[4][input]);
		scanf("%d", &input);
	}

	return 0;
}