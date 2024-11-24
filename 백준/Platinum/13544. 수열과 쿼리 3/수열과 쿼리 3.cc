#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> tree[1<<18];
int A[100000],N,S;
int solve(int l,int r,int c);

int main(){
	int M,i,j,k,a,b,c,last=0;

	scanf("%d",&N);
	S=N-1;
	i=0;
	while(S){ S>>=1; i++; }
	S=1<<i;

	for(i=0; i<N; i++){
		scanf("%d",A+i);
		tree[S+i].push_back(A[i]);
	}

	for(i=S-1; i>0; i--){
		tree[i].resize(tree[i*2].size()+tree[i*2+1].size());
		merge(tree[i*2].begin(),tree[i*2].end(),tree[i*2+1].begin(),
		tree[i*2+1].end(),tree[i].begin());
	}
	
	scanf("%d",&M);
	while(M--){
		scanf("%d%d%d",&a,&b,&c);
		i=last^a;
		j=last^b;
		k=last^c;
		last=solve(S+i-1,S+j-1,k);
		printf("%d\n",last);
	}

	return 0;
}

int solve(int l,int r,int c){
	int ret=0;
	while(l<r){
		if(l%2==1){
			ret+=tree[l].end()-upper_bound(tree[l].begin(),tree[l].end(),c);
			l++;
		}
		if(r%2==0){
			ret+=tree[r].end()-upper_bound(tree[r].begin(),tree[r].end(),c);
			r--;
		}
		if(l>=r) break;
		l>>=1, r>>=1;
	}

	if(l==r)
		ret+=tree[r].end()-upper_bound(tree[r].begin(),tree[r].end(),c);

	return ret;
}