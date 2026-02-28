#include <stdio.h>
#include <math.h>

int kiemTraThuocDuongTron(int xInput, int yInput, int xTam, int yTam, int r){
    long long distSq = (long long)(xInput - xTam)*(xInput - xTam) + (long long)(yInput - yTam)*(yInput - yTam);
    long long rSq = (long long)r * r;
    
    if(distSq < rSq) return 1;
    else return 0;
}

int main(){
    int xTam, yTam, banKinh;
    printf("Nhap toa do tam cua hinh tron va ban kinh (xTam yTam r): ");
    scanf("%d %d %d", &xTam, &yTam, &banKinh);
    
    int xInput, yInput;
    int cntBanPhanThu1 = 0;
    int cntBanPhanThu2 = 0;
    
    printf("Nhap cac diem (x y). Nhap ky tu bat ky de ket thuc:\n");
    
    while(scanf("%d %d", &xInput, &yInput) == 2){
        
        if (xInput == xTam && yInput == yTam) {
            break; 
        }

        if(kiemTraThuocDuongTron(xInput, yInput, xTam, yTam, banKinh)){
            
            if((yInput - yTam) > 0){
                cntBanPhanThu1++;
            } 
            else {
                cntBanPhanThu2++;
            }
        }
    }
    
    printf("So diem thuoc ban phan thu 1 (Upper): %d\n", cntBanPhanThu1);
    printf("So diem thuoc ban phan thu 2 (Lower): %d\n", cntBanPhanThu2);
    
    return 0;
}