#include<stdio.h>

int facto(int a);
int d[10001],n;

int main(){
    int i,j;
    
    scanf("%d",&n);
    for(i=1; i<=n; i++) d[i]=i;
    for(i=1; i<n; i++){
        j=n+1;
        if(i<8) j=facto(i);
        if(j<=n && d[j]>d[i]) d[j]=d[i];
        for(j=1; j<=i; j++){
            if(i+j<=n && d[i+j]>d[i]+d[j]) d[i+j]=d[i]+d[j];
            if(i*j<=n && d[i*j]>d[i]+d[j]) d[i*j]=d[i]+d[j];
        }
        if(d[i+1]>d[i]+1) d[i+1]=d[i]+1;
    }

    printf("%d",d[n]);
    return 0;
}


int facto(int a){
    int ret=1,i;
    for(i=1; i<=a; i++) ret*=i;
    return ret;
}