#include<stdio.h>

int N;
int table[2000];
int arr[2000];

int main() {
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	table[0] = 0, table[1] = arr[1], arr[0] = 0;
	for (i = 2; i <= N; i++) {
		for (j = 0; j<i; j++) {
			if (arr[i]>arr[j] && table[i]<table[j] + arr[i])
				table[i] = table[j] + arr[i];
		}
	}
    
    int max=-9999999;
	for (i=1; i<=N; i++) {
        if(max<table[i]) max=table[i];
    }
        
	printf("%d", max);
	return 0;
}