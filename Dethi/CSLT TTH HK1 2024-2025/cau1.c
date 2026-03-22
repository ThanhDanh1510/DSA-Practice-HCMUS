#include <stdio.h>
#include <math.h>

float computeDistance(float x, float y){
    return sqrt(x*x + y*y); 
}

int getScore(float x, float y){
    float distance = computeDistance(x, y);
    if(distance < 2) return 10;
    else if (distance < 5)
    {
        return 5;
    }
    else if (distance < 10)
    {
        return 1;
    }
    else return 0;
}

int main(){
    int N, result;
    printf("Nhap so nguoi choi: ");
    scanf("%d", &N);

    int soLuotChoi = 3;
    float x, y;
    int sumMax = 0;
    for(int i = 0; i < N; i++){
        int sum =0;
        for(int j =0; j < soLuotChoi; j++){
            printf("Nhap vi tri phi tieu: ");
            scanf("%f %f", &x, &y);
            result = getScore(x, y);
            printf("Diem so: %d\n", result);
            sum+=result;
        }
        printf("Tong diem: %d", sum);
        if(sum > sumMax) {sumMax = sum;}
    }
    printf("Diem thang cuoc: %d", sumMax);
}