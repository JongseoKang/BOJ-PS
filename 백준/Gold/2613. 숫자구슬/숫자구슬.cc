
#include<vector>
// #include<vector>
#include<stdio.h>

using namespace std;
int N,M;
vector<int> nummarble;
vector<int> groupnum;
vector<int> groupnum1;
bool group(int maxnum);
int bs(int l,int r);
int main(){
    int temp;
    int numsum = 0;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        numsum+=temp;
        nummarble.push_back(temp);
    }
    int ans = bs(1,300000);
    printf("%d\n",ans);
    // 1이상인 값 자르기
    int a=M-groupnum.size();
    for(int i=0;i<groupnum.size();i++){
        // printf("%d/",i);
        if(a>0&&groupnum[i]>1){
            if(a<(groupnum[i]-1)){
                for(int j=0;j<a;j++){
                    printf("1 ");
                }
                printf("%d ",groupnum[i]-a);
                a=0;
            }else{
                for(int j=0;j<(groupnum[i]);j++){
                    printf("1 ");
                    a--;
                }
                a++;
            }
        }else{
            printf("%d ",groupnum[i]);
        }
    }
    
    

    return 0;
}
bool group(int maxnum){
    groupnum.clear();
    int groupcnt=M;
    int groupsum=0,memcnt=0;
    int i;
    for(i=0; i<nummarble.size() ; i++){
        groupsum += nummarble[i];
        if(groupsum>maxnum){
            groupsum=nummarble[i];
            if(maxnum<nummarble[i]) return false;
            groupnum.push_back(memcnt);
            memcnt=0;
            groupcnt--;
        }
        memcnt++;

        if(groupcnt<=0){
            return false;
        }
    } 
    groupnum.push_back(memcnt);
    return true;
}
int bs(int l,int r){
    int mid;
    mid = (l+r)/2;
    if(l==r){
        group(mid);
        return mid;
    }
    if(!group(mid)){
        return bs(mid+1,r);
    }else{
        return bs(l,mid);
    }
}