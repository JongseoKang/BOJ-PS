#include<stdio.h>

int arr[1000000],temp[1000000];

void Sort(int s,int e);

int main(){
    int n,i;

    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&arr[i]);

    Sort(0,n-1);

    for(i=0; i<n; i++) printf("%d\n",arr[i]);
    return 0;
}

void Sort(int s,int e){
    if(s==e) return;

    Sort(s,(s+e)/2);
    Sort((s+e)/2+1,e);

    int i,l=s,r=(s+e)/2+1;
    for(i=s; i<=e; i++) temp[i]=arr[i];

    while(l<=(s+e)/2 || r<=e){
        i=l+r-(s+e)/2-1;
        if(l==(s+e)/2+1 || (r<=e && temp[l]>temp[r])) arr[i]=temp[r++];
        else arr[i]=temp[l++];
    }
}
