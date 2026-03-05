#include <stdio.h>

int main() {
    int n;
    int viTri = 0;
    int tongSoChan = 0;
    int soChanViTriChan = 0;

    printf("Nhap day so (ket thuc bang 0): ");

    while (1) {
        scanf("%d", &n);
        
        if (n == 0) break;

        viTri++; 

        if (n % 2 == 0) {
            tongSoChan++;
            
            if (viTri % 2 == 0) {
                soChanViTriChan++;
            }
        }
    }


    if (soChanViTriChan > 0.5 * tongSoChan){
        printf("Day so dac biet");
    } else printf("Day so khong dac biet");
    
    return 0;
}