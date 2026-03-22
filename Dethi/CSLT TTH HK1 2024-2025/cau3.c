#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i =0; i<n;i++){
        scanf("%d", &a[i]);
    }
    int soLeMax = -1;
    int indexMax = -1;
    
    for(int i =0; i < n-k; i++){
        int countSoLe =0;
        for(int j = i; j < k+i; j++){
            if(a[j]%2==1) countSoLe++;
        }
        if(countSoLe > soLeMax){
            soLeMax = countSoLe;
            indexMax = i;
        } 
    }
    for(int i = indexMax; i < indexMax+k; i++){
        printf("%d ", a[i]);
    }
    return 0;
}