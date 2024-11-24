#include<stdio.h>
#include<queue>

using namespace std;

struct casher{
	long long time;
	long long id;
	bool operator<(const casher p)const{
		return time > p.time || (time == p.time && id > p.id);
	}
};

struct out{
	long long time;
	long long cashid;
	long long id;
	bool operator<(const out p)const{
		return time > p.time || (time == p.time && cashid < p.cashid);
	}
};

priority_queue<out> print;
priority_queue<casher> heap;
long long N, K;
long long ans;

int main(){
	long long i, j;
	long long id;
	long long w;


	scanf("%lld%lld", &N, &K);
	for(i = 0; i < K; i++){
		heap.push({0, i});
	}
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &id, &w);

		casher t = heap.top();
		heap.pop();

		t.time += w;

		print.push({t.time, t.id, id});
		heap.push(t);
	}

	i = 0;
	while(!print.empty()){
		ans += print.top().id * ++i;
		print.pop();
	}

	printf("%lld", ans);
	return 0;
}
