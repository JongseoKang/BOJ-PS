#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct data{
	int num;
	int mem;
	bool operator<(const data &x)const {
		return mem>x.mem;
	}
}party[300];

vector<int> print;
int N,M,Max,arr[300],d[100001],path[100001];

int main(){
	int i,j,k;

	scanf("%d",&N);
	for(i=0; i<N; i++){
		scanf("%d",&party[i].mem);
		party[i].num=i+1;
		M+=party[i].mem;
	}

	sort(party,party+i);
	d[0]=1;
	d[party[0].mem]=1;
	path[party[0].mem]=0;
	Max=party[0].mem;
	print.push_back(party[0].num);
	for(i=1; i<N; i++){
		for(j=M/2; j>=0; j--){
			if(d[j] && !d[j+party[i].mem]){
				path[j+party[i].mem]=i;
				d[j+party[i].mem]=1;
				if(j+party[i].mem>Max){
					Max=k=j+party[i].mem;
					print.clear();
					while(k>0){
						print.push_back(party[path[k]].num);
						k-=party[path[k]].mem;
					}
				}
			}
		}
	}
	
	sort(print.begin(),print.end());

	printf("%ld\n",print.size());
	for(auto it=print.begin(); it!=print.end(); it++)
		printf("%d ",*it);
	return 0;
}