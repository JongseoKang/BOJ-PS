#include<stdio.h>
#include<algorithm>
#include<string.h>

bool compare(char *str,char *str2);

struct word
{
	char str[51];
	bool operator () (word a,word b)
	{
		return strlen(a.str)<strlen(b.str) 
			|| (strlen(a.str)==strlen(b.str) && compare(a.str,b.str));
	}
}data[20000];
int N;

int main()
{
	int i;
	scanf("%d",&N);
	for(i=0; i<N; i++)
		scanf("%s",data[i].str);
	std::sort(data,data+N,word());
	for(i=0; i<N; i++)
	{
		if(strcmp(data[i].str,data[i-1].str))
			printf("%s\n",data[i].str);
	}
	return 0;
}

bool compare(char *str,char *str2)
{
	int i;
	for(i=0; i<strlen(str); i++)
	{
		if(str[i]==str2[i]);
		else if(str[i]<str2[i])
			return true;
		else return false;
	}
	return false;
}