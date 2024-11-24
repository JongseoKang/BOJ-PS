#include<stdio.h>

int rslt[3000001];

int main(){
	int i,j,k,t,n;

	scanf("%d",&n);
	i=3,j=0;
	while(i<=n){
		j++;
		for(k=1; k<=i/3; k++)
			rslt[i+k]=j;
		j++;
		for(; k<=i; k++)
			rslt[i+k]=j;
		i*=2;
		rslt[i]=j;
	}

	printf("%d",rslt[n]);
	return 0;
}