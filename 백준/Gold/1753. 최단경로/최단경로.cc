#include <stdio.h>
#include <vector>
#include<queue>

using namespace std;

int v, e, a, b, c, s, sum, m[20001];

struct st{
    int jj;
    int le;
    bool operator<(const st &p)const{
        return le > p.le;
    }
};

int d[20001];

int Min[20001];

vector<st> vv[20001];
priority_queue<st> G;

int main() {
    scanf("%d %d", &v, &e);

    scanf("%d", &s);

    for(int i = 0 ; i < e ; i++) {
        scanf("%d %d %d", &a, &b, &c);
        vv[a].push_back({b, c});
    }
    for(int i = 0 ; i <= v ; i++) {
        d[i] = -1;
    }


    d[s] = 0;

    for(int i = 2 ; i <= v ; i++) {
        m[s] = 1;
        for(int j = 0 ; j < vv[s].size() ; j++) {
            if(d[vv[s][j].jj] == -1 || d[s] + vv[s][j].le < d[vv[s][j].jj]) {
                d[vv[s][j].jj] = d[s] + vv[s][j].le;
                G.push({vv[s][j].jj, d[vv[s][j].jj]});
            }
        }

        while(!G.empty() && m[G.top().jj]){
            G.pop();
        }
        if(G.empty()) break;
        sum += G.top().le;
        s = G.top().jj;
        G.pop();
    }

    for(int i = 1 ; i <= v ; i++) {
        if(d[i]==-1) printf("INF\n");
        else printf("%d\n", d[i]);
    }
    return 0;
}