#include <stdio.h>

#define MAX 100

int coDoiXungTam(int m, int n, int a[][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[m - 1 - i][n - 1 - j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int m, n;
    int a[MAX][MAX];

    printf("Nhap so dong m: ");
    if (scanf("%d", &m) != 1 || m <= 0) return 1;
    printf("Nhap so cot n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int ketQua = coDoiXungTam(m, n, a);
    
    if (ketQua == 1) {
        printf("Ket qua: 1 (Ma tran DOI XUNG qua tam)\n");
    } else {
        printf("Ket qua: 0 (Ma tran KHONG DOI XUNG qua tam)\n");
    }

    return 0;
}