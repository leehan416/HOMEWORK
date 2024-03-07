#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main(void) {
    char input[100];

    // 문자열 입력
    printf("문자열 입력 ");
    fgets(input, sizeof(input), stdin);
    
    // 연산
    reverseString(input);
    
    //결과출력
    printf("역순으로 변환한 문자열은 %s", input);
    return 0;
}

void reverseString(char *str) {
    char reverse[100];
    int index = 0;

    for (int i = strlen(str) - 1; i > -1; i--) {
        if (str[i] == '\n')  // \n 넘기기
            continue;
        else
            reverse[index++] = str[i];
        // printf("%c", reverse[i]);
    }
    for (int i = 0; i < strlen(str); i++)
        *(str + i) = *(reverse + i);
}