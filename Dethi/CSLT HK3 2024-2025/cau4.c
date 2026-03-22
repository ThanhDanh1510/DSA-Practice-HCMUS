#include <stdio.h>

int main(){
    char chuoi[1000];
    scanf("%[^\n]", chuoi);

    int tuMoi = 1;
    int checkDaPrint = 0;

    for(int i =0; chuoi[i] != '\0'; i++){
        if(chuoi[i] != ' ' && chuoi[i] != '\t'){
            if(tuMoi && checkDaPrint) printf(" ");

            if(tuMoi){

                if(chuoi[i] >= 'a' && chuoi[i] <= 'z'){
                    printf("%c", chuoi[i] - 32);
                }
                else printf("%c", chuoi[i]);

                tuMoi = 0;
                checkDaPrint = 1;
            } else{

                if(chuoi[i] >= 'A' && chuoi[i] <= 'Z'){
                    printf("%c", chuoi[i] + 32);
                } else printf("%c", chuoi[i]);
            }
        } else {
            tuMoi = 1;
        }
    }
    printf("\n");
    return 0;
}