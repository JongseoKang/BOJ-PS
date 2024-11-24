#include<stdio.h>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

map<long long,long long> pos;
set<long long> s;
struct query{
	long long a,b,c;
}in[100000];

long long N,M,S,MM;
long long tree[1<<19],init[200000],snow[200000];
long long solve(long long l,long long r);
long long solve2(long long v,long long t);

int main(){
	long long i,j,*x,*y;

	scanf("%lld%lld",&N,&M);

	for(i=0; i<N; i++){
		scanf("%lld",snow+i);
		init[i]=snow[i];
		s.insert(snow[i]);
	}

	for(i=0; i<M; i++){
		scanf("%lld%lld",&in[i].a,&in[i].b);
		if(in[i].a==1){
			in[i].b--;
			scanf("%lld",&in[i].c);
			snow[N+i]=snow[in[i].b];
			snow[in[i].b]+=in[i].c;
			s.insert(snow[in[i].b]);
		}
		else if(in[i].a==2){
			in[i].b--;
			scanf("%lld",&in[i].c);
			snow[N+i]=snow[in[i].b];
			snow[in[i].b]-=in[i].c;
			s.insert(snow[in[i].b]);
		}
		else if(in[i].a==3)	scanf("%lld",&in[i].c);
	}
	
	MM=s.size(); i=0;
	for(auto it=s.begin(); it!=s.end(); it++) snow[i++]=*it;
	S=MM-1;
	i=0;
	while(S){ S>>=1; i++; }
	S=1<<i;
	for(i=0; i<MM; i++) pos[snow[i]]=i;
	for(i=0; i<N; i++) tree[S+pos[init[i]]]++;
	for(i=S-1; i>0; i--) tree[i]=tree[i*2]+tree[i*2+1];
	for(i=0; i<M; i++){
		if(in[i].a==1){
			j=pos[init[in[i].b]]+S;
			while(j){ tree[j]--; j>>=1; }
			init[in[i].b]+=in[i].c;
			j=pos[init[in[i].b]]+S;
			while(j){ tree[j]++; j>>=1; }
		}
		else if(in[i].a==2){
			j=pos[init[in[i].b]]+S;
			while(j){ tree[j]--; j>>=1; }
			init[in[i].b]-=in[i].c;
			j=pos[init[in[i].b]]+S;
			while(j){ tree[j]++; j>>=1; }
		}
		else if(in[i].a==3){
			x=upper_bound(snow,snow+MM,in[i].c);
			y=lower_bound(snow,snow+MM,in[i].b);
			if(x==snow || y==snow+MM)
				printf("0\n");
			else{
				in[i].c=*(x-1);
				in[i].b=*y;
				printf("%lld\n",solve(pos[in[i].b]+S,pos[in[i].c]+S));
			}
		}
		else printf("%lld\n",solve2(1,in[i].b));
	}
	return 0;
}

long long solve(long long l,long long r){
	long long ret=0;
	while(l<r){
		if(l%2==1) ret+=tree[l++];
		if(r%2==0) ret+=tree[r--];
		if(l>=r) break;
		l>>=1, r>>=1;
	}

	if(l==r) ret+=tree[l];
	return ret;
}

long long solve2(long long v,long long t){
	if(v>=S) return snow[v-S];
	if(tree[v*2+1]<t) return solve2(v*2,t-tree[v*2+1]);
	return solve2(v*2+1,t);
}