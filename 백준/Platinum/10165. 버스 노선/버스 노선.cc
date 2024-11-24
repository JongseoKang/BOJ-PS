#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct bus
{
	int s, e;
	int num;
	bool operator() (bus a, bus b) {
		return a.s < b.s || (a.s == b.s && a.e > b.e);
	}
}line[1000000];

int N, M;
vector<int> print;

int main() {
	int i, j, last, sep = 0;

	scanf("%d%d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d%d", &line[i].s, &line[i].e);
		if (line[i].s > line[i].e) {
			line[M + sep].num = -1;
			line[M + sep].e = N * 2;
			line[M + sep++].s = line[i].s + N;
			line[i].e += N;
		}
		else {
			line[i].s += N;
			line[i].e += N;
		}
		line[i].num = i + 1;
	}

	sort(line, line + (M + sep), bus());

	last = 0;
	print.push_back(line[0].num);
	for (i = 1; i < M + sep; i++) {
		if (line[i].e > line[last].e) {
			print.push_back(line[i].num);
			last = i;
		}
	}

	sort(print.begin(), print.end());

	for (i = 0; i < print.size(); i++) {
		if(print[i]!=-1)
			printf("%d ", print[i]);
	}
}
