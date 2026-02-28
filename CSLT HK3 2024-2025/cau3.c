#include <stdio.h>

int scalerProduct(int a[], int b[], int n){
    int sum = 0;
    int result;
    for(int i = 0; i < n; i++){
        result = a[i] * b[i];
        sum += result;
    }
    return result;
}

int isOrthogonal(int a[], int b[], int n){
    int ketQua = scalerProduct(a, b, n);
    if(ketQua == 0) return 1;
    else return 0;
}

int kiemTraTapHopTrucGiao(int a[][100], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            if(!isOrthogonal(a[i], a[j], n)) return 0;
        }
    }
    return 1;
}

int main(){
    int a[100][100];
    int n, m;
    
    printf("Nhap so luong vector (m): ");
    scanf("%d", &m);
    printf("Nhap do dai moi vector (n): ");
    scanf("%d", &n);

    for(int i = 0; i < m; i++){
        printf("Nhap cac phan tu cho vector thu %d:\n", i + 1);
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    if(kiemTraTapHopTrucGiao(a, m, n)){
        printf("\nDay la mot tap hop truc giao.\n");
    } else {
        printf("\nDay KHONG phai la tap hop truc giao.\n");
    }

    return 0;
}