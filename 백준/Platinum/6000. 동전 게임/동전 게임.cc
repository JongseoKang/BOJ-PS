#include<bits/stdc++.h>
using namespace std;

int n, sum[2001], dp[2001][2001];

int dpv( int r, int k ){
    
    if( !k || n<r ) return 0;
    if( dp[r][k] ) return dp[r][k];
    
    dp[r][k] = max( dpv(r,k-1), sum[n]-sum[r-1]-dpv(r+k,k*2) );
    
    return dp[r][k];
}
int main(){
    scanf("%d",&n);
    for( int i=1; i<=n; i++ ){
        scanf("%d",&sum[i]);
        sum[i] += sum[i-1];
    }
    printf("%d",dpv(1,2));
    return 0;
}