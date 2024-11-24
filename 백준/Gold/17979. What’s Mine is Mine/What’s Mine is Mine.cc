#include<stdio.h>
#include<algorithm>

using namespace std;

struct ore{
	int s,e,t;
	bool operator<(const ore& cmp)const{
		return e<cmp.e;
	}
}in[10000];

int n,m,p[101],d[15001];

int main(){
	int i,j,Max;

	scanf("%d%d",&m,&n);
	for(i=1; i<=m; i++) scanf("%d",p+i);
	for(i=0; i<n; i++) scanf("%d%d%d",&in[i].s,&in[i].e,&in[i].t);
	sort(in,in+n);
	for(i=0; i<n; i++){
		Max=0;
		for(j=0; j<=in[i].s; j++)
			if(Max<d[j]) Max=d[j];
		if(d[in[i].e]<Max+(in[i].e-in[i].s)*p[in[i].t])
			d[in[i].e]=Max+(in[i].e-in[i].s)*p[in[i].t];
	}

	for(i=0; i<n; i++) 
		if(d[in[i].e]>Max) Max=d[in[i].e];
	printf("%d",Max);
	return 0;
}