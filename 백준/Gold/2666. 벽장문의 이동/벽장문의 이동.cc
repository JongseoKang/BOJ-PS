#include<stdio.h>


int min = 2147483647;
int door, N;
int arr[20];
int open1, open2;

void back(int l, int r, int c, int level);

int main()
{
	int i;

	scanf("%d%d%d", &door, &open1, &open2);
	if (open1 > open2)
	{
		int temp = open1;
		open1 = open2;
		open2 = temp;
	}
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	back(open1, open2, 0, 0);
	printf("%d", min);
	return 0;
}

void back(int l, int r, int c, int level)
{
	if (c >= min) return;
	if (level == N)
	{
		min = c;
		return;
	}

	if (arr[level] > r)
		back(l, arr[level], c + arr[level] - r, level + 1);
	else back(l, arr[level], c + r - arr[level], level + 1);
	
	if (arr[level] < l)
		back(arr[level], r, c + l - arr[level], level + 1);
	else back(arr[level], r, c + arr[level] - l, level + 1);
}