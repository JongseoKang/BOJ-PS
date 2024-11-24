#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> a;
vector<vector<int>> v;
int n, m, total,t;
int dis[10001];
int scc[10001];
stack<int> st;
int dfs(int here) {
	dis[here] = ++t;
	int ret = dis[here];
	st.push(here);
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!dis[next]) ret = min(ret, dfs(next)); // discover타임 갱신(tree edge 관련)
		if (!scc[next]) ret = min(ret, dis[next]); // discover타임 갱신(tree edge를 제외한 edge들과 관련)
	}

	if (ret == dis[here]) { // 만약 같다면
		vector<int> temp;
		while (1) { //쭉뽑아줌
			int a = st.top();
			st.pop();
			scc[a] = 1;
			temp.push_back(a);
			if (a == here) break;
		}
		sort(temp.begin(), temp.end()); // 내부에서도 정렬이 되어있어야 해서 미리 정렬시켜줌
		v.push_back(temp);
		total++; //SCC갯수 증가
	}
	return dis[here]=ret;
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
	}
	for (int i = 1; i <= n; i++) {
		if (!dis[i]) dfs(i); 
	}
	printf("%d\n", total);
	sort(v.begin(), v.end()); // 정렬을 시키면 맨 앞의 원소를 기준으로 정렬이 됨
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("%d ", v[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}