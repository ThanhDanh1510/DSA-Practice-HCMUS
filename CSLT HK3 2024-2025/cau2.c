#include <stdio.h>

int demSoChuSo(int n){
    int len = 0;
    if (n == 0) return 1; // Trường hợp n = 0
    if (n < 0) n = -n;
    while(n > 0){
        len++;
        n /= 10;
    }
    return len;
}

int power(int n, int a){
    int result = 1;
    // Sửa lỗi: Chạy từ 0 đến bé hơn a
    for(int i = 0; i < a; i++){
        result *= n;
    }
    return result;
}

int main(){
    int n;
    printf("Nhap n: ");
    if (scanf("%d", &n) != 1) return 1;

    int original_n = n;
    int len = demSoChuSo(n);
    int r, num;

    for(int i = 0; i < len; i++){
        r = n % 10;
        num = r * power(10, i);
        
        if (i == len - 1) {
            printf("%d", num);
        } else {
            printf("%d + ", num);
        }
        
        n /= 10;
    }
    
    printf("\n");
    return 0;
}