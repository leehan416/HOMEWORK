#include <stdio.h>

int which_first(char *str1, char *str2);

int main(void) {
    char input[2][100];

    // 변수 입력
    printf("첫번째 문자열을 입력하시오. -->");
    scanf("%s", input[0]);
    printf("두번째 문자열을 입력하시오. -->");
    scanf("%s", input[1]);

    // 검사, 출력
    if (which_first(input[0], input[1]) == 1)
        printf("첫번째 문자열이 사전에 먼저 나옵니다.");
    else
        printf("두번째 문자열이 사전에 먼저 나옵니다.");

    return 0;
}


int which_first(char *str1, char *str2) {
    if (*(str1) < *(str2)) // 아스키코드 순 검사
        return 1;
    else
        return 2;
}
