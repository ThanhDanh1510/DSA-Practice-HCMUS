#include <stdio.h>


void demTanSuat(int grades[], int n) {
    int count[11] = {0};

    for (int i = 0; i < n; i++) {
        int diem = grades[i];
        if (diem >= 0 && diem <= 10) {
            count[diem]++;
        }
    }

    printf("Ket qua dem tan suat:\n");
    for (int i = 0; i <= 10; i++) {
        printf("Diem %d xuat hien %d lan\n", i, count[i]);
    }
}

int main() {
    int n;
    printf("Nhap so luong sinh vien n: ");
    scanf("%d", &n);

    int grades[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap diem cua sinh vien thu %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    demTanSuat(grades, n);

    return 0;
}