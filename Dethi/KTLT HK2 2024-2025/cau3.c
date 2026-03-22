#include <stdio.h>
#include <string.h>
#include <math.h>

struct Ngay {
    int d, m, y;
};

struct SanPham {
    char maSP[11];
    char tenSP[51];
    int soLuong;
    struct Ngay ngayNhap;
};

long quyDoiNgay(struct Ngay date) {
    return date.y * 365 + date.m * 30 + date.d;
}

void docFile(char *tenFile, struct SanPham ds[], int *n) {
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }

    fscanf(f, "%d", n);

    for (int i = 0; i < *n; i++) {
        fscanf(f, "%s %d %d %d %d", 
               ds[i].maSP, &ds[i].soLuong, 
               &ds[i].ngayNhap.d, &ds[i].ngayNhap.m, &ds[i].ngayNhap.y);
        
        // Đọc bỏ ký tự xuống dòng còn sót lại trước khi đọc tên
        char temp[2]; fgets(temp, 2, f); 

        fgets(ds[i].tenSP, 50, f);
        
        ds[i].tenSP[strcspn(ds[i].tenSP, "\n")] = 0;
    }

    fclose(f);
    printf("Da doc xong du lieu!\n");
}

void lietKeSanPhamCanNhap(struct SanPham ds[], int n) {
    struct Ngay hienTai = {11, 6, 2025}; // Ngày giả định: 11/06/2025
    long tongNgayHienTai = quyDoiNgay(hienTai);
    
    printf("\n=== DANH SACH CAN NHAP HANG GAP ===\n");
    printf("%-10s %-20s %-10s %-15s\n", "Ma SP", "Ten SP", "SL", "Ngay Nhap");

    int count = 0;
    for (int i = 0; i < n; i++) {
        long tongNgayNhap = quyDoiNgay(ds[i].ngayNhap);
        long soNgayTonKho = tongNgayHienTai - tongNgayNhap;

        // Điều kiện: Tồn < 10 VÀ Tồn kho > 90 ngày
        if (ds[i].soLuong < 10 && soNgayTonKho > 90) {
            printf("%-10s %-20s %-10d %02d/%02d/%4d\n", 
                   ds[i].maSP, 
                   ds[i].tenSP, 
                   ds[i].soLuong, 
                   ds[i].ngayNhap.d, ds[i].ngayNhap.m, ds[i].ngayNhap.y);
            count++;
        }
    }

    if (count == 0) {
        printf("Khong co san pham nao can nhap gap.\n");
    }
}