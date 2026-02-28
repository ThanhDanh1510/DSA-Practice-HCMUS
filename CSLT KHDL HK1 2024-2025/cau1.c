#include <stdio.h>

int hasFailingGrade(int diemToan, int diemVan, int diemAnh){
    if(diemToan == 0 || diemVan == 0|| diemAnh == 0){
        printf("Bi diem liet. Can co gang");
        return 1;
    }
    return 0;
}
int main(){
    float diemToan, diemVan, diemAnh, diemChuan;
    while(1){
        printf("Nhap diem toan van anh: ");
        scanf("%f %f %f", &diemToan, &diemVan, &diemAnh);
        if(diemToan < 0 || diemVan < 0|| diemAnh < 0){
            printf("Tam biet. Hen gap lai");
            break;
        }
        float sum;
        sum = diemToan + diemAnh + diemVan;
        printf("Tong diem: %.2f\n", sum);
        printf("Nhap diem chuan trung binh: ");
        scanf("%f", &diemChuan);

        while(diemChuan > 0){
            if(sum - diemChuan > 0.5 && !hasFailingGrade(diemToan, diemAnh, diemVan)){
                printf("Co kha nang trung tuyen");
            } else printf("Khong co kha nang trung tuyen");

            printf("Nhap diem chuan trung binh: ");
            scanf("%f", &diemChuan);
        }
    }
    return 0;
}