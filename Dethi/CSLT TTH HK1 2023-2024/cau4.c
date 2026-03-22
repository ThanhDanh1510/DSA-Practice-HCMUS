#include <stdio.h>

int demDayDongTri(int a[], int n){
    int count = 0;
    int flag = 0;

    for(int i = 0; i < n - 1; i++){
        if(a[i+1] == a[i]){
            if(flag == 0){
                count++;
                flag = 1;
            }
        } 

        else {
            flag = 0;
        }
    }
    return count;
}

int main(){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) return 0; 
    
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    int result = demDayDongTri(a, n);
    printf("%d\n", result);
    
    return 0;
}