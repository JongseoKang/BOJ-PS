#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct stu{
	int d,m,org;
	bool operator<(const stu &p)const{
		return d<p.d;
	}
}s[100000];

vector<int> A[100000];
int list[31];
int N,K,D,E;
void calc(int i,int j);

int main(){
	int i,j,k;

	scanf("%d%d%d",&N,&K,&D);

	for(i=0; i<N; i++){
		scanf("%d%d",&s[i].m,&s[i].d);
		s[i].org=i;
		for(j=0; j<s[i].m; j++){
			scanf("%d",&k);
			A[i].push_back(k);
		}
	}
	
	s[N].d=2*1e9+20;
	sort(s,s+N);
	
	i=0,j=1;
	for(auto it=A[s[0].org].begin(); it!=A[s[0].org].end(); it++) list[*it]++;
	while(i<N){
		while(j<N && s[j].d-s[i].d<=D){
			for(auto it=A[s[j].org].begin(); it!=A[s[j].org].end(); it++) list[*it]++;
			j++;
		}
		calc(i,j);
		while(i<N && s[j].d-s[i].d>D){
			for(auto it=A[s[i].org].begin(); it!=A[s[i].org].end(); it++) list[*it]--;
			i++;
		}
	}

	printf("%d",E);
	return 0;
}

void calc(int i,int j){
	int allknow=0,all=0;

	for(int k=1; k<=K; k++){
		allknow+=list[k]==(j-i);
		all+=bool(list[k]);
	}

	E=E>(all-allknow)*(j-i) ? E:(all-allknow)*(j-i);
}