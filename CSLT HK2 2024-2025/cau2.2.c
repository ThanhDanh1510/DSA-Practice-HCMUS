#include <stdio.h>

int main(){
    int a, n;
    scanf("%d %d", &a, &n);
    int Sum = 0;
    int term = 0;
    for(int i = 0; i < n; i++){
        term = term*10 + a;
        Sum+=term;
    }
    printf("Tong la: %d", Sum);
    return 0;
}