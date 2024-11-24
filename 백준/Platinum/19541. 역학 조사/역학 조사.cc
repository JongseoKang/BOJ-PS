#include<stdio.h>
#include<vector>

using namespace std;

vector<int> meeting[100000];
int N,M,rst[100001],init[100001],temp[100001];

int main(){
	int i,j,s,v,c;

	scanf("%d%d",&N,&M);
	for(i=0; i<M; i++){
		scanf("%d",&s);
		while(s--){
			scanf("%d",&v);
			meeting[i].push_back(v);
		}
	}

	for(i=1; i<=N; i++) { scanf("%d",rst+i); init[i]=rst[i]; }
	for(i=M-1; i>=0; i--){ 
		c=0;
		for(auto j=meeting[i].begin(); j!=meeting[i].end(); j++){
			if(!rst[*j]){
				c++;
				break;
			}
		}
		if(c){
			for(auto j=meeting[i].begin(); j!=meeting[i].end(); j++)
				rst[*j]=0;
		}
	}

	for(i=1; i<=N; i++) temp[i]=rst[i];

	for(i=0; i<M; i++){
		c=0;
		for(auto j=meeting[i].begin(); j!=meeting[i].end(); j++){
			if(temp[*j]){
				c++;
				break;
			}
		}
		if(c){
			for(auto j=meeting[i].begin(); j!=meeting[i].end(); j++)
				temp[*j]=1;
		}
	}

	for(i=1; i<=N; i++){
		if(temp[i]!=init[i]){
			printf("NO");
			return 0;
		}
	}

	printf("YES\n");
	for(i=1; i<=N; i++) printf("%d ",rst[i]);
	return 0;
}