#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

long long N,M,K;
vector<long long> inf[26];
char mstr[26][200001],nstr[200001],ds[2]={'R','U'};

int main(){
	long long i,j,l,r,rslt=0;

	scanf("%lld%lld%lld",&N,&M,&K);
	for(i=0; i<K; i++){
		scanf("%s",mstr[i]);
		inf[i].push_back(-1);
		for(j=0; j<M; j++){
			if(mstr[i][j]=='U') inf[i].push_back(j);
		}
		inf[i].push_back(M);
	}	

	scanf("%s",nstr);
	r=M-1;
	l=(*(lower_bound(inf[nstr[N-1]-'A'].begin(),inf[nstr[N-1]-'A'].end(),M-1)-1))+1;
	rslt+=(r-l+1);
	for(i=N-2; i>=0; i--){
		r=(*(upper_bound(inf[nstr[i]-'A'].begin(),inf[nstr[i]-'A'].end(),r)-1));
		if(r<l) break;
		l=(*(lower_bound(inf[nstr[i]-'A'].begin(),inf[nstr[i]-'A'].end(),l)-1))+1;
		rslt+=(r-l+1);
	}
	printf("%lld",rslt);
	return 0;
}