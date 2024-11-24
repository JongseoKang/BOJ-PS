#include<stdio.h>

int N,K,gender,grade;
int student[2][6];
int checkin;

int main(){
	int i,j;
	
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%d%d",&gender,&grade);
		student[gender][grade-1]++;
	}
	
	j=(student[0][0]+student[0][1]+student[1][0]+student[1][1]);
	checkin+=(j/K+(j%K==0 ? 0:1));
	j=(student[0][2]+student[0][3]);
	checkin+=(j/K+(j%K==0 ? 0:1));
	j=(student[1][2]+student[1][3]);
	checkin+=(j/K+(j%K==0 ? 0:1));
	j=(student[0][4]+student[0][5]);
	checkin+=(j/K+(j%K==0 ? 0:1));
	j=(student[1][4]+student[1][5]);
	checkin+=(j/K+(j%K==0 ? 0:1));
	
	printf("%d",checkin);
	return 0;
}