#include<stdio.h>
#include<string.h>

char str[12][51];
struct result{
	char s[601];
	int m;
	bool operator<(const result &p)const{
		return strcmp(s,p.s)<0;
	}
}ans[1<<12][12],temp;

int N,Max;
int g[12][12],len[12],d[1<<12][12];

int main(){
	int i,j,k,l;

	scanf("%d",&N);
	for(i=0; i<N; i++){
		scanf("%s",str[i]);
		len[i]=strlen(str[i]);
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j || len[i]<len[j]) continue;
			for(k=0; k<len[i]-len[j]; k++){
				for(l=0; l<len[j]; l++){
					if(str[i][k+l]!=str[j][l]) break;
				}
				if(l==len[j]){ str[j][0]='0'; break; }
			}
		}
	}
	
	for(i=0; i<N; i++){
		if(str[i][0]=='0'){
			for(j=i+1; j<N; j++){
				strcpy(str[j-1],str[j]);
				len[j-1]=len[j];
			}
			N--, i--;
		}
	}

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j) continue;
			for(k=1; k<=len[i] && k<=len[j]; k++){
				for(l=0; l<k; l++){
					if(str[i][len[i]-k+l]!=str[j][l]) break;
				}
				if(l==k) g[i][j]=k;
			}
		}
	}
	
	for(i=0; i<(1<<N); i++){
		for(j=0; j<N; j++) d[i][j]=-1;
	}
	for(i=0; i<N; i++){
		d[1<<i][i]=0;
		ans[1<<i][i].m=len[i];
		strcpy(ans[1<<i][i].s,str[i]);
	}

	for(i=1; i<(1<<N); i++){
		for(j=0; j<N; j++){
			if((i&(1<<j))==(1<<j)){
				for(k=0; k<N; k++){
					if(j!=k && (i&(1<<k))==(1<<k)){
						temp=ans[i-(1<<j)][k];
						for(l=g[k][j]; l<len[j]; l++)
							temp.s[temp.m+l-g[k][j]]=str[j][l];
						if(d[i][j]<d[i-(1<<j)][k]+g[k][j] ||
							(d[i][j]==d[i-(1<<j)][k]+g[k][j] && temp<ans[i][j])){
							d[i][j]=d[i-(1<<j)][k]+g[k][j];
							ans[i][j]=temp;
							ans[i][j].m+=len[j]-g[k][j];
						}
					}
				}
			}
		}
	}
	
	for(i=1; i<N; i++)
		if(d[(1<<N)-1][i]>d[(1<<N)-1][Max] ||
		(d[(1<<N)-1][i]==d[(1<<N)-1][Max] && ans[(1<<N)-1][i]<ans[(1<<N)-1][Max]))
		Max=i;
	printf("%s",ans[(1<<N)-1][Max].s);
	return 0;
}