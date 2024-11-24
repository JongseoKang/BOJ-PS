#include<stdio.h>
#include<algorithm>

using namespace std;

struct XY{
    int X,Y;
    bool operator <(const XY &p)const{
        return X<p.X;
    }
}line[1000000],t;

int N;

int main(){
    int i,j,k,sum=0;

    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d%d",&t.X,&t.Y);
        line[i]=t;
    }

    sort(line,line+N);

    j=line[0].X;
    k=line[0].Y;
    for(i=1; i<N; i++){
        if(k>=line[i].X && k<line[i].Y){
            k=line[i].Y;
        }
        else if(k<line[i].X){
            sum+=k-j;
            j=line[i].X;
            k=line[i].Y;
        }
    }

    sum+=k-j;

    printf("%d",sum);
    return 0;
}
