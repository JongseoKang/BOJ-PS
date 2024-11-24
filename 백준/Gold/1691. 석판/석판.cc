#include <bits/stdc++.h>
using namespace std;
int d[601][601],r,c;
int main(){
	int i,j,k,x,y;
	scanf("%d %d",&c,&r);
	for(i=1;i<=r;i++)for(j=1;j<=c;j++)d[i][j]=i*j;
	scanf("%d",&j);
	for(i=1;i<=j;i++)scanf("%d %d",&x,&y),d[y][x]=0;
	for(i=1;i<=r;i++)for(j=1;j<=c;j++){
		for(k=1;k<=i-k;k++)d[i][j]=min(d[i][j],d[k][j]+d[i-k][j]);
		for(k=1;k<=j-k;k++)d[i][j]=min(d[i][j],d[i][k]+d[i][j-k]);
	}
	printf("%d",d[r][c]);
	return 0;
}