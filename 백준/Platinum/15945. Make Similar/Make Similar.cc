#include<stdio.h>
#include<algorithm>

using namespace std;

long long N,A[100000];

int main(){
	long long i,t;

	scanf("%lld",&N);
	for(i=0; i<N; i++){
		scanf("%lld", A+i);
		if(!A[i]){ i--, N--;}
	}
	if(!N || N==1){printf("0"); return 0;}
	sort(A,A+N);
	if((A[0]<0 && A[N-1]>0) || (A[0]>0 && A[N-1]<0)) printf("0");
	else if(A[0]>0){
		if(2*A[0]>A[N-1]) printf("%lld",A[N-1]-A[0]);
		else printf("%lld",A[0]);
	}	
	else{
		A[0]*=(-1);
		A[N-1]*=(-1);
		t=A[0];
		A[0]=A[N-1];
		A[N-1]=t;
		if(2*A[0]>A[N-1]) printf("%lld",A[N-1]-A[0]);
		else printf("%lld",A[0]);
	}
	return 0;
}