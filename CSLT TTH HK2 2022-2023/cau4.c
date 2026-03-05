#include <stdio.h>

void loopSTR(const char *str, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; str[j] != '\0'; j++){
            printf("%c", str[j]);
        }
    }
}

int main(){
    char str[1000];
    scanf("%[^\n]", str);
    int n;
    printf("Nhap so lan lap: ");
    scanf("%d", &n);
    loopSTR(str, n);
    return 0;
}