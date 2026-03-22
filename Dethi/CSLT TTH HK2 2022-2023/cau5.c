#include <stdio.h>

#define MAX 100

int checkRowsForNegative(int a[MAX][MAX], int m, int n) {
    int i, j, hasNeg;

    for (i = 0; i < m; i++) {
        hasNeg = 0;
        for (j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                hasNeg = 1;
                break;
            }
        }
        if (hasNeg == 0) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int m, n, i, j;
    int a[MAX][MAX];

    printf("Nhap so hang va so cot (toi da %d): ", MAX);
    if (scanf("%d %d", &m, &n) != 2) return 1;

    if (m > MAX || n > MAX) {
        printf("Kich thuoc vuot qua gioi han cho phep.\n");
        return 1;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    if (checkRowsForNegative(a, m, n)) {
        printf("Tat ca cac hang deu co so am\n");
    } else {
        printf("Co hang khong chua so am\n");
    }

    return 0;
}