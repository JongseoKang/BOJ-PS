#include<stdio.h>

int P[1001], table[1001], Max;

int main() {
	int N, i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
	}

	table[1] = P[1];
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= i; j++) {
			if (table[i] < table[j] + P[i - j]) {
				table[i] = table[j] + P[i - j];
			}
		}
	}

	for (i = 0; i <= N; i++) {
		if (Max < table[i]) Max = table[i];
	}

	printf("%d", Max);
	return 0;
}