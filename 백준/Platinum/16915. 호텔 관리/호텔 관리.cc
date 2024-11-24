#include<stdio.h>
#include<vector>
#define Re 100000
using namespace std;

vector<int> st,temp,line[200010];
typedef struct ROOM{
    int open;
    vector<int> line_num;
};
ROOM room[200010];
int when[200010],check_stack[200010],cot=1,check_scc[100005],possible=1;

int DFS(int fx)
{
    int x,re=when[fx]=cot++,z;
    st.push_back(fx);
    for(auto x:line[fx]){
        if(when[x]==0){
            z=DFS(x);
            if(z<re) re=z;
        }
        else if(check_stack[x]==0 && when[x]<re){
            re=when[x];
        }
    }
    temp.clear();
    if(re==when[fx]){
        while(st.back()!=fx){
            temp.push_back(st.back());
            check_stack[st.back()]=1;
            st.pop_back();
        }
        temp.push_back(st.back());
        check_stack[st.back()]=1;
        st.pop_back();
        for(auto x:temp){
            if(check_scc[x%Re]==1) possible=0;
            else check_scc[x%Re]=1;
        }
        for(auto x:temp){
            check_scc[x%Re]=0;
        }
    }
    return re;
}

int main()
{
    int n,m,k,x,y,i;
    scanf("%d %d" ,&n,&m);
    for(x=1;x<=n;x++){
        scanf("%d",&room[x].open);
    }
    for(x=1;x<=m;x++){
        scanf("%d",&k);
        for(y=1;y<=k;y++){
            scanf("%d",&i);
            room[i].line_num.push_back(x);
        }
    }
    for(x=1;x<=n;x++){
        if(room[x].open==1){ ///원래 열려있을 때  ( !a || b) && ( a || !b )
            line[room[x].line_num.front()].push_back(room[x].line_num.back());
            line[Re+room[x].line_num.back()].push_back(Re+room[x].line_num.front());
            line[Re+room[x].line_num.front()].push_back(Re+room[x].line_num.back());
            line[room[x].line_num.back()].push_back(room[x].line_num.front());
        }
        else{                          ///원래 닫혀있을 때 ( a || b ) && ( !a || !b )
            line[Re+room[x].line_num.front()].push_back(room[x].line_num.back());
            line[Re+room[x].line_num.back()].push_back(room[x].line_num.front());
            line[room[x].line_num.front()].push_back(Re+room[x].line_num.back());
            line[room[x].line_num.back()].push_back(Re+room[x].line_num.front());
        }
    }
    for(x=1;x<=m;x++){
        if(when[x]==0){
            DFS(x);
        }
        if(when[x+Re]==0){
            DFS(x+Re);
        }
    }
    if(possible==1) printf("1");
    else printf("0");
    return 0;
}