#include<stdio.h>

int N, M, A, B, K;
int block[100000][2];
int map[505][505];
int Sx, Sy, Ax, Ay;
int queue[255000][3], head, tail;
int move[4][2] = {{ 0,1 }, { 1,0 }, { 0,-1 }, { -1,0 }};

int main() {
	int i, j, k, X, Y, cnt;

	scanf("%d%d%d%d%d", &N, &M, &A, &B, &K);
	for (i = 0; i < K; i++) {
		scanf("%d%d", &block[i][0], &block[i][1]);
		map[block[i][0]][block[i][1]] = 2;
	}
	scanf("%d%d%d%d", &Sx, &Sy, &Ax, &Ay);

	queue[tail][0] = Sx;
	queue[tail++][1] = Sy;
	map[Sx][Sy] = 1;
	while (!map[Ax][Ay] && head < tail) {
		for (i = 0; i < 4; i++) {
			X = queue[head][0] + move[i][0];
			Y = queue[head][1] + move[i][1];
			if (map[X][Y]) continue;
			if (X > 0 && X + A-1 <= N && Y > 0 && Y + B-1 <= M) {
				cnt = 0;
				for (j = 0; j < A; j++) {
					for (k = 0; k < B; k++) {
						if (map[X + j][Y + k] == 2) {
							cnt = 1;
							break;
						}
					}
				}
				if (!cnt) {
					map[X][Y] = 1;
					queue[tail][0] = X;
					queue[tail][1] = Y;
					queue[tail++][2] = queue[head][2] + 1;
				}
			}
		}

		head++;
	}

	for (i = head; i < tail; i++) {
		if (queue[i][0] == Ax && queue[i][1] == Ay) {
			printf("%d", queue[i][2]);
			return 0;
		}
	}
	printf("-1");
}