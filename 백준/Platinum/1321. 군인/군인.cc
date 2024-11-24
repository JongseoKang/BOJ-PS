#include<stdio.h>

int segtree[1<<20+1],N,M,size=1;
void initree(int v);
void updatetree(int v,int a);
int solvetree(int v,int i,int p);

int main(){
	int q,i,a;

	scanf("%d",&N);
	while(size<N) size<<=1;
	for(i=0; i<N; i++) scanf("%d",segtree+i+size);
	initree(1);
	scanf("%d",&M);
	while(M--){
		scanf("%d",&q);
		if(q==1){
			scanf("%d%d",&i,&a);
			updatetree(size+i-1,a);
		}
		else{
			scanf("%d",&i);
			printf("%d\n",solvetree(1,i,0));
		}
	}
	return 0;
}

void initree(int v){
	if(v>=size) return;
	initree(v*2);
	initree(v*2+1);
	segtree[v]=segtree[v*2]+segtree[v*2+1];
}

void updatetree(int v,int a){
	if(!v) return;
	segtree[v]+=a;
	updatetree(v/2,a);
}

int solvetree(int v,int i,int p){
	if(v>=size) return v-size+1;
	if(p+segtree[v*2]<i) return solvetree(v*2+1,i,p+segtree[v*2]);
	return solvetree(v*2,i,p);
}