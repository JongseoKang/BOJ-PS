#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define A 'A'

int p, w;
int type[26] = { 21,22,23,31,32,33,41,42,43,51,52,53,61,62,63,71,72,73,74,81,82,83,91,92,93,94 };
char str[100000];

int main() {
	int i, r = 0, l;

	scanf("%d%d ", &p, &w);
	gets(str);
	int len = strlen(str);

	r = (type[str[0] - A] % 10)*p;
	l = type[str[0] - A] / 10;
	for (i = 1; i < len; i++) {
		if (str[i] == ' ') {
			r += p;
			l = 1;
		}
		else if ((type[str[i] - A] / 10) == l) {
			r += (w + (type[str[i] - A]%10) * p);
			l = type[str[i] - A] / 10;
		}
		else {
			r += (type[str[i] - A]%10) * p;
			l = type[str[i] - A] / 10;
		}
	}

	printf("%d", r);
	return 0;
}