#include<stdio.h>

struct node{
    node *left;
    node *right;
    int id;
}Nd[1001],ini;
int N,pre[1000],in[1000];
void recur(int pl,int pr,int il,int ir);
void postorder(node *n);

int main(){
    int T,i,j;

    scanf("%d",&T);
    Nd[1000].id=-1;
    while(T--){
        scanf("%d",&N);
        for(i=0; i<N; i++) scanf("%d",&pre[i]);
        for(i=0; i<N; i++) scanf("%d",&in[i]);

        recur(0,N-1,0,N-1);
        postorder(&Nd[0]);
        puts("");
    }


    return 0;
}

void recur(int pl,int pr,int il,int ir){
    if(pl==pr && il==ir){
        Nd[pl].id=pre[pl];
        Nd[pl].left=&Nd[1000];
        Nd[pl].right=&Nd[1000];
        return;
    }
    int i;
    Nd[pl].id=pre[pl];

    for(i=il; i<=ir; i++) if(pre[pl]==in[i]) break;
    if(pl+1>pl+(i-il)) Nd[pl].left=&Nd[1000];
    else {
        recur(pl+1,pl+(i-il),il,i-1);
        Nd[pl].left=&Nd[pl+1];
    }

    if(pl+(i-il)+1>pr) Nd[pl].right=&Nd[1000];
    else {
        recur(pl+(i-il)+1,pr,i+1,ir);
        Nd[pl].right=&Nd[pl+(i-il)+1];
    }
    return;
}

void postorder(node *n){
    if(n->id==-1) return;

    postorder(n->left);
    postorder(n->right);
    printf("%d ",n->id);
    return;
}
