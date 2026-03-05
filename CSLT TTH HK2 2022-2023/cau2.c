#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    int result = 1;
    for(int i = 1; i<=n;i++){
        result*=i;
        sum+=result;
    }
    printf("Tong la: %d", sum);
}