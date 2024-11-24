
#include<stdio.h>

long long n,W,s[17],r[15],l;

int main(){
    long long i,j,c,t;

    scanf("%lld%lld",&n,&W);
    for(i=1; i<=n; i++){
        scanf("%lld",&s[i]);
        if(s[i]==s[i-1]){
            n--;
            i--;
        }
    }
    s[0]=10001, s[n+1]=0;
    for(i=1; i<=n; i++){
        if((s[i]>s[i+1] && s[i]>s[i-1]) ||
            (s[i]<s[i+1] && s[i]<s[i-1]))
            r[l++]=s[i];
    }

    for(i=0; i<l; i+=2){
        t=W/r[i];
        c=W%r[i];
        W=c+t*r[i+1];
    }
    printf("%lld",W);
    return 0;
}
