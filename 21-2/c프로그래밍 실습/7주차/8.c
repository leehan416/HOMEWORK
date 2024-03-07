#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char code[10][20];
    
    srand(time(0)); // 랜덤 시드 변경

    // 코드 생성 반복문
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) { // 문자열 부분
            code[i][j] = rand() % 26 + 'A';
        }
        code[i][3] = '-'; // 끊어주는 부분
        for (int j = 4; j < 10; j++) { // 숫자 부분
            code[i][j] = rand() % 9 + '1';
        }
        code[i][10] = '\0'; // end word 입력
    }

    // 결과 출력
    printf("10개의 코드가 생성되었습니다.\n");

    for (int i = 0; i < 10; i++)
        printf("Code #%d : %s\n", i + 1, code[i]);
}

