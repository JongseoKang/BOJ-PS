#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

int N, M, L;
int hunter[100000];
int prey[2];

int bsearch(int l, int r, int c);

int main()
{
	int i, j, cnt = 0;

	scanf("%d%d%d", &M, &N, &L);
	for (i = 0; i < M; i++) {
		scanf("%d", &hunter[i]);
	}

	sort(hunter, hunter + M);

	for (i = 0; i < N; i++) {
		scanf("%d%d", &prey[0], &prey[1]);
		j = hunter[bsearch(0, M - 1, prey[0])];
		if (abs(j - prey[0]) + prey[1]<=L) {
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}

int bsearch(int l, int r, int c) {
	if (l == r) return l;
	if (l + 1 == r) {
		if (abs(hunter[l] - c) < abs(hunter[r] - c))
			return l;
		return r;
	}
	if (hunter[(l + r) / 2] > c) return bsearch(l, (l + r) / 2, c);
	else return bsearch((l + r) / 2, r, c);
}