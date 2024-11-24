#include<stdio.h>

int card[2][10],r[3];

int winner(int round){
    if(card[0][round]==card[1][round]) return 2;
    return card[0][round]<card[1][round];
}

int main(){
    int i;

    for(i=0; i<10; i++) scanf("%d",&card[0][i]);

    for(i=0; i<10; i++){
        scanf("%d",&card[1][i]);
        r[winner(i)]++;
    }

    if(r[0]>r[1]) puts("A");
    else if(r[0]<r[1]) puts("B");
    else puts("D");

    return 0;
}
