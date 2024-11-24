#include<stdio.h>

char p[1030][2050];

void solve(int x, int y, int l);

int main(){
	int N, i, j;

	scanf("%d", &N);

	if(N & 1)
		solve((1 << N) - 2, 0, N);
	else
		solve((1 << N) - 2, (1 << N) - 2, N);

	if(N & 1){
		for(i = 0; i < (1 << N) - 1; i++){
			for(j = 0; j < (1 << N) - 1 + i; j++){
				printf("%c", (p[i][j] == '*' ? '*' : ' '));
			}
			puts("");
		}
	}
	else{
		for(i = 0; i < (1 << N) - 1; i++){
			for(j = 0; j < (1 << N + 1) - 3 - i; j++){
				printf("%c", (p[i][j] == '*' ? '*' : ' '));
			}
			puts("");
		}
	}


	return 0;
}

void solve(int x, int y, int l){
	if(l == 1){
		p[y][x] = '*';
		return;
	}

	if(l & 1){
		for(int i = 0; i < (1 << l) - 1; i++){
			p[y + i][x - i] = p[y + i][x + i] = p[y + (1 << l) - 2][x - i] = p[y + (1 << l) - 2][x + i] = '*';
		}
	}
	else{
		for(int i = 0; i < (1 << l) - 1; i++){
			p[y - i][x - i] = p[y - i][x + i] = p[y - (1 << l) + 2][x - i] = p[y - (1 << l) + 2][x + i] = '*';
		}
	}

	if(l & 1) solve(x, y + (1 << l) - 3, l - 1);
	else solve(x, y - (1 << l) + 3, l - 1);
}
