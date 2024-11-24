#include<stdio.h>
#define MAX 10007

int memo[100001],n;
int recur(int x);

int main(){
	scanf("%d",&n);
	printf("%d",recur(n));
	return 0;
}

int recur(int x){
	if(x==0 || x==1) return 1;
	if(memo[x]) return memo[x];
	return memo[x]=(recur(x-1)+recur(x-2))%MAX;
}