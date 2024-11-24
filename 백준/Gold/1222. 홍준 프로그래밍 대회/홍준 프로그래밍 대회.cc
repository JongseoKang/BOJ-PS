#include<stdio.h>
#include<math.h>

int N, r = 1;
long long twenty_million[2000001];
long long a, b;

int main() {
	int i, j, st;
	double sq;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &st);
		sq = sqrt((double)st);
		for (j = 1; j <= sq; j++) {
			if (st%j == 0) {
				twenty_million[j]++;
				if(j*j!=st)
				twenty_million[st / j]++;
			}
		}
	}

	for (i = 2; i <= 2000000; i++) {
		if (twenty_million[i] < 2) continue;
		a = r*twenty_million[r];
		b = i*twenty_million[i];
		if (a < b) {
			r = i;
		}
	}

	printf("%lld", r*twenty_million[r]);
	return 0;
}