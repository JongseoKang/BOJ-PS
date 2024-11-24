#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>

using namespace std;

struct se{
    int s,e;
    int len;
}pu;

vector<se> init;
map<int, vector<se>> d;
set<int> lst;
queue<se> q;
int N,A[2000];

int main(){
	int i,j,cnt,Max=1;
	scanf("%d",&N);
	for(i=0; i<N; i++) scanf("%d",A+i);
    sort(A, A+N);
    for(i=0; i<N; i++){
        lst.insert(A[i]);
        cnt=1;
        while(i+cnt<N && A[i]==A[i+cnt]) cnt++;
        if(cnt>Max) Max=cnt;
        i+=cnt-1;
    }

    N=0;
    for(set<int>::iterator it=lst.begin(); it!=lst.end(); it++)
        A[N++]=*it;

    for(i=0; i<N-1; i++){
        for(j=i+1; j<N; j++){
            if(d.find(A[j]-A[i])==d.end()){
                d[A[j]-A[i]]=init;
            }
            pu.s=i, pu.e=j, pu.len=2;
            d[A[j]-A[i]].push_back(pu);
        }
    }
    
    for(auto it=d.begin(); it!=d.end(); it++){
        q.push(it->second[0]);
        for(auto vit=it->second.begin()+1; vit!=it->second.end(); vit++){
            while(!q.empty() && q.front().e<=vit->s){
                if(q.front().e==vit->s){
                    pu=*vit;
                    pu.len=q.front().len+1;
                    q.push(pu);
                }
                else{
                    if(q.front().len>Max) Max=q.front().len;
                }
                q.pop();
            }
            if(q.empty() || q.front().e>vit->s){
                q.push(*vit);
            }
            else{
                pu=*vit;
                pu.len=q.front().len+1;
                q.push(pu);
            }
        }
        while(!q.empty()){
            if(q.front().len>Max) Max=q.front().len;
            q.pop();
        }
    }

    printf("%d",Max);
    return 0;
}