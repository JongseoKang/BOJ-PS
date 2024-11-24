#include<stdio.h>
#include<set>

using namespace std;

struct vertex{
    int parent,color;
}g[100000];

int P[1000],Plen,Pcheck[100000];

int Find(int v,int u);
int Count(int v,int u);
void Paint(int v,int u,int c);

int main()
{
    int N,K;
    int r,a,b,c;

    scanf("%d%d",&N,&K);
    while(K--){
        scanf("%d",&r);
        if(r==1){
            scanf("%d%d%d",&a,&b,&c);
            Paint(a,b,c);
        }
        else if(r==2){
            scanf("%d%d",&a,&b);
            g[a].parent=b;
        }
        else{
            scanf("%d%d",&a,&b);
            c=Count(a,b);
            printf("%d\n",c);
        }
    }
    return 0;
}

int Find(int v,int u){
    int a=v;
    int i=0;

    P[Plen++]=a;
    Pcheck[a]=1;
    while(i<1000 && a && a!=u){
        a=g[a].parent;
        P[Plen++]=a;
        Pcheck[a]=1;
        i++;
    }
    a=u;
    while(!Pcheck[a]){
        a=g[a].parent;
    }
    for(i=0; i<Plen; i++){
        Pcheck[P[i]]=0;
    }
    Plen=0;
    return a;
}

int Count(int v,int u){
    set<int> S2;
    int E=Find(v,u);
    int cnt;

    while(v!=E){
        S2.insert(g[v].color);
        v=g[v].parent;
    }
    while(u!=E){
        S2.insert(g[u].color);
        u=g[u].parent;
    }
    cnt=S2.size();
    return cnt;
}

void Paint(int v,int u,int c){
    int E=Find(v,u);

    while(v!=E){
        g[v].color=c;
        v=g[v].parent;
    }
    while(u!=E){
        g[u].color=c;
        u=g[u].parent;
    }
}
