#include<stdio.h>
#include<algorithm>

using namespace std;

long long d[50002][11],sum;
int N,K,line[50];

int main(){
	int i,j,k;

	scanf("%d",&N);
	for(i=0; i<N; i++) scanf("%d",line+i);
	scanf("%d",&K);
	if(K<3){ puts("0"); return 0; }
	sort(line,line+N);

	for(j=0; j<N; j++){
		for(i=min(K,j+1); i>=1; i--){
			if(i==1) d[line[j]][1]++;
			else{
				for(k=50001; k>0; k--){
					d[min(k+line[j],50001)][i]+=d[k][i-1];
					if(i==K && k>line[j]) sum+=d[k][i-1];
				}
			}
		}
	}
	
	printf("%lld",sum);
	return 0;
}