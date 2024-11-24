#include<stdio.h>

int main(){
    int x,cnt=0;

    scanf("%d",&x);
    while(x){
        cnt+=x%2;
        x>>=1;
    }
    printf("%d",cnt);
    return 0;
}
