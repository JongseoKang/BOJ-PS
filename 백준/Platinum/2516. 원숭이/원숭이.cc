#include<stdio.h>
#include<vector>

using namespace std;

struct mk{
    int u[3];
    int l;
}in;

mk g[100001];
int team[100001];
vector<int> print[2];

int main(){
    int N,i,j,c;

    scanf("%d",&N);
    for(i=1; i<=N; i++){
        scanf("%d",&g[i].l);
        for(j=0; j<g[i].l; j++){
            scanf("%d",&g[i].u[j]);
        }
    }

    team[1]=0;
    for(i=2; i<=N; i++){
        team[i]=1;
    }
    int k=0,lk;
    while(k<3*(N+1)/2){
        lk=k;
        for(i=1; i<=N; i++){
            c=0;
            for(j=0; j<g[i].l; j++){
                if(team[i]==team[g[i].u[j]]) c++;
            }
            if(c>1){
                team[i]=(team[i]+1)%2;
                k++;
            }
        }
        if(lk==k) break;
    }

    for(i=1; i<=N; i++) print[team[i]].push_back(i);
    printf("%d ",print[0].size());
    for(i=0; i<print[0].size(); i++) printf("%d ",print[0][i]);
    printf("\n%d ",print[1].size());
    for(i=0; i<print[1].size(); i++) printf("%d ",print[1][i]);
    return 0;
}
