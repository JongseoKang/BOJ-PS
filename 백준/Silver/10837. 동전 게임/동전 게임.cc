#include<stdio.h>

int main()
{
	int k,c,m,n;
	
	scanf("%d%d",&k,&c);
	while(c--){
		scanf("%d%d",&m,&n);
		if(m>n && k-(m-1)<(m-1)-n) printf("0\n");
		else if(m<n && k-n<(n-1)-m) printf("0\n");
		else printf("1\n");
	}
	
	return 0;
}