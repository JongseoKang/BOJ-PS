#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> print;
int A[550000],B[550000],N,M;

int main(){
    int i,j,k;

    scanf("%d%d",&N,&M);
    for(i=0; i<N; i++) scanf("%d",A+i);
    for(i=0; i<M; i++) scanf("%d",B+i);

    sort(A, A+N);
    sort(B, B+M);

    i=j=0;
    while(1){
        if(A[i]>B[j]){
            if(j<M-1) j++;
            else break;
        }
        else if(A[i]<B[j]){
            print.push_back(A[i]);
            i++;
            if(i==N) break;
        }
        else{
            i++;
            if(i==N) break;
            if(j<M-1)
                j++;
            else break;
        }
    }

    for(; i<N; i++) print.push_back(A[i]);
    printf("%d\n",print.size());
    for(i=0; i<print.size(); i++) printf("%d ",print[i]);

    return 0;
}
