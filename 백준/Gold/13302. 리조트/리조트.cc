 #include<stdio.h>
 
 int table[101][41];
 int N,M;
 int absentday[101];
 
 int main()
 {
 	int i,j,absent,min=2147483647,it;
 	
 	scanf("%d%d",&N,&M);
 	for(i=0;i<M;i++){
 		scanf("%d",&absent);
 		absentday[absent]=1;
	}
	
	for(i=0;i<=N;i++){
		for(j=0;j<=40;j++)
			table[i][j]=999999999;
	}
	
	table[0][0]=0;
	for(i=0;i<N;i++){
		it=(i/5)*2+(i%5)/3;
		for(j=0;j<=it;j++){
			if(table[i+1][j]>table[i][j]+10000){
				table[i+1][j]=table[i][j]+10000;
			}
			if(table[i+3][j+1]>table[i][j]+25000){
				table[i+3][j+1]=table[i][j]+25000;
			}
			if(table[i+5][j+2]>table[i][j]+37000){
				table[i+5][j+2]=table[i][j]+37000;
			}
			if(j>=3 && table[i+1][j-3]>table[i][j]){
				table[i+1][j-3]=table[i][j];
			}
			if(absentday[i+1] && table[i+1][j]>table[i][j]){
				table[i+1][j]=table[i][j];
			}
		}
	}
	
	for(i=0;i<=40;i++){
		if(table[N][i]<min) min=table[N][i];
	}
	
	printf("%d",min);
 	return 0;
 }