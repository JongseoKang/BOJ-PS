#include<stdio.h>
#define MAX 0
#define MIN 1

int T,N,K,S;
int tree[2][270000];

void update(int p,int v,int tog){
    int t=-2*tog+1,u=-2*(p%2)+1;
    p+=S/2;
    tree[tog][p]=v;
    while(p){
        if(t*tree[tog][p]>t*tree[tog][p+u]) tree[tog][p/2]=tree[tog][p];
        else  tree[tog][p/2]=tree[tog][p+u];
        p>>=1;
        u=-2*(p%2)+1;
    }
}

int find(int l,int r,int tog){
    int t=-2*tog+1,ret=-1;
    l+=S/2;
    r+=S/2;
    while(l<r){
        if(l%2==1){
            if(ret==-1 || (ret!=-1 && t*ret<t*tree[tog][l])) ret=tree[tog][l];
            l++;
        }
        if(r%2==0){
            if(ret==-1 || (ret!=-1 && t*ret<t*tree[tog][r])) ret=tree[tog][r];
            r--;
        }
        l>>=1;
        r>>=1;
    }

    if(l==r && (ret==-1 || (ret!=-1 && ret*t<tree[tog][l]*t))) ret=tree[tog][l];
    return ret;
}


int main(){
    int i,q,a,b,aa,bb,Max,Min;
    scanf("%d",&T);

    while(T--){
        scanf("%d%d",&N,&K);

        S=1;
        while(S<N) S<<=1;
        S<<=1;

        for(i=0; i<N; i++) tree[0][S/2+i]=tree[1][S/2+i]=i;
        for(; i<S/2; i++){
            tree[MAX][S/2+i]=-1;
            tree[MIN][S/2+i]=100000;
        }
        for(i=S/2-1; i>=1; i--){
            tree[MAX][i]=(tree[MAX][i*2]>tree[MAX][i*2+1]) ? tree[MAX][i*2]:tree[MAX][i*2+1];
            tree[MIN][i]=(tree[MIN][i*2]<tree[MIN][i*2+1]) ? tree[MIN][i*2]:tree[MIN][i*2+1];
        }

        for(i=0; i<K; i++){
            scanf("%d%d%d",&q,&a,&b);
            if(!q){
                aa=tree[MAX][S/2+a];
                bb=tree[MAX][S/2+b];
                update(a,bb,MAX);
                update(b,aa,MAX);
                aa=tree[MIN][S/2+a];
                bb=tree[MIN][S/2+b];
                update(a,bb,MIN);
                update(b,aa,MIN);
            }
            else{
                Max=find(a,b,MAX);
                Min=find(a,b,MIN);
                if(Max==b && Min==a) printf("YES\n");
                else printf("NO\n");
            }
        }

    }

    return 0;
}
