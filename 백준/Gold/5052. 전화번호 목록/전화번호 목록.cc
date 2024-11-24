#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

struct node
{
	int f;
	int num[10];
}push;

vector<node> trie;

int t, n;
char input[20];

int main()
{
	int i, j, k, len, index, out;

	scanf("%d", &t);
	while (t--)
	{
		push.f = 0;
		for (i = 0; i < 10; i++) push.num[i] = -1;
		trie.push_back(push);

		out = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%s", input);
			len = strlen(input);
			for (j = 0; j < len; j++)
				input[j] -= '0';
			index = 0;
			for (j = 0; j < len; j++)
			{
				if (trie[index].num[input[j]] == -1)
				{
					trie[index].num[input[j]] = trie.size();
					index = trie.size();
					push.f = 0;
					if (j == len - 1) push.f = 1;
					for (k = 0; k < 10; k++) push.num[k] = -1;
					trie.push_back(push);
				}

				else
				{
					if (j == len - 1)
						trie[index].f = 1;
					index = trie[index].num[input[j]];

					if (j == len - 1) out = 1;
					if (trie[index].f) out = 1;
				}
			}
		}

		if (!out) printf("YES\n");
		else printf("NO\n");
		trie.clear();
	}

	return 0;
}