#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

int D[1001][1001],P[1001][1001][2],l1,l2;
char S1[1001],S2[1001];
stack<char> print;

int main(){
    int i,j,x,y;

    scanf("%s%s",S1,S2);
    l1=strlen(S1);
    l2=strlen(S2);


    for(i=1; i<=l1; i++){
        for(j=1; j<=l2; j++){

            if(S1[i-1]==S2[j-1]){
                D[i][j]=D[i-1][j-1]+1;
                P[i][j][0]=i-1;
                P[i][j][1]=j-1;
            }
            else{
                if(D[i-1][j]<D[i][j-1]){
                    D[i][j]=D[i][j-1];
                    P[i][j][0]=i;
                    P[i][j][1]=j-1;
                }
                else{
                    D[i][j]=D[i-1][j];
                    P[i][j][0]=i-1;
                    P[i][j][1]=j;
                }
            }
        }
    }



    printf("%d\n",D[l1][l2]);
    while(l1>0 && l2>0){
        if(S1[l1-1]==S2[l2-1]) print.push(S1[l1-1]);
        x=P[l1][l2][0];
        y=P[l1][l2][1];
        l1=x;
        l2=y;
    }

    while(!print.empty()){
        printf("%c",print.top());
        print.pop();
    }
    return 0;
}
