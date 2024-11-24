#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> Bgraph[101];
vector<int> Sgraph[101];

int N,M;

int main()
{
    int i,j,k;

    scanf("%d%d",&N,&M);

    for(i=0; i<M; i++)
    {
        int big,small;

        scanf("%d%d",&big,&small);

        Bgraph[small].push_back(big);
        Sgraph[big].push_back(small);
    }

    for(i=1; i<=N; i++)
    {
        int cnt=1;
        int check[101]={0};
        queue<int> Squeue;
        queue<int> Bqueue;

        check[i]=1;
        Squeue.push(i);
        while(!Squeue.empty())
        {
            for(j=0; j<Sgraph[Squeue.front()].size(); j++)
            {
                if(!check[Sgraph[Squeue.front()][j]])
                {
                    check[Sgraph[Squeue.front()][j]]=1;
                    Squeue.push(Sgraph[Squeue.front()][j]);
                    cnt++;
                }
            }

            Squeue.pop();
        }

        Bqueue.push(i);
        while(!Bqueue.empty())
        {
            for(j=0; j<Bgraph[Bqueue.front()].size(); j++)
            {
                if(!check[Bgraph[Bqueue.front()][j]])
                {
                    check[Bgraph[Bqueue.front()][j]]=1;
                    Bqueue.push(Bgraph[Bqueue.front()][j]);
                    cnt++;
                }
            }

            Bqueue.pop();
        }

        printf("%d\n",N-cnt);
    }

    return 0;
}
