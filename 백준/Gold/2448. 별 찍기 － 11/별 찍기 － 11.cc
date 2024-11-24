#include<stdio.h>

char p[3500][7000];

void solve(int x, int y, int l);

int main(){
	int N;
	scanf("%d", &N);

	solve(N - 1, 0, N);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N * 2 - 1; j++){
			printf("%c", (p[i][j] == '*' ? '*' : ' '));
		}
		puts("");
	}

	return 0;
}

void solve(int x, int y, int l){
	if(l == 3){
		p[y][x] = p[y + 1][x - 1 ] = p[y + 1][x + 1] = p[y + 2][x - 2] =
			p[y + 2][x - 1] = p[y + 2][x] = p[y + 2][x + 1] = p[y + 2][x + 2] = '*'; 
		return;
	}
	
	int t = l >> 1;
	solve(x, y, t);
	solve(x - t, y + t, t);
	solve(x + t, y + t, t);
}
