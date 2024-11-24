#include<stdio.h>

int p[50][50],d[50][50][2500],c[50][50][2500];
int N,M,K;

int main(){
	int i,j,k;

	scanf("%d%d%d",&N,&M,&K);
	for(i=0; i<N; i++) for(j=0; j<M; j++) scanf("%d",&p[i][j]);

	if(p[0][0]==1){
		d[0][0][(N*M)%K]=1;
		c[0][0][(N*M)%K]=1;
	}
	else if(p[0][0]==0){
		d[0][0][0]=1;
		c[0][0][0]=0;
	}
	else{
		d[0][0][(N*M)%K]=1;
		c[0][0][(N*M)%K]=1;
		d[0][0][0]=1;
		c[0][0][0]=0;
	}

	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			if(i+j==0);
			else if(p[i][j]==1){
				for(k=0; k<K; k++){
					d[i][j][(k+(i+1)*(j+1)*(N-i)*(M-j))%K]=d[i-(j==0)][(j+M-1)%M][k];
					c[i][j][(k+(i+1)*(j+1)*(N-i)*(M-j))%K]=1;
				}
			}
			else if(p[i][j]==0){
				for(k=0; k<K; k++){
					d[i][j][k]=d[i-(j==0)][(j+M-1)%M][k];
					c[i][j][k]=0;
				}
			}
			else{
				for(k=0; k<K; k++){
					if(d[i-(j==0)][(j+M-1)%M][k]==1){
						d[i][j][(k+(i+1)*(j+1)*(N-i)*(M-j))%K]=1;
						c[i][j][(k+(i+1)*(j+1)*(N-i)*(M-j))%K]=1;
					}
					if(d[i-(j==0)][(j+M-1)%M][k]==1){
						d[i][j][k]=1;
						c[i][j][k]=0;
					}
				}
			}
		}
	}
	
	if(d[N-1][M-1][0]==1){
		k=0;
		for(i=N-1; i>=0; i--){
			for(j=M-1; j>=0; j--){
				p[i][j]=c[i][j][k];
				if(c[i][j][k]==1){
					k=(k+K-((i+1)*(j+1)*(N-i)*(M-j))%K)%K;
				}
			}
		}
		
		puts("1");
		for(i=0; i<N; i++){
			for(j=0; j<M; j++) printf("%d ",p[i][j]);
			puts("");
		}
	}
	else printf("-1");
	return 0;
}