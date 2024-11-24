#include<stdio.h>

long long t[1000][1000],f[200][200],rslt;
int n,p;

int main(){
	int i,j,k,l;

	f[0][0]=f[0][1]=1;
	for(i=2; i<200; i++){
		if(f[0][i-2]+f[0][i-1]<=1e18) f[0][i]=f[0][i-1]+f[0][i-2];
		else f[0][i]=1e18+1;
	}

	for(i=1; i<200; i++){
		if(i==1) f[1][0]=0;
		else if(f[0][i-2]<=1e18){
			if(i%2==1) f[i][0]=-f[0][i-2];
			else f[i][0]=f[0][i-2];
		}
		else f[i][0]=1e18+1;

		for(j=1; j<200; j++){
			f[i][j]=f[i-1][j-1];
		}
	}

	scanf("%d%d",&n,&p);

	for(i=0; i<p; i++){
		for(j=0; j<p; j++){
			scanf("%lld",&t[i][j]);
		}
	}

	if(p>200){
		printf("0");
		return 0;
	}

	for(i=1; i<200 && i<n; i++){
		int chk=0;
		for(j=0; j<p; j++){
			for(k=0; k<p; k++){
				if(f[j+i][k]!=t[j][k]){
					chk=1;
					break;
				}
			}
		}

		if(chk==0){
			rslt+=n-p-i+1;
		}
	}

	for(i=0; i<200 && i<n; i++){
		int chk=0;
		for(j=0; j<p; j++){
			for(k=0; k<p; k++){
				if(f[j][k+i]!=t[j][k]){
					chk=1;
					break;
				}
			}
		}

		if(chk==0){
			rslt+=n-p-i+1;
		}
	}
	printf("%lld",rslt);
	return 0;
}