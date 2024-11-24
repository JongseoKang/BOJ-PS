#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> mstree[1<<19];
int K,S;
int A[200000];

int solve(int l,int r,int c);

int main(){
	int i,temp=0,N=-1,M=-1;

	scanf("%d",&K);
	S=K-1;
	i=0;
	while(S){ S>>=1; i++; }
	S=1<<i;

	for(i=0; i<K; i++){
		scanf("%d",A+i);
		mstree[S+i].push_back(A[i]);
	}

	for(i=S-1; i>0; i--){
		mstree[i].resize(mstree[i*2].size()+mstree[i*2+1].size());
		merge(mstree[i*2].begin(),mstree[i*2].end(),
		mstree[i*2+1].begin(),mstree[i*2+1].end(),mstree[i].begin());
	}
	
	for(i=1; i<K-2; i++){
		if(temp<A[i-1]) temp=A[i-1];
		if(solve(S+i+1,S+K-1,temp)>=2*A[i]){
			if(N<temp || (N==temp && M<A[i])){
				N=temp;
				M=A[i];
			}
		}
	}

	if(N==-1) printf("-1");
	else printf("%d %d",N,M);

	return 0;
}

int solve(int l,int r,int c){
	int ret=0;
	while(l<r){
		if(l%2==1){
			ret+=upper_bound(mstree[l].begin(),mstree[l].end(),c)-mstree[l].begin();
			l++;
		}
		if(r%2==0){
			ret+=upper_bound(mstree[r].begin(),mstree[r].end(),c)-mstree[r].begin();
			r--;
		}
		if(l>=r) break;
		l>>=1,r>>=1;
	}

	if(l==r)
		ret+=upper_bound(mstree[l].begin(),mstree[l].end(),c)-mstree[l].begin();
	
	return ret;
}