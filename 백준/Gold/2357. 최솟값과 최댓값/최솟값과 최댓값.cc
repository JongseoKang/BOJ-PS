#include<stdio.h>
#define MAX 0
#define MIN 1

int N, M, S;
int tree[500000];
int prob[100000][2];
int print[100000][2];

int ans;
void search(int l, int r, int comp);
void creation(int level, int len, int comp);
int rtn(int a, int b, int comp)
{
	if (comp == MAX)
	{
		if (a > b) return a;
		return b;
	}

	if (a < b) return a;
	return b;
}

int main()
{
	int i, j;
	int input;

	scanf("%d%d", &N, &M);

	i = 1;
	S = 1;
	while (i < N)
	{
		i *= 2;
		S += i;
	}
	S -= i;

	for (i = 0; i < N; i++)
	{
		scanf("%d", &input);
		tree[S + i] = input;
	}

	for (i = 0; i < M; i++)
		scanf("%d%d", &prob[i][0], &prob[i][1]);

	creation(S, N, MAX);
	for (i = 0; i < M; i++)
	{
		ans = 0;
		search(S + prob[i][0] - 1, S + prob[i][1] - 1, MAX);
		print[i][1] = ans;
	}

	creation(S, N, MIN);
	for (i = 0; i < M; i++)
	{
		ans = 1000000000;
		search(S + prob[i][0] - 1, S + prob[i][1] - 1, MIN);
		print[i][0] = ans;
	}

	for (i = 0; i < M; i++)
		printf("%d %d\n", print[i][0], print[i][1]);

	return 0;
}

void search(int l, int r, int comp)
{
	if (l > r)
		return;

	if (l == r)
	{
		ans = rtn(ans, tree[l], comp); return;
	}

	if (l % 2 == 0)
	{
		ans = rtn(ans, tree[l], comp);
		l++;
	}

	if (r % 2 == 1)
	{
		ans = rtn(ans, tree[r], comp);
		r--;
	}

	search(l / 2, (r - 1) / 2, comp);
}

void creation(int level, int len, int comp)
{
	if (!level) return;

	for (int i = 0; i < len; i += 2)
		tree[(level + i) / 2] = rtn(tree[level + i], tree[level + i + 1], comp);

	creation(level / 2, (len + 1) / 2, comp);
}