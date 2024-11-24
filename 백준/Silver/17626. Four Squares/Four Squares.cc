#include<stdio.h>
#include<math.h>
#define sqnum 223

int sq[sqnum];
bool check(int n,int r)
{
    int i;
    if(r==0 && n==0) return true;
    else if(r==0) return false;
    for(i=0; i<sqnum; i++){
        if(check(n-sq[i],r-1))
            return true;
    }
    return false;
}

int main(){
    int i,n;

    for(i=1; i<=223; i++) sq[i-1]=i*i;
    scanf("%d",&n);

    for(i=1; i<=3; i++){
        if(check(n,i)){
            printf("%d",i);
            return 0;
        }
    }
    printf("4");
    return 0;
}
