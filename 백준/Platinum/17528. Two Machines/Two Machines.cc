#include<stdio.h>

int n,a[250][2],d[62501][250][2];

int main(){
	int i,j,k;

	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d%d",&a[i][0],&a[i][1]);

	for(i=0; i<=62500; i++){
		for(j=0; j<250; j++) d[i][j][0]=d[i][j][1]=9999999;
	}

	d[a[0][0]][0][0]=0;
	d[a[0][1]][0][1]=0;
	for(i=0; i<n-1; i++){
		for(j=0; j<=62500; j++){
			for(k=0; k<2; k++){
				if(62500>=j+a[i+1][k] && d[j+a[i+1][k]][i+1][k]>d[j][i][k]){
					d[j+a[i+1][k]][i+1][k]=d[j][i][k];
				}
				if(d[j][i][k]+a[i+1][(k+1)%2]<=j){
					if(d[j][i+1][k]>d[j][i][k]+a[i+1][(k+1)%2]){
						d[j][i+1][k]=d[j][i][k]+a[i+1][(k+1)%2];
					}
				}
				else{
					if(62500>=d[j][i][k]+a[i+1][(k+1)%2] &&
					d[d[j][i][k]+a[i+1][(k+1)%2]][i+1][(k+1)%2]>j){
						d[d[j][i][k]+a[i+1][(k+1)%2]][i+1][(k+1)%2]=j;
					}
				}
			}
		}
	}
	for(i=1; i<=62500; i++){
		if(d[i][n-1][0]<=i){
			printf("%d",i);
			return 0;
		}
		else if(d[i][n-1][1]<=i){
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}