#include<stdio.h>

int N, T;
int goal;
int coin[21];
int table[50001];

void ini() {
	int i, j;
	for (i = 0; i <= 20; i++) coin[i] = 0;
	for (i = 1; i <= 50000; i++) {
		table[i] = 0;
	}
}

int main() {
	int i, j;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i<N; i++) scanf("%d", &coin[i]);
		scanf("%d", &goal);
		table[0] = 1;
		for (j = 0; j < N; j++) {
			for (i = 1; i <= goal; i++){
				if (i-coin[j]>=0) {				
					table[i] += table[i-coin[j]];
				}
			}
		}   
		printf("%d\n", table[goal]);
		ini();
	}

	return 0;
}