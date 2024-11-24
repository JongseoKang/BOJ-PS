#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;

struct data{
	int a,ind;
	bool operator<(const data &p)const{
		return a<p.a || (a==p.a && ind<p.ind);
	}
};

set<data> s;
int A[200001],L[200000],R[200000],query[200000][2],N,M,Q;
int chk[200001];

int main(){
	int i,j,temp;

	scanf("%d%d%d",&N,&M,&Q);
	for(i=1; i<=N; i++) scanf("%d",A+i);
	for(i=0; i<M; i++) scanf("%d",L+i);
	for(i=0; i<M; i++) scanf("%d",R+i);
	for(i=0; i<Q; i++) scanf("%d%d",&query[i][0],&query[i][1]);
	
	sort(L,L+M);
	sort(R,R+M);
	int l=L[0],r=R[0];
	for(i=l; i<=r; i++){
		s.insert({A[i],i});
		chk[i]=1;
	}

	for(i=1; i<M; i++){
		if(L[i]>R[i]){
			for(j=0; j<Q; j++) printf("1000000000\n");
			return 0;
		}

		l=max(L[i],r+1);
		r=R[i];

		for(j=l; j<=r; j++){
			s.insert({A[j],j});
			chk[j]=1;
		}
	}
	for(i=0; i<Q; i++){
		l=query[i][0],r=query[i][1];
		s.erase({A[l],l});
		s.erase({A[r],r});
		temp=A[l];
		A[l]=A[r];
		A[r]=temp;
		if(chk[l]) s.insert({A[l],l});
		if(chk[r]) s.insert({A[r],r});
		auto it=s.end();
		printf("%d\n",(--it)->a);
	}

	return 0;
}