#include<stdio.h>
#include<algorithm>
int arr[1000000];
int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0; i<N; i++)
        scanf("%d",&arr[i]);
    std::sort(arr,arr+N);
    for(i=0; i<N; i++)
        printf("%d\n",arr[i]);
    return 0;
}