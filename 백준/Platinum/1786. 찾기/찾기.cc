#include<stdio.h>
#include<vector>
#define LEN 1000000

using namespace std;

vector<int>print;
char Find[LEN+1];
char lyric[LEN+1];
int phy[LEN];
int fle,fl;

int main(){
    int i,j,k;

    gets(lyric);
    for(fle=LEN-1; lyric[fle]=='\0'; fle--);
    fle++;
    gets(Find);
    for(fl=LEN-1; Find[fl]=='\0'; fl--);
    fl++;

    phy[0]=-1;
    k=0;
    for(i=1; i<fl; i++){
        if(k){
            if(Find[k]==Find[i]){
                phy[i]=k++;
            }
            else{
                k=phy[k-1]+1;
                i--;
            }
        }
        else{
            if(Find[0]==Find[i]) phy[i]=k++;
            else phy[i]=-1;
        }
    }

    i=k=0;
    for(j=0; j<fle; j++){
        if(k){
            if(Find[k]==lyric[j]){
                k++;
            }
            else{
                k=phy[k-1]+1;
                j--;
            }
        }
        else{
            if(Find[0]==lyric[j]) k++;
        }
        if(k==fl){
            i++;
            print.push_back(j-fl+2);
            k=phy[k-1]+1;
        }
    }

    printf("%d\n",print.size());
    for(i=0; i<print.size(); i++){
        printf("%d ",print[i]);
    }
    return 0;
}
