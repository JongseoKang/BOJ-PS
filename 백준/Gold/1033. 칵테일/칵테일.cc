#include<stdio.h>

struct cocktail{
    long long p,q;
};

long long rate[10],g[10][10],N;
int check[10],lev=2;

long long gcd(long long a,long long b);
void Forward(int v);
void Backward(int v);

int main(){
    long long a,b,p,q,i,G;

    scanf("%lld",&N);
    for(i=0; i<N-1; i++){
        scanf("%lld%lld%lld%lld",&a,&b,&p,&q);
        g[a][b]=p, g[b][a]=q;
    }

    check[0]=rate[0]=1;
    Forward(0);

    G=rate[0];
    for(i=1; i<N; i++) G=gcd(G,rate[i]);
    for(i=0; i<N; i++) printf("%lld ",rate[i]/G);
    return 0;
}

long long gcd(long long a,long long b){
    long long temp;
    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }
    return (b ? gcd(b,a%b):a);
}

void Forward(int v){
    int i;
    for(i=0; i<N; i++){
        if(g[v][i] && !check[i]){
            check[i]=lev;
            rate[v]*=g[v][i];
            rate[i]=rate[v]/g[v][i]*g[i][v];
            Backward(i);
            lev++;
            Forward(i);
        }
    }
}

void Backward(int v){
    int i;
    for(i=0; i<N; i++){
        if(g[v][i] && check[i]==lev-1){
            check[i]=lev;
            if((double)rate[v]/rate[i]!=(double)g[v][i]/g[i][v]){
                rate[i]=rate[v]/g[v][i]*g[i][v];
            }
            Backward(i);
        }
    }
}
