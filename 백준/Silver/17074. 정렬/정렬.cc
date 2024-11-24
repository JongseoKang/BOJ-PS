#include<stdio.h>

int arr[100000],N,cnt;

int main(){
	int i,j;

	scanf("%d",&N);
	for(i=0; i<N; i++) scanf("%d",arr+i);
	for(i=0; i<N-1; i++){
		if(arr[i]>arr[i+1]){
			cnt++;
			j=i;
		}
	}

	if(cnt==1){
		int ans=0;
		if(j==0 || arr[j-1]<=arr[j+1]) ans++;
		if(j==N-2 || arr[j]<=arr[j+2]) ans++;
		printf("%d",ans);
	}
	else if(cnt==0){
		printf("%d",N);
	}
	else{
		printf("0");
	}
	return 0;
}