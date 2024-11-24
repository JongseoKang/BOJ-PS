#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

char str[500005];
int s[500005],g[500005],r[500001],LCP[500001],temp[500005];
int len,t=1;

bool c1(const int &a, const int &b){
    return str[a]<str[b];
}

bool c2(const int &a, const int &b){
    if(g[a]<g[b]) return 1;
    if(g[a]>g[b]) return 0;
    return g[a+t]<g[b+t];
}

int main(){
    int i,j,k,l;

    scanf("%s",str);
    len=strlen(str);
    for(i=0; i<len; i++) s[i]=i;
    sort(s,s+len,c1);
    g[s[0]]=0;
    for(i=1; i<len; i++){
        if(str[s[i-1]]==str[s[i]]) g[s[i]]=g[s[i-1]];
        else g[s[i]]=g[s[i-1]]+1;
    }

    while(t<len){
        g[len]=-1;
        sort(s,s+len,c2);
        temp[s[0]]=0;
        for(i=1; i<len; i++){
            if(g[s[i-1]]<g[s[i]]) temp[s[i]]=temp[s[i-1]]+1;
            else if(g[s[i-1]+t]<g[s[i]+t]) temp[s[i]]=temp[s[i-1]]+1;
            else temp[s[i]]=temp[s[i-1]];
        }
        for(i=0; i<len; i++) g[i]=temp[i];
        t*=2;
    }

    for(i=0; i<len; i++) printf("%d ",s[i]+1);
    puts("");
    for(i=0; i<len; i++)
        r[s[i]] = i;
    l=0;
    for (i=0; i<len; i++) {
        k=r[i];
        if(k) {
            int j=s[k-1];
            while(str[j+l] == str[i+l])
                l++;
            LCP[k]=l;
            if (l)
                l--;
        }
    }
    printf("x ");
    for(i=1; i<len; i++)printf("%d ",LCP[i]);
    return 0;
}
