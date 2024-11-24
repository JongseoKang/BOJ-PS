#include<stdio.h>

int main(){
	int X,N,i;
	int a,b,sum=0;

	scanf("%d%d",&X,&N);
	for(i=0; i<N; i++){
		scanf("%d%d",&a,&b);
		sum+=a*b;
	}

	if(sum==X) printf("Yes");
	else printf("No");
	return 0;
}