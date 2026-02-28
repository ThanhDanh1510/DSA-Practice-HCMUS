#include <stdio.h>
#include <math.h>

float mean(float series[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += series[i];
    }
    return sum / n;
}

float sd(float series[], int n) {
    float avg = mean(series, n);
    float sum_sq_diff = 0;
    
    for (int i = 0; i < n; i++) {
        sum_sq_diff += pow(series[i] - avg, 2);
    }
    
    return sqrt(sum_sq_diff / n);
}

int main() {
    float data[4][7];
    
    printf("Nhap du lieu doanh thu 4 tuan (moi tuan 7 ngay):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            scanf("%f", &data[i][j]);
        }
    }

    float daily_avgs[7];
    printf("\n* Day so lieu trung binh doanh thu tung ngay trong 4 tuan:\n");
    for (int j = 0; j < 7; j++) {
        float sum_column = 0;
        for (int i = 0; i < 4; i++) {
            sum_column += data[i][j];
        }
        daily_avgs[j] = sum_column / 4.0;
        printf("%.2f  ", daily_avgs[j]);
    }
    printf("\n");

    float m = mean(daily_avgs, 7);
    float s = sd(daily_avgs, 7);

    printf("* Trung binh cua day so lieu tren: %.2f\n", m);
    printf("* Do lech chuan cua day so lieu tren: %.2f\n", s);

    float c = (s / m) * 100;
    
    printf("* Danh gia: ");
    if (c < 10) {
        printf("Doanh thu rat dong deu\n");
    } else if (c >= 10 && c < 20) {
        printf("Doanh thu kha dong deu\n");
    } else if (c >= 20 && c < 30) {
        printf("Doanh thu chenh lech dang ke\n");
    } else {
        printf("Doanh thu chenh lech rat manh\n");
    }

    return 0;
}