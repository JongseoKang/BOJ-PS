#include<stdio.h>

int cnt=1,N,K,P,print[200001],inv[200001],l;
int chk(int v);
int main(){
	int i,j;
	scanf("%d%d%d",&N,&K,&P);
	i=P,j=-1;
	while(i){
		j++;
		i>>=1;
	}
	l=K;
	if(j>=K || N-chk(P)<K-1){
		printf("-1");
		return 0;
	}
	i=P/2;
	while(i){
		inv[j]=1;
		print[i]=j--;
		i>>=1;
	}
	inv[K]=1;
	print[P]=K;
	for(i=1; i<=N; i++){
		if(print[i]){
			printf("%d\n",print[i]);
		}
		else{
			while(inv[cnt]) cnt++;
			printf("%d\n",cnt++);
		}
	}
	return 0;
}

int chk(int v){
	if(v>N) return 0;
	print[v]=l;
	inv[l++]=1;
	return 1+chk(v*2)+chk(v*2+1);
}