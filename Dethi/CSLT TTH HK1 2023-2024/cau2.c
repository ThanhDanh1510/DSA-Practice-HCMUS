#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    float S = sqrt(2);
    for(int i = 2; i<= n; i++){
        S=sqrt(S+2);
    }
    printf("%f", S);
    return 0;
}