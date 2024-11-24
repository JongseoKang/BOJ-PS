#include<stdio.h>
#include<algorithm>

bool check[50];

int main()
{
	int N,i;
    int A[50]={0},B[50]={0};
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
	std::sort(B,B+N);
	for(i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(!check[j] && A[i]==B[j])
			{
				printf("%d ",j);
				check[j]++;
				break;
			}
		}
	}
	return 0;
}