#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int A[50][50],S[50][50],N;
vector<int> t1,t2;

int main(){
    int i,j,k,l,a,p,q,x;
    long long r,s,c=0;

    scanf("%d",&N);

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d",&A[i][j]);
            S[i][j]=A[i][j];
            if(i>0) S[i][j]+=S[i-1][j];
            if(j>0) S[i][j]+=S[i][j-1];
            if(i>0 && j>0) S[i][j]-=S[i-1][j-1];
        }
    }

    for(i=0; i<N-1; i++){
        for(j=0; j<N-1; j++){
            for(k=0; k<=i; k++){
                for(l=0; l<=j; l++){
                    a=S[i][j];
                    if(k>0) a-=S[k-1][j];
                    if(l>0) a-=S[i][l-1];
                    if(k>0 && l>0) a+=S[k-1][l-1];
                    t1.push_back(a);
                }
            }
            for(k=i+1; k<N; k++){
                for(l=j+1; l<N; l++){
                    a=S[k][l];
                    a-=S[i][l];
                    a-=S[k][j];
                    a+=S[i][j];
                    t2.push_back(a);
                }
            }
            sort(t1.begin(), t1.end());
            sort(t2.begin(), t2.end());
            p=q=0;
            while(p<t1.size() && q<t2.size()){
                if(t1[p]==t2[q]){
                    r=s=0;
                    x=t1[p];
                    while(p<t1.size() && t1[p]==x){ p++; r++; }
                    while(q<t2.size() && t2[q]==x){ q++; s++; }
                    c+=r*s;
                }
                else if(t1[p]>t2[q]) q++;
                else p++;
            }
            t1.clear();
            t2.clear();
        }
    }

    for(i=0; i<N-1; i++){
        for(j=N-1; j>0; j--){
            for(k=0; k<=i; k++){
                for(l=N-1; l>=j; l--){
                    a=S[i][l];
                    a-=S[i][j-1];
                    if(k>0) a-=S[k-1][l];
                    if(k>0) a+=S[k-1][j-1];
                    t1.push_back(a);
                }
            }
            for(k=i+1; k<N; k++){
                for(l=j-1; l>=0; l--){
                    a=S[k][j-1];
                    a-=S[i][j-1];
                    if(l>0) a-=S[k][l-1];
                    if(l>0) a+=S[i][l-1];
                    t2.push_back(a);
                }
            }
            sort(t1.begin(), t1.end());
            sort(t2.begin(), t2.end());
            p=q=0;
            while(p<t1.size() && q<t2.size()){
                if(t1[p]==t2[q]){
                    r=s=0;
                    x=t1[p];
                    while(p<t1.size() && t1[p]==x){ p++; r++; }
                    while(q<t2.size() && t2[q]==x){ q++; s++; }
                    c+=r*s;
                }
                else if(t1[p]>t2[q]) q++;
                else p++;
            }
            t1.clear();
            t2.clear();
        }
    }

    printf("%lld",c);
    return 0;
}
