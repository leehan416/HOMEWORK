#include <stdio.h>
#include <string.h>
int main(void) {
    char str[100];      // 입력받은 문자열
    char reverse[100];  // 순서를 거꾸로 바꾼 문자열

    // 변수 입력
    printf("문자열 입력 ");
    fgets(str, sizeof(str), stdin);

    
    //결과 출력
    printf("역순으로 변환한 문자열은 ");
    for (int i = strlen(str); i > -1; i --) { // 뒤에서 부터 출력
        if (str[i] == '\n') { // 글자 이외엔 넘기기
            continue;
        }
        printf("%c", str[i]); // 출력
    }
    return 0;
}