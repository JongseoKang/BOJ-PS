#include<stdio.h>

int N;
int arr[30];
int arr2[30];
int from, value, count;

int main()
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	while (count < N)
	{
		value = arr[count];
		while (arr2[from])
			from = (from + 1) % N;
		arr2[from] = value;
		from = (from + value) % N;
		count++;
	}

	printf("%d\n", N);
	for (i = 0; i < N; i++)
		printf("%d ", arr2[i]);

	return 0;
}