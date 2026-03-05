#include <stdio.h>

int checkSNT(int n){
    if(n < 2) return 0;
    for(int i =2; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(checkSNT(i) == 1) sum+=i;
    }
    printf("Tong la: %d", sum);
}