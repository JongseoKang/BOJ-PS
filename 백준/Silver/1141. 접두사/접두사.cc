#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

struct node
{
	int f;
	int next[26];
}push;

vector<node> trie;

int N, sum;
char input[60];

int main()
{
	int i, j, k;
	int index, len;

	push.f = 0;
	for (i = 0; i < 26; i++)
		push.next[i] = -1;
	trie.push_back(push);

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", input);
		len = strlen(input);
		for (j = 0; j < len; j++)
			input[j] -= 'a';

		index = 0;
		for (j = 0; j < len; j++)
		{
			if (trie[index].next[input[j]] == -1)
			{
				if (trie[index].f)
					trie[index].f = 0;
				trie[index].next[input[j]] = trie.size();
				index = trie.size();
				push.f = 0;
				if (j == len - 1)
					push.f = 1;
				for (k = 0; k < 26; k++)
					push.next[k] = -1;
				trie.push_back(push);
			}

			else
				index = trie[index].next[input[j]];
		}
	}

	for (i = 0; i < trie.size(); i++)
		sum += trie[i].f;

	printf("%d", sum);
	return 0;
}