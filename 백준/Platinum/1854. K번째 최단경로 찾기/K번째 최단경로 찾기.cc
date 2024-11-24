#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

struct state
{
   int v, c;
   bool operator <(const state &x)const
   {
      return c > x.c;
   }
};

struct data
{
   int state;
   int cost;
};

priority_queue<state> que;
vector<data> graph[1001];

int N, M, K;
int cnt[1001];
int print[1001];

int main()
{
   int i, j;

   scanf("%d%d%d", &N, &M, &K);

   for (i = 1; i <= N; i++)
      print[i] = -1;

   for (i = 0; i < M; i++)            //INPUT
   {
      data ini;
      int a, b, c;
      
      scanf("%d%d%d", &a, &b, &c);

      ini.state = b;
      ini.cost = c;
      graph[a].push_back(ini);
   }

   state ini = { 1, 0 };
   que.push(ini);

   while (!que.empty())
   {
      state min = que.top();

      que.pop();
      cnt[min.v]++;
      if (cnt[min.v] == K)
         print[min.v] = min.c;
      if(cnt[min.v]>K)
         continue;
      
      for (i = 0; i < graph[min.v].size(); i++)
      {
         if (print[graph[min.v][i].state] == -1)
         {
            ini.c = min.c + graph[min.v][i].cost;
            ini.v = graph[min.v][i].state;
            que.push(ini);
         }
      }
   }

   for (i = 1; i <= N; i++)
      printf("%d\n", print[i]);

   return 0;
} 