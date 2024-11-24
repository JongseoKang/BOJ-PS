#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct piece{
    int H,C;
    bool operator() (const piece& a, const piece& b){
        return (a.H<b.H || (a.H==b.H && a.C>b.C));
    }
}in;

vector<piece> pic;
int N,S;
int t[20000001];

int main(){
    int i,j,h,c,p=0;

    scanf("%d%d",&N,&S);
    for(i=0; i<N; i++){
        scanf("%d%d",&h,&c);
        if(h>=S){
            in.C=c,in.H=h;
            pic.push_back(in);
        }
    }

    sort(pic.begin(),pic.end(),piece());

    for(i=S; i<=20000000; i++){
        if(pic[p].H==i){
            if(t[i-1]<t[i-S]+pic[p].C)
                t[i]=t[i-S]+pic[p].C;
            else t[i]=t[i-1];
            while(pic[++p].H==pic[p-1].H);
        }
        else t[i]=t[i-1];
    }
    
    printf("%d",t[20000000]);
    return 0;
}
