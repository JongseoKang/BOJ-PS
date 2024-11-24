#include <stdio.h>
int arr[5],n=0, rst=0;
bool check();
int divide(int a);

int main()
{
    int N,m,i;
    scanf("%d",&N);
    for(m=1;m<=N;m++){
        
    i=m;
    n=0;
    while(i>0){
        arr[n] = i%10;
        i /= 10;
        n++;
    }
        if(check()){
            rst++;
        }
    }
    printf("%d", rst);


    return 0;
}

bool check(){
    int k=0,j=0,tem=arr[0]-arr[1];
    for(j=0;j<n-1;j++){
        if(tem == arr[j]-arr[j+1]){
            k+=1;
        }else{
            break;
        }
    }
    if(k==n-1){
        return true;
    }else{
        return false;
    }
}

int divide(int a){
    int i=a;
    n=0;
    while(i>0){
        arr[n] = i%10;
        i /= 10;
        n++;
    }
}