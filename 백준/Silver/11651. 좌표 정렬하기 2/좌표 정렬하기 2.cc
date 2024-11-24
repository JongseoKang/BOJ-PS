#include<stdio.h>
#include<queue>

using namespace std;

struct XY{
    int X,Y;

     bool operator <(const XY &A)const {
        return Y>A.Y || (Y==A.Y && X>A.X);
     }
}ini;

priority_queue<XY> heap;

int main(){
    int n;

    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&ini.X,&ini.Y);
        heap.push(ini);
    }

    while(!heap.empty()){
        printf("%d %d\n",heap.top().X,heap.top().Y);
        heap.pop();
    }

    return 0;
}
