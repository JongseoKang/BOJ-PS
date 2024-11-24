#include<stdio.h>

long long can[2001][2001];
long long N, K, Q, T;

int main(){
	int i, j, k;

	scanf("%lld%lld%lld", &N, &K, &Q);
	for(i = 1; i <= N; i++){
		for(j = 0; j < K; j++){
			scanf("%d", &k);
			can[i][k]++;
		}
	}
	
	if(can[1][1] == K) T += N;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			T += ((j + N - i) % N) * can[i][j];
		}
	}
	
	if(T > N * Q) printf("0");
	else printf("1");
	return 0;
}