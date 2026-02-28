#include <stdio.h>

int findWrdChr(const char *str, char ch, int *pos){
    int i = 0;
    while(str[i] != '\0'){
        while(str[i] == ' ' || str[i] == '\t'){
            i++;
        }

        if(str[i] == '\0') return 0;

        int len = 0;
        int found =0;


        while(str[i] != ' ' && str[i] != '\t' && str[i] != '\0'){
            if(str[i] == ch) found = 1;
            len++;
            i++;
        }
        if(found){
            *pos = i - len;
            return len;
        }
    }
    *pos = -1;
    return 0;
}

int main(){
    char S[1000];
    scanf("%[^\n]", S);

    getchar();
    char ch;
    scanf("%c", &ch);

    char *originalPtr = S;
    int ptr, length;
    int distance = 0;
    while((length = findWrdChr(originalPtr, ch, &ptr)) > 0){
        int actualPos = distance + ptr;
        printf("%d %d\n", actualPos, length);
        int shift = ptr + length;
        distance += shift;
        originalPtr += shift;
    }

    return 0;
}