#include<stdio.h>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

struct xy{
	int x,y;
}init;

queue<xy> poss;
stack<int> p;
int N,d[50][50],chk[50][50],A[50];

int main(){
	int i,j,k,Min,rslt=9999;

	scanf("%d",&N);
	for(i=0; i<N; i++) scanf("%d",A+i);

	sort(A,A+N);
	d[1][0]=d[0][1]=A[1]-A[0];
	chk[0][0]=1;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j || i+j==1);
			else if(i>j){
				if(i-1==j){
					Min=0;
					for(k=1; k<j; k++){
						if(max(d[Min][j],A[i]-A[Min])>max(d[k][j],A[i]-A[k])) Min=k;
					}
					d[i][j]=max(d[Min][j],A[i]-A[Min]);
				}
				else{
					d[i][j]=max(d[i-1][j],A[i]-A[i-1]);
				}
			}
			else{
				if(i==j-1){ 
					Min=0;
					for(k=1; k<i; k++){
						if(max(d[i][Min],A[j]-A[Min])>max(d[i][k],A[j]-A[k])) Min=k;
					}
					d[i][j]=max(d[i][Min],A[j]-A[Min]);
				}
				else{
					d[i][j]=max(d[i][j-1],A[j]-A[j-1]);
				}
			}
		}
	}

	for(i=0; i<N-1; i++){
		d[i][N-1]=max(d[i][N-1],A[N-1]-A[i]);
		d[N-1][i]=max(d[N-1][i],A[N-1]-A[i]);
		rslt=min(rslt,min(d[i][N-1],d[N-1][i]));
	}
	for(i=0; i<N-1; i++){
		if(rslt==d[i][N-1]){
			chk[i][N-1]=1;
			poss.push({i,N-1});
		}
		if(rslt==d[N-1][i]){
			chk[N-1][i]=1;
			poss.push({N-1,i});
		}
	}
	
	while(!poss.empty()){
		i=poss.front().x;
		j=poss.front().y;
		if(i>j){
			if(i-1==j){
				for(k=0; k<j; k++){
					if(rslt>=max(d[k][j],A[i]-A[k]) && !chk[k][j]){
						chk[k][j]=1;
						poss.push({k,j});
					}
				}
			}
			else if(!chk[i-1][j]){
				chk[i-1][j]=1;
				poss.push({i-1,j});
			}
		}
		else{
			if(i==j-1){ 
				for(k=0; k<i; k++){
					if(rslt>=max(d[i][k],A[j]-A[k]) && !chk[i][k]){
						chk[i][k]=1;
						poss.push({i,k});
					}
				}
			}
			else if(!chk[i][j-1]){
				chk[i][j-1]=1;
				poss.push({i,j-1});
			}
		}
		poss.pop();
	}
	
	i=j=0;
	while(i<N){
		while(i<N && chk[i][j]){
			printf("%d ",A[i++]);
		}
		j=i++;
		p.push(A[j]);
	}
	p.pop();
	while(!p.empty()){
		printf("%d ",p.top());
		p.pop();
	}

	return 0;
}