#include<stdio.h> 

int N;
long long gas[100000],len[100000];
long long min,cost;

int main(){
	int i;
	
	scanf("%d",&N);
	for(i=0;i<N-1;i++)scanf("%lld",&len[i]);
	for(i=0;i<N;i++)scanf("%lld",&gas[i]);
	
	min=gas[0];
	for(i=0;i<N-1;i++){
		if(min>gas[i])min=gas[i];
		cost+=min*len[i];
	}
	
	printf("%lld",cost);
	return 0;
}