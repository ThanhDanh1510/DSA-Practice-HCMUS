#include <stdio.h>

int sum(int n, int a){
    if(n==1) return a;
    return a+sum(n-1, a)*10;
}

int tinhTong(int n, int a){
    if(n==1) return a;
    return tinhTong(n-1, a) + sum(n, a);
}

int main(){
    int result = tinhTong(3, 1);
    printf("%d", result);
    return 0;
}