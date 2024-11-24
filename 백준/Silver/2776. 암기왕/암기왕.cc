#include<stdio.h>
#include<set>

using namespace std;

set<int> m1;

int main(){
    int T,i,n,a;

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0; i<n; i++){
            scanf("%d",&a);
            m1.insert(a);
        }
        scanf("%d",&n);
        for(i=0; i<n; i++){
            scanf("%d",&a);
            if(m1.find(a)!=m1.end()) printf("1\n");
            else printf("0\n");
        }

        m1.clear();
    }

    return 0;
}
