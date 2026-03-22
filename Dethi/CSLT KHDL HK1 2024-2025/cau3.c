#include <stdio.h>

int checkEvenNumber(int num){
    if(num % 2==0) return 0;
    return 1;
}


int main(){
    int mang[24];
    for(int i =0; i < 24; i++){
        scanf("%d", &mang[i]);
    }

    int len = 0;
    int soTapCon;
    int tongSoTapCon = 0;
    int maxLen = -1;
    int startIndex = -1;
    for(int i =0; i < 24; i++){
        if(checkEvenNumber(mang[i])){
            len++;
            if(len > maxLen){
                maxLen = len;
                startIndex = i - maxLen + 1;
            }
        } else{
            soTapCon = len*(len+1)/2;
            tongSoTapCon += soTapCon;
            len = 0;
        }
    }

    soTapCon = len*(len+1)/2;
    printf("%d\n", tongSoTapCon);
    printf("%d\n", maxLen);
    for(int i = startIndex; i < startIndex + maxLen; i++){
        int cot = i % 6;
        int hang = i / 6;
        printf("%d %d\n", hang, cot);
    }
    return 0;
}