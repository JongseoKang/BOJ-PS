#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int T, N;
long long K, ans, timer;

struct Coffee{
	long long c, t, s;
	bool operator <(const Coffee &p)const{
		return s<p.s;
	}
}coffee[101], top;
priority_queue<Coffee> heap;

bool cmp(const Coffee &a, const Coffee &b){
	return a.t > b.t;
}

int main(){
	int i, j; 

	scanf("%d", &T);
	for(i=1; i<=T; i++){
		scanf("%d%lld", &N, &K);
		for(j=0; j<N; j++){
			scanf("%lld%lld%lld", &coffee[j].c, &coffee[j].t, &coffee[j].s);
		}
		
		coffee[N]={1, 0, 0};
		sort(coffee, coffee+N, cmp);
		j=0;
		timer=coffee[0].t;
		while(j<N){
			while(coffee[j].t==timer){
				heap.push(coffee[j++]);
			}
			
			while(coffee[j].t < timer && !heap.empty()){
				top=heap.top();
				heap.pop();
				if(timer-coffee[j].t>=top.c){
					ans+=top.c * top.s;
					timer-=top.c;
				}
				else{
					ans+=(timer-coffee[j].t) * top.s;
					top.c-=(timer-coffee[j].t);
					timer=coffee[j].t;
					heap.push(top);
				}
			}
			timer=coffee[j].t;
		}

		printf("Case #%d: %lld\n", i, ans);
		while(!heap.empty()) heap.pop();
		ans=0;
	}

	return 0;
}