#include<stdio.h>
#define abs(a) ((a)>0 ? (a):-(a))

int n,a[1000],b[1000],r[1001];

int main(){
    int i,j,ret=0;

    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",a+i);
    for(i=0; i<n; i++) scanf("%d",b+i);
    for(i=0; i<n; i++) r[i]=b[i]-a[i];

    for(i=1; i<=n; i++){
        if(r[i-1]*r[i]<=0){
            ret+=abs(r[i-1]);
        }
        else if(abs(r[i-1])>abs(r[i])){
            ret+=abs(r[i-1]-r[i]);
        }
    }

    printf("%d",ret);
    return 0;
}
