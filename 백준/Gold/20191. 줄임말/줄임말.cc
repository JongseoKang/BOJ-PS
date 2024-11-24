#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

char S[1000001], T[100001];
vector<int> alpha[26];
int lenS, lenT;

int main(){
	int i, j, n = 1;

	scanf("%s%s",S, T);
	lenS = strlen(S);
	lenT = strlen(T);

	for(i = 0; i < lenT; i++) alpha[T[i] - 'a'].push_back(i);

	for(i = j = 0; i < lenS; i++){
		int t = S[i] - 'a';
		auto nextj = lower_bound(alpha[t].begin(), alpha[t].end(), j);

		if(nextj == alpha[t].end()){
			if(!j){
				printf("-1");
				return 0;
			}
			else{
				j = 0;
				n++;
				i--;
			}
		}
		else{
			j = *nextj + 1;
			if(j > lenT){
				j = 0;
				n++;
			}
		}
	}

	printf("%d", n);
	return 0;
}