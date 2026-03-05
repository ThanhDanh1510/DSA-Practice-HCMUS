#include <stdio.h>

int main() {
    char chuoi[1000];
    if (scanf("%999[^\n]", chuoi) != 1) {
        return 0;
    }

    int mangDanhDau[1000] = {0}; 
    int length = 0;

    for (int i = 0; chuoi[i] != '\0'; i++) {
        if (chuoi[i] != ' ' && chuoi[i] != '\t') {
            length++;
        } 

        else {
            if (length > 0) {
                mangDanhDau[length]++;
                length = 0;
            }
        }
    }

    if (length > 0) {
        mangDanhDau[length]++;
    }

    float result = 0;
    float sumTotalWords = 0;
    float sumTotalLetters = 0;

    for (int i = 0; i < 1000; i++) {
        if (mangDanhDau[i] != 0) {
            sumTotalWords += i;
            sumTotalLetters += i * mangDanhDau[i];
        }
    }

    if (sumTotalWords > 0) {
        result = sumTotalLetters / sumTotalWords;
        printf("%f\n", result);
    } else {
        printf("0.000000\n");
    }

    return 0;
}