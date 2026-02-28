#include <stdio.h>
#include <stdlib.h>

typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

void nhapMaTran(Pixel **maTran, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap R G B cho pixel [%d][%d]: ", i, j);
            scanf("%d %d %d", &maTran[i][j].red, &maTran[i][j].green, &maTran[i][j].blue);
        }
    }
}

void inMaTran(Pixel **maTran, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Pixel [%d][%d]: R=%d, G=%d, B=%d\n", 
                    i, j, maTran[i][j].red, maTran[i][j].green, maTran[i][j].blue);
        }
    }
}

void chuyenAnhSangThangXam(Pixel **maTran, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gray = (int)(0.3 * maTran[i][j].red + 0.59 * maTran[i][j].green + 0.11 * maTran[i][j].blue);

            maTran[i][j].red = gray;
            maTran[i][j].green = gray;
            maTran[i][j].blue = gray;
        }
    }
}
int timPixelSangNhat(Pixel **maTran, int n, int m, int *row_res, int *col_res) {
    int max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = maTran[i][j].red + maTran[i][j].green + maTran[i][j].blue;
            if (sum > max) {
                max = sum;
                *row_res = i;
                *col_res = j;
            }
        }
    }
    return max;
}

int main() {
    int n, m;
    printf("Nhap so hang va cot: ");
    scanf("%d %d", &n, &m);

    Pixel **maTran = (Pixel **)malloc(n * sizeof(Pixel *));
    for (int i = 0; i < n; i++) {
        maTran[i] = (Pixel *)malloc(m * sizeof(Pixel));
    }

    nhapMaTran(maTran, n, m);
    inMaTran(maTran, n, m);
    chuyenAnhSangThangXam(maTran, n, m);

    int r, c;
    int maxBrightness = timPixelSangNhat(maTran, n, m, &r, &c);
    printf("\nPixel sang nhat tai [%d][%d] voi tong gia tri: %d\n", r, c, maxBrightness);

    for (int i = 0; i < n; i++) free(maTran[i]);
    free(maTran);

    return 0;
}