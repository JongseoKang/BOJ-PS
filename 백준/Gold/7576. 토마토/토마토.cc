#include<stdio.h>
#include<queue>

using namespace std;

struct tomato{
	int x, y, day;
};

queue<tomato> q;
int box[1000][1000];
int N,M,tomatoes, rotten;
int dir[4][2] = {{1, 0}, {0, 1}, {-1,0}, {0, -1}};


int main(){
	int i,j;
	int d = 0;

	scanf("%d%d", &N, &M);
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d", &box[i][j]);
			if(box[i][j]!=-1) tomatoes++;
			if(box[i][j]==1){
				q.push({i, j, 0});
				rotten++;
			}
		}
	}

	while(!q.empty()){
		int x = q.front().x, y = q.front().y;
		d = q.front().day;
		
		for(i=0; i<4; i++){
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if(xx >= 0 && xx < M && yy >= 0 && yy < N && !box[xx][yy]){
				q.push({xx, yy, d + 1});
				box[xx][yy] = 1;
				rotten++;
			}
		}

		q.pop();
	}

	if(rotten == tomatoes) printf("%d", d);
	else printf("-1");
	return 0;
}
