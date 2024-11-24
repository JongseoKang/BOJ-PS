#include<stdio.h>
#include<vector>

using namespace std;

long long dig(long long x){
    long long c=0;
    while(x){
        c+=x%10;
        x/=10;
    }
    if(c>9) return dig(c);
    return c;
}

vector<long long> pattern;
long long T,M,K,chk[10];
long long dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main(){
    long long i,j,g,x,y,p,q;

    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&K,&M);
        x=y=p=q=0;
        g=1;
        while(!chk[g]){
            chk[g]=1;
            pattern.push_back(g);
            g=dig(g*M);
        }
        for(j=0; pattern[0]!=g && K>0; j++, K--){
            p+=dir[j%4][0]*pattern[0];
            q+=dir[j%4][1]*pattern[0];
            pattern.erase(pattern.begin());
        }
        if(pattern.size()>=K){
            for(i=0; i<K; i++){
                x+=dir[(i+j)%4][0]*pattern[i];
                y+=dir[(i+j)%4][1]*pattern[i];
            }
        }
        else{
            for(i=0; i<pattern.size()*4; i++){
                x+=dir[(i+j)%4][0]*pattern[i%pattern.size()];
                y+=dir[(i+j)%4][1]*pattern[i%pattern.size()];
            }
            x=x*4*(K/(pattern.size()*4));
            y=y*4*(K/(pattern.size()*4));
            for(i=0; i<K%(pattern.size()*4); i++){
                x+=dir[(i+j)%4][0]*pattern[i%pattern.size()];
                y+=dir[(i+j)%4][1]*pattern[i%pattern.size()];
            }
        }
        printf("%lld %lld\n",x+p,y+q);
        for(i=0; i<10; i++) chk[i]=0;
        pattern.clear();
    }

    return 0;
}
