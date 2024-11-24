#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int N;
int dir[20001];
int orbit[20001];

int main(){
    int i,j,a,r1,r2;

    scanf("%d",&N);
    for(i=1;i<=N; i++){
        scanf("%d",&dir[i]);
    }

    r1=1;
    a=dir[1];
    orbit[1]=1;
    while(a!=1){
        a=dir[a];
	orbit[a]=1;
        r1++;
    }
    for(i=2; i<=N; i++){
        if(orbit[i]) continue;
	orbit[i]=1;
	r2=1;
        a=dir[i];
        while(a!=i){
            a=dir[a];
	    orbit[a]=1;
            r2++;
        }
        a=__gcd(r1,r2);
	r1/=a;
        r1*=r2;
    }

    printf("%d",r1);
    return 0;
}
