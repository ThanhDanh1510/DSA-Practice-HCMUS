#include <stdio.h>

long long power(int n, int a){
    long long result = 1;
    for(int i =0; i < a; i++){
        result*=n;
    }
    return result;
}

int main(){
    long long product = 1;
    int n;
    scanf("%d", &n);

    for(int i =0; i < n; i++){
        long long result = power(i+1, n-i);
        product*=result;
    }

    printf("Ket qua: %lld", product);
}