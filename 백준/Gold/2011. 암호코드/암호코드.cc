#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[5010],num[3];
int d[5001],p;

int main(){
    int N,i;

    scanf("%s",str);
    N=strlen(str);

    if(str[0]=='0' || (str[0]>'2' && str[1]=='0')){ printf("0"); return 0; }
    d[0]=d[1]=1;
    num[0]=str[0],num[1]=str[1];
    p=atoi(num);
    if(p%10==0) d[1]=1;
    else if(p<=26) d[1]=2;
    for(i=2; i<N; i++){

        num[0]=str[i-1],num[1]=str[i];
        p=atoi(num);
        if(p==0 || (p%10==0 && p>20)){printf("0"); return 0;}
        else if(p%10==0) d[i]=d[i-2];
        else if(p>26) d[i]=d[i-1];
        else if(p<10) d[i]=d[i-1];
        else d[i]=d[i-1]+d[i-2];
        d[i]=d[i]%1000000;
        if(d[i]<0) d[i]+=1000000;
    }
    printf("%d",d[N-1]);
    return 0;
}
