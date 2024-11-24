#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

int arr[100000],N;

int main(){
    int i,l,r,a=0,b=1;

    scanf("%d",&N);
    for(i=0; i<N; i++) scanf("%d",arr+i);

    sort(arr,arr+N);

    for(i=0; i<N; i++){
        r=upper_bound(arr,arr+N,-arr[i])-arr;
        l=r-1;
        if(r==i) r++;
        if(l==i) l--;
        if(r<N && abs(arr[i]+arr[r])<abs(arr[a]+arr[b])){ a=i,b=r; }
        if(l>=0 && abs(arr[i]+arr[l])<abs(arr[a]+arr[b])){ a=i,b=l; }
    }

    if(a>b){
        int t=a;
        a=b;
        b=t;
    }
    printf("%d %d",arr[a],arr[b]);
    return 0;
}
