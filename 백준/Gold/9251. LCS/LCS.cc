#include<stdio.h>
#include<string.h>

int table[1002][1002];
char str1[1001],str2[1001];

int main(){
    int i,j;
    int len1,len2;

    scanf("%s %s",str1,str2);
    len1=strlen(str1);
    len2=strlen(str2);

    if(str1[0]==str2[0]) table[0][0]=1;
    for(i=1; i<len1; i++){
        table[i][0]=(table[i-1][0] || str1[i]==str2[0]) ? 1:0;
    }
    for(i=1; i<len2; i++){
        table[0][i]=(table[0][i-1] || str1[0]==str2[i]) ? 1:0;
    }

    for(i=1; i<len1; i++){
        for(j=1; j<len2; j++){
            if(table[i][j-1]>table[i-1][j]){
                table[i][j]=table[i][j-1];
            }
            else {
                table[i][j]=table[i-1][j];
            }

            if(str1[i]==str2[j] && table[i][j]<table[i-1][j-1]+1){
                table[i][j]=table[i-1][j-1]+1;
            }
        }
    }

    printf("%d",table[len1-1][len2-1]);
    return 0;
}
