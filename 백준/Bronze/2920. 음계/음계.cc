#include<stdio.h>

int main(){
    int arr[8];
    int i;
    for(i = 0; i < 8; i++){
        scanf("%d",&arr[i]);
    }
    for(i = 0; i < 8 && arr[i] == i + 1; i++);
    if(i == 8){
        printf("ascending");
        return 0;
    }
    for(i = 0; i < 8 && arr[i] == 8 - i; i++);
    if(i == 8){
        printf("descending");
        return 0;
    }
    printf("mixed");
    return 0;
}