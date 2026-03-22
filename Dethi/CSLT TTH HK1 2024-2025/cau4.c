#include <stdio.h>

int findStrChr(const char *str, char ch){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ch){
            return i + 1;
        }
    }
    return -1;
}

int main(){
    char s1[100], s2[100], s3[100];

    printf("Nhap s1: "); scanf("%s", s1);
    printf("Nhap s2: "); scanf("%s", s2);
    printf("Nhap s3: "); scanf("%s", s3);
    
    int len3 = 0;
    while(s3[len3] != '\0'){
        len3++;
    }

    for(int i = 0; s1[i] != '\0'; i++){
        char a = s1[i]; 
        int index = findStrChr(s2, a);
        
        if(index != -1 && index <= len3){
            char c = s3[index - 1];
            s1[i] = c;
            
            printf("%c, %d, %d, %c\n", a, i + 1, index, c);
        }
    }

    printf("%s\n", s1);
    return 0;
}