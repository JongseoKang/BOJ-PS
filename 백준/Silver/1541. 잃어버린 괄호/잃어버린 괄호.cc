#include<stdio.h>
#include<string.h>

int conv(char *str, int s,int e){
    int i=1,r=0;

    for(;e>=s; e--){
        r+=((str[e]-'0')*i);
        i*=10;
    }
    return r;
}

int main(){
    char str[51]="\0";
    char num[5];
    int n,m=1,r=0,i,j,len;

    scanf("%s",str);
    len=strlen(str);
    for(i=0; i<len; i++){
        j=i;
        while(str[i]>='0' && str[i]<='9'){
            i++;
        }
        n=conv(str,j,i-1);
        if(m) r+=n;
        else r-=n;
        if(str[i]=='-') m=0;
    }
    printf("%d",r);
    return 0;
}
