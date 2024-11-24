#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

long long arr[5000];

int bsearch(int l, int r, long long c);

int main() {
	int i, j, N, x;
	long long a=99999999999, b=0, c=0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + N);
	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {
			x = bsearch(j + 1, N - 1, -arr[i] - arr[j]);
			if (labs(arr[i] + arr[j] + arr[x]) < labs(a + b + c)) {
				a = arr[i];
				b = arr[j];
				c = arr[x];
			}
		}
	}

	printf("%lld %lld %lld", a, b, c);
	return 0;
}

int bsearch(int l, int r, long long c) {
	if (l == r) return l;
	if (l + 1 == r) {
		if (labs(c - arr[l]) < labs(c - arr[r])) {
			return l;
		}
		return r;
	}
	if (arr[(l + r) / 2] == c) return (l + r) / 2;
	if (arr[(l + r) / 2] > c)
	{
		return bsearch(l, (l + r) / 2, c);
	}
	else {
		return bsearch((l + r) / 2, r, c);
	}
}