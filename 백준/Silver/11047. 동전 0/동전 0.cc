#include<stdio.h>

int coin[10];
int cnt;

int main()
{
	int N, W, i;
	scanf("%d%d", &N, &W);

	for (i = N-1; i >=0 ; i--) scanf("%d", &coin[i]);
	for (i = 0; i < N; i++)
	{
		cnt += W / coin[i];
		W %= coin[i];
	}

	printf("%d", cnt);
	return 0;
}