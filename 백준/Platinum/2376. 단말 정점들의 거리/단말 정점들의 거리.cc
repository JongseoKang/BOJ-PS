#include<stdio.h>

int n,dist[1001];

int main(){
    int i,u,v,r=0,temp;

    scanf("%d",&n);
    for(i=1; i<n; i++) scanf("%d",dist+i);
    scanf("%d%d",&u,&v);

    if(u>v){
        temp=v;
        v=u;
        u=temp;
    }
    while(u!=v){
        for(i=1; i<n; i++){
            if(dist[i]==2) break;
        }
        if(i==u || i==u-1){
            r++;
            u=i;
        }
        if(i==v || i==v-1){
            r++;
            v=i;
        }
        if(i+1<u) u--;
        if(i+1<v) v--;
        dist[i-1]--, dist[i+1]--, n--;
        for(; i<n; i++) dist[i]=dist[i+1];
    }

    printf("%d",r);
    return 0;
}
