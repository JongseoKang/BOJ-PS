#include<stdio.h>
#include<math.h>

int main() {
	int i, j, N;
	double sq;

	scanf("%d", &N);
	sq = sqrt((double)N);
	for (i = 2; i <= sq; i++) {
		if (N%i == 0) {
			break;
		}
	}
	
	if (i > sq) i = N;
	printf("%d", N - N / i);
	return 0;
}