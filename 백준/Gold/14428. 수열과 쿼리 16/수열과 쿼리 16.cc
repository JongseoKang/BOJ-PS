#include<stdio.h>

int A[100001],tree[1<<18];
int N,M,S;

void update(int v);
int solve(int l,int r);

int main(){
	int i,j,k;
	A[100000]=1e9+1;
	for(i=0; i<(1<<18); i++) tree[i]=100000;

	scanf("%d",&N);
	S=N-1;
	i=0;
	while(S){ S>>=1; i++; }
	S=1<<i;
	for(i=0; i<N; i++){
		scanf("%d",A+i);
		tree[S+i]=i;
	}

	for(i=S-1; i>0; i--) tree[i]=A[tree[i*2]]>A[tree[i*2+1]] ? tree[i*2+1]:tree[i*2];

	scanf("%d",&M);
	while(M--){
		scanf("%d%d%d",&i,&j,&k);
		if(i==1){
			A[j-1]=k;
			update((S+j-1)/2);
		}
		else printf("%d\n",solve(S+j-1,S+k-1)+1);
	}

	return 0;
}

void update(int v){
	if(!v) return;
	tree[v]=A[tree[v*2]]>A[tree[v*2+1]] ? tree[v*2+1]:tree[v*2];
	update(v/2);
}

int solve(int l,int r){
	int ret=100000;

	while(l<r){
		if(l%2==1){
			if(A[ret]>A[tree[l]] || (A[ret]==A[tree[l]] && ret>tree[l])) ret=tree[l];
			l++;
		}
		if(r%2==0){
			if(A[ret]>A[tree[r]] || (A[ret]==A[tree[r]] && ret>tree[r])) ret=tree[r];
			r--;
		}
		if(l>=r) break;
		l>>=1, r>>=1;
	}

	if(l==r && (A[ret]>A[tree[l]] || (A[ret]==A[tree[l]] && ret>tree[l]))) ret=tree[l];
	return ret;
}