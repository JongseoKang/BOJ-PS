#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int a= (N%5);
    int b={(N-a)/5};
    if(a==4 && b>0) printf("%d",b+2);
    else if(a==3) printf("%d",b+1);
    else if(a==2 && b>1) printf("%d",b+2);
    else if(a==1) printf("%d",b+1);
    else if(!a) printf("%d",b);
    else if(a==4 && b==0) printf("-1");
    else if(a==2 && b==1) printf("-1");
    return 0;
}