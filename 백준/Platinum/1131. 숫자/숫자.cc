#include<stdio.h>
#include<stack>
#include<math.h>

using namespace std;

stack<long long> stk,stk2;
long long num[4000001],A,B;
double K;
long long decimal[8]={1,10,100,1000,10000,100000,1000000,10000000};
bool check[3000001];

long long sk(long long n){
    long long i;
    double ret=0,digit;
    for(i=0; i<7; i++){
        digit=n%decimal[i+1]/decimal[i];
        ret+=pow(digit,K);
    }
    return (long long)ret;
}

int main(){
    long long i,j,Min,sum=0;

    scanf("%lld%lld%lf",&A,&B,&K);
    for(i=A; i<=B; i++){
        j=i;
        while(!check[j]){
            stk.push(j);
            check[j]=true;
            j=sk(j);
        }
        if(!num[j]){
            Min=99999999;
            while(stk.top()!=j){
                if(Min>stk.top()) Min=stk.top();
                stk2.push(stk.top());
                stk.pop();
            }
            if(Min>stk.top()) Min=stk.top();
            stk2.push(stk.top());
            stk.pop();

            while(!stk2.empty()){
                num[stk2.top()]=Min;
                stk2.pop();
            }
            while(!stk.empty()){
                if(Min>stk.top()) Min=stk.top();
                num[stk.top()]=Min;
                stk.pop();
            }
        }
        else{
            Min=num[j];
            while(!stk.empty()){
                if(Min>stk.top()) Min=stk.top();
                num[stk.top()]=Min;
                stk.pop();
            }
        }
        sum+=Min;
    }

    printf("%lld",sum);
    return 0;
}
