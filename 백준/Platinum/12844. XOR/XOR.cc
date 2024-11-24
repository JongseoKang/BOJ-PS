#include<stdio.h>

struct node{
	int l,r;
	int lazy;
	int val;
}segTree[1100000];

int A[600000],N,S,M;

void initTree();
void lazyPropagation(int u);
int update(int u, int l, int r, int k);
int find(int u, int l, int r);

int main(){
	int i,t,a,b,c;

	scanf("%d",&N);
	for(i=0; i<N; i++) scanf("%d",A+i);

	initTree();
	scanf("%d",&M);
	for(i=0; i<M; i++){
		scanf("%d", &t);
		if(t==1){
			scanf("%d%d%d",&a,&b,&c);
			update(1, a, b, c);
		}else{
			scanf("%d%d",&a,&b);
			printf("%d\n",find(1, a, b));
		}
	}

	return 0;
}

void initTree(){
	int i,j;

	i=1;
	while(i<N) i<<=1;
	S=i;
	
	for(i=1; i<S; i++) segTree[i].l=99999999;
	for(i=0; i<S; i++){
		segTree[S+i]={i,i,0,A[i]};
		for(j=(S+i)/2; j>0; j>>=1){
			if(segTree[j].l>i) segTree[j].l=i;
			segTree[j].r=i;
			segTree[j].val^=segTree[S+i].val;
		}
	}
	
	return;
}

void lazyPropagation(int u){
	if(segTree[u].l==segTree[u].r){
		segTree[u].val^=segTree[u].lazy;
		segTree[u].lazy=0;
	}
	else{
		segTree[u*2].lazy^=segTree[u].lazy;
		segTree[u*2+1].lazy^=segTree[u].lazy;
		segTree[u].lazy=0;
	}
}

int update(int u, int l, int r, int k){
	lazyPropagation(u);

	if(segTree[u].l>=l && segTree[u].r<=r){
		segTree[u].lazy^=k;
		if(segTree[u].l==segTree[u].r) return segTree[u].val^segTree[u].lazy;
		return segTree[u].val;
	}
	else if(segTree[u].l>r || segTree[u].r<l) return segTree[u].val;
	else{
		return segTree[u].val=update(u*2, l, r, k)^update(u*2+1, l, r, k);
	}
}

int find(int u, int l, int r){
	lazyPropagation(u);
	if(segTree[u].l>=l && segTree[u].r<=r){
		return segTree[u].val;
	}
	else if(segTree[u].l>r || segTree[u].r<l) return 0;
	else{
		return find(u*2, l, r)^find(u*2+1, l, r);
	}
}
