#include<stdio.h>
#include<math.h>

int A, B;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	int i,G,L;

	scanf("%d%d", &G, &L);

	B = L/G;
	A = (int)sqrt((double)B);

	while (B%A != 0 || gcd(B/A, A) > 1) {
		A--;
	}

	B /= A;
	printf("%d %d", G*A, G*B);
	return 0;
}