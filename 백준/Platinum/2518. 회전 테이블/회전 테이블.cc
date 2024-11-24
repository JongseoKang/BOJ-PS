#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define min(a,b) (a<b ? a:b)
#define abs(a) ((a)>0 ? (a):-(a))

using namespace std;

int N;
int t[101][101][101][3];
int p[3][101];
int wish[3];

int d(int a, int b);
int f(int a, int b, int c);
int main() {
	int i, j, k, l;
	int a, b, c;

	scanf("%d", &N);

	for (i = 0; i<3; i++) {
		scanf("%d", &wish[i]);
		for (j = 1; j <= wish[i]; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	p[0][0] = 1;
	p[1][0] = N / 3 + 1;
	p[2][0] = N / 3 * 2 + 1;

	for (i = 0; i<=wish[0]; i++) {
		for (j = 0; j<=wish[1]; j++) {
			for (k = 0; k<=wish[2]; k++) {
				t[i][j][k][0] = 99999999;
				t[i][j][k][1] = 99999999;
				t[i][j][k][2] = 99999999;
			}
		}
	}

	/*    t[1][0][0][0]=d(1,p[0][0]);
	t[0][1][0][1]=d(N/3+1,p[1][0]);
	t[0][0][1][2]=d(N/3*2+1,p[2][0]);*/
	t[0][0][0][0] = t[0][0][0][1] = t[0][0][0][2] = 0;

	for (i = 0; i <= wish[0]; i++) {
		for (j = 0; j <= wish[1]; j++) {
			for (k = 0; k <= wish[2]; k++) {
				a = t[i][j][k][0] + d(p[0][i], p[0][i + 1]);
				b = t[i][j][k][1] + d(f(p[1][j], N / 3 + 1, p[0][i + 1]), 1);
				c = t[i][j][k][2] + d(f(p[2][k], N / 3 * 2 + 1, p[0][i + 1]), 1);
				t[i + 1][j][k][0] = min(a, min(c, b));
				a = t[i][j][k][0] + d(f(p[0][i], 1, p[1][j + 1]), N / 3 + 1);
				b = t[i][j][k][1] + d(p[1][j], p[1][j + 1]);
				c = t[i][j][k][2] + d(f(p[2][k], N / 3 * 2 + 1, p[1][j + 1]), N / 3 + 1);
				t[i][j + 1][k][1] = min(a, min(c, b));
				a = t[i][j][k][0] + d(f(p[0][i], 1, p[2][k + 1]), N / 3 * 2 + 1);
				b = t[i][j][k][1] + d(f(p[1][j], N / 3 + 1, p[2][k + 1]), N / 3 * 2 + 1);
				c = t[i][j][k][2] + d(p[2][k], p[2][k + 1]);
				t[i][j][k + 1][2] = min(a, min(b, c));
			}
		}
	}

	a = min(t[wish[0]][wish[1]][wish[2]][0], t[wish[0]][wish[1]][wish[2]][1]);
	a = min(a, t[wish[0]][wish[1]][wish[2]][2]);
	printf("%d", a);
	return 0;
}

int d(int a, int b) {
	int temp;
	if (a>b) {
		temp = a;
		a = b;
		b = temp;
	}
	if (-a + b<N + a - b) return -a + b;
	else return N + a - b;
}

int f(int a, int b, int c) {
	if (c - a + b>N) return c - a + b - N;
	if (c - a + b>0) return c - a + b;
	return c - a + b + N;
}
