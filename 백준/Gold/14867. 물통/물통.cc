#include<stdio.h>
#include<vector>
#define t(a) (bool)a

using namespace std;

struct AB{
    int a,b;
    int trial;
}in;

vector<AB> q;
int A,B;
int D[3][3]={{0,1,2},{3,4,5},{6,7,8}};
int check[9][200001];
int tag(int a,int b);
void Mab(int a,int b,int d);


int main(){
    int i,tg,h=0,rT,rA,rB;

    scanf("%d%d%d%d",&A,&B,&rA,&rB);
    rT=tag(rA,rB);

    if(!rA && !rB){
        printf("0");
        return 0;
    }

    in.a=in.b=in.trial=0;
    q.push_back(in);
    check[0][0]=1;

    while(!check[rT][rA+rB] && h<q.size()){
        tg=tag(q[h].a,0);
        if(!check[tg][q[h].a]){
            in.a=q[h].a,in.b=0,in.trial=q[h].trial+1;
            q.push_back(in);
            check[tg][q[h].a]=in.trial;
        }
        tg=tag(0,q[h].b);
        if(!check[tg][q[h].b]){
            in.a=0,in.b=q[h].b,in.trial=q[h].trial+1;
            q.push_back(in);
            check[tg][q[h].b]=in.trial;
        }
        tg=tag(A,q[h].b);
        if(!check[tg][A+q[h].b]){
            in.a=A,in.b=q[h].b,in.trial=q[h].trial+1;
            q.push_back(in);
            check[tg][A+q[h].b]=in.trial;
        }
        tg=tag(q[h].a,B);
        if(!check[tg][q[h].a+B]){
            in.a=q[h].a,in.b=B,in.trial=q[h].trial+1;
            q.push_back(in);
            check[tg][q[h].a+B]=in.trial;
        }
        Mab(q[h].a,q[h].b,1);
        tg=tag(in.a,in.b);
        if(!check[tg][in.a+in.b]){
            in.trial=q[h].trial+1;
            q.push_back(in);
            check[tg][in.a+in.b]=in.trial;
        }
        Mab(q[h].a,q[h].b,0);
        tg=tag(in.a,in.b);
        if(!check[tg][in.a+in.b]){
            in.trial=q[h].trial+1;
            q.push_back(in);
            check[tg][in.a+in.b]=in.trial;
        }
        h++;
    }

    if(!check[rT][rA+rB]) printf("-1");
    else printf("%d",check[rT][rA+rB]);
    return 0;
}

int tag(int a,int b){
    return D[t(a)*(1+a/A)][t(b)*(1+b/B)];
}

void Mab(int a,int b,int d){
    int t;
    if(!d){
        t=A; A=B; B=t;
        t=a; a=b; b=t;
    }

    in.b=(a+b)>B ? B:(a+b);
    in.a=(a+b)>B ? (a+b-B):0;

    if(!d){
        t=A; A=B; B=t;
        t=in.a; in.a=in.b; in.b=t;
    }
}
