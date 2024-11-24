#include<stdio.h>
#include<algorithm>

using namespace std;

int teamA[51], teamB[51];
int d[51][51];

int main(){
	int N,i,j,cnt=0;

	scanf("%d",&N);
	for(i=1; i<=N; i++) scanf("%d",teamA+i);
	for(i=1; i<=N; i++) scanf("%d",teamB+i);

	sort(teamA+1, teamA+N+1);
	sort(teamB+1, teamB+N+1);
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			d[i][j]=(d[i][j-1]>d[i-1][j] ? d[i][j-1]:d[i-1][j]);
			if(teamA[i]==teamB[j] && d[i][j]<d[i-1][j-1]+1){
				d[i][j]=d[i-1][j-1]+1;
			}
			if(teamA[i]>teamB[j] && d[i][j]<d[i-1][j-1]+2){
				d[i][j]=d[i-1][j-1]+2;
			}
		//printf("d[%d][%d]: %d\n",i,j,d[i][j]);
		}
	}

	printf("%d",d[N][N]);
	return 0;
}
