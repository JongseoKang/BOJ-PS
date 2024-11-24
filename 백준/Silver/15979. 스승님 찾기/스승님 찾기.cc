#include<stdio.h>
#include<algorithm>

using namespace std;


int main(){
    int N,M;
    scanf("%d%d",&N,&M);

    if(N<0) N=-N;
    if(M<0) M=-M;

    if(N==0 && M==0) printf("0");
    else if((N==0 && M==1) || (N==1 && M==0)) printf("1");
    else if(__gcd(N,M)==1) printf("1");
    else printf("2");
    return 0;


}
