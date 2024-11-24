#include<stdio.h> 

int table[5000];
int mi[5000];

int main()
{
	int D1, D2;
	int i, j;
	int result = 0;

	for (i = 1; i < 5000; i++)
	{
		table[i] = i;
		mi[i] = i;
	}
	scanf("%d%d", &D1, &D2);

	for (i = 1; i <= D2; i++)
	{
		j = 2;

		while (i*j <= D2)
		{
			mi[i*j] -= mi[i];

			j++;
		}
	}

	for (i = 1; i < D2; i++)
	{
		j = 2;

		int s;
		if (i < D1)
			s = 1;
		else s = 0;

		while (i*j <= D2)
		{
			if (i*j >= D1 && s)
				s--;

			else table[i*j] -= mi[i];

			j++;
		}
	}

	for (i = D1; i <= D2; i++)
		result += table[i];

	printf("%d", result);
	return 0;
}
