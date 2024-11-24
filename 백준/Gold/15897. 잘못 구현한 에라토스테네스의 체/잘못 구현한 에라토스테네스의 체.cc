#include<stdio.h>

long long n,rslt;
long long f(long long x){
	return (n-1)/x;
}

int main(){
	long long i,l,r,mid;
	scanf("%lld",&n);
	i=1;
	while(i<n){
		l=i+1;
		r=n;
		while(l<r){
			mid=(l+r)/2;
			if(f(mid)==f(i)){
				l=mid+1;
			}
			else r=mid;
		}
		rslt+=((l-i)*f(i));
		i=l;
	}

	rslt+=n;
	printf("%lld",rslt);
	return 0;
}