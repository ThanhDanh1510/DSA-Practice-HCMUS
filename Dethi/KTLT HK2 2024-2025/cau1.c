#include <stdio.h>

int max(int a, int b);
int timMangConTongLonNhat(int mangGoc[], int kichCoMang);

int main(){
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test 1 (Hon hop): %d\n", timMangConTongLonNhat(arr1, n1));
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int timMangConTongLonNhat(int mangGoc[], int n) {
    int max_current = mangGoc[0];
    int max_global = mangGoc[0];
    
    for (int i = 1; i < n; i++) {
        max_current = max(mangGoc[i], max_current + mangGoc[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}