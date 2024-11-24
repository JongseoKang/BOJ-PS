#include<stdio.h>

int N;
int table[100000][3];	//[N][0]=X, [N][1]=Left, [N][2]=Right

int main()
{
	int i, j;

	scanf("%d", &N);

	table[0][0] = 1;
	table[1][0] = 1;
	table[1][1] = 1;
	table[1][2] = 1;

	for (i = 2; i <= N; i++)
	{
		table[i][0] = (table[i - 1][0] + table[i - 1][1] + table[i - 1][2])%9901;
		table[i][1] = (table[i - 1][0] + table[i - 1][2])%9901;
		table[i][2] = (table[i - 1][0] + table[i - 1][1])%9901;
	}

	printf("%d", (table[N][0] + table[N][1] + table[N][2]) % 9901);
	return 0;
}