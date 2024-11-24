#include<stdio.h>
#include<stack>

using namespace std;

stack<int> stk;

int N;
int in;
int arr[500000];

int main(){
    int i,j;
    scanf("%d",&N);

    for(i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    stk.push(0);
    printf("0 ");
    for(i=1; i<N; i++){
        while(!stk.empty() && arr[stk.top()]<arr[i]){
            stk.pop();
        }
        if(stk.empty()){
            printf("0 ");
        }
        else{
            printf("%d ",stk.top()+1);
        }
        stk.push(i);
    }
    return 0;
}
