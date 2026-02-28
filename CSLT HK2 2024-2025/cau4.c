#include <stdio.h>

int kiemtra(char c){
    if((c >= 'a' && c <= 'z') ||
       (c >= 'A' && c <= 'Z') ||
       (c >= '0' && c <= '9')){
        return 1;
       }
    return 0;
}

int main(){
    char S[1000], W[100];
    
    printf("S = ");
    scanf("%[^\n]", S);

    getchar();

    printf("W = ");
    scanf("%s", W);

    int lenS = 0;
    while(S[lenS]!='\0') lenS++;

    int lenW = 0;
    while(W[lenW]!='\0') lenW++;

    int index = -1;
    for(int i = 0; i <= lenS - lenW; i++){
        int found = 1;

        for(int j = 0; j < lenW; j++){
            if(S[i + j] != W[j]){
                found = 0;
                break;
            }
        }

        if(found){

            int checkTruoc = (i == 0 || !kiemtra(S[i-1]));

            int checkSau = (S[i+ lenW] == '\0' || !kiemtra(S[i + lenW]));

            if(checkTruoc && checkSau){
                index = i + 1;
                break;
            }
        }
    }

    if(index == -1){
        printf("Tu %s khong co trong cau S", W);
    } else printf("Vi tri xuat hien cua tu W trong cau S la: %d", index);
    return 0;
}